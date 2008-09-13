#include "stdlib.h"
#include "time.h"

#include "Steuerung.h"

Steuerung::Steuerung(void) {

}

Steuerung::Steuerung(TdieGUI *parent){

	dieGUI = parent;
	dieGUI->randomize();
	dieDaten = new Daten();
	dieHighscores = new Highscore();
	pause=true;
	gameOver=true;
	level = 1;
}

void Steuerung::ladeHighscores(){
  //dieHighscores->ladeHighscores();
  //dieHighscores->ueberpruefeHighscores();
}

QString Steuerung::gibName(int pPlatz){
  return dieHighscores->gibName(pPlatz);
}

int Steuerung::gibScore(int pPlatz){
  return dieHighscores->gibScore(pPlatz);
}

void Steuerung::speichereHighscore(QString pName){
  //ladeHighscores();
  dieHighscores->sendeScore(dieDaten->gibPunktestand(),pName);
  //dieHighscores->test();
}

int Steuerung::gibSpielstatus(){
  if(gameOver){
    return 0;
  }else if(pause){
    return 1;
  }else{
    return 2;
  }
}

void Steuerung::spielBeenden() {
  gameOver=true;
  pause=true;
  int punkte=dieDaten->gibPunktestand();
  bool highscore=false;
  ladeHighscores();
  for(int i=0; i<10; i++){
    if(punkte > dieHighscores->gibScore(i)){
      highscore = true;
    }
  }
  dieGUI->setTimerStatus(false);
  dieGUI->gameOver(highscore);
}

void Steuerung::tasteGedruecktRechts() {

if(!pause && !gameOver)
 {
  bool kollision = false;
   for(int i=0;i<4;i++){
     if(testePosition(xPositionBrick[i]+1,yPositionBrick[i])) {
        kollision = true;
     }
   }
   if (kollision == false){
      for(int i=0;i<4;i++){
        dieGUI->loescheSegment(xPositionBrick[i],yPositionBrick[i]);
        xPositionBrick[i] = xPositionBrick[i]+1;
      }
      for(int i=0; i<4; i++) {
        dieGUI->setzeSegment(xPositionBrick[i],yPositionBrick[i],typStein);
      }
   }

 }
}

void Steuerung::tasteGedruecktLinks() {

if(!pause && !gameOver)
 {
 bool kollision = false;

   for(int i=0;i<4;i++){
     if(testePosition(xPositionBrick[i]-1,yPositionBrick[i])){
        kollision = true;
     }
   }
   if (kollision == false){
      for(int i=0;i<4;i++){
        dieGUI->loescheSegment(xPositionBrick[i],yPositionBrick[i]);
        xPositionBrick[i] = xPositionBrick[i]-1;
      }
      for(int i=0; i<4; i++) {
        dieGUI->setzeSegment(xPositionBrick[i],yPositionBrick[i],typStein);
      }
   }
 }
}

void Steuerung::tasteGedruecktOben() {
  drehen();
}

void Steuerung::tasteGedruecktPause() {
  if(!gameOver){
    if(pause){
      pause = false;
    }else{
      pause = true;
    }
    dieGUI->pause(pause);
  }
}

void Steuerung::tasteGedruecktUnten() {
   if(!gameOver)
	   fallen();
}

void Steuerung::fallen()
{
  if(!pause &&! gameOver){
	bool kollision = false;
    for(int i=0;i<4;i++){
      if(testePosition(xPositionBrick[i],yPositionBrick[i]+1)){
        kollision = true;
        if(xPositionBrick[i] < -1 && xPositionBrick[i]< 10 && yPositionBrick[i] >= 20){
          spielBeenden();
        }
        if(xPositionBrick[i]>-1 && xPositionBrick[i]< 10 && yPositionBrick[i] >-1 && yPositionBrick[i] < 20){
          if(!gameOver)
            schreibeDaten();
        }
        initialisiereStein(naechsterStein);
      }
    }
    if (kollision == false){
      for(int i=0;i<4;i++){
        dieGUI->loescheSegment(xPositionBrick[i],yPositionBrick[i]);
        yPositionBrick[i]=yPositionBrick[i]+1;
      }
      for(int i=0; i<4; i++){
        dieGUI->setzeSegment(xPositionBrick[i],yPositionBrick[i],typStein);
      }
    }
  }
}

void Steuerung::neuesSpiel() {
  dieDaten->setzePunktestand(0);
  gameOver = false;
  drehungStein = 0;
  reihen = 0;
  pause = false;
  dieDaten->initialisiereSpielfeld();
  dieGUI->initialisiereSpielfeld();
  initialisiereStein(-1);
}

bool Steuerung::testePosition(int x, int y) { //kollision wenn true
  int daten = dieDaten->gibDaten(x,y);
  if (daten == -1 || daten == -2){
    return false;
  }else{
    return true;
  }
}

void Steuerung::drehen() {
  if(!pause && !gameOver)
  {
    bool kollision=false;
    int iFormel;

    if(drehungStein>3)
      drehungStein = 0;

    switch(typStein) {
      case 0:
        if(drehungStein==0 || drehungStein==2){
          for(int i=0; i<3; i++) {
            iFormel = i+(i/2);
            if(!kollision)
              kollision = testePosition(xPositionBrick[2]+2-i-(i/2),yPositionBrick[2]);
          }
          if(!kollision){
            for(int i=0; i<3; i++) {
              iFormel = i+(i/2);
              dieGUI->loescheSegment(xPositionBrick[iFormel],yPositionBrick[iFormel]);
              xPositionBrick[iFormel] = xPositionBrick[2]+2-i-(i/2);
              yPositionBrick[iFormel] = yPositionBrick[2];
              dieGUI->setzeSegment(xPositionBrick[iFormel],yPositionBrick[iFormel],typStein);
            }
          }
        }else if(drehungStein==1 || drehungStein==3){
          for(int i=0; i<3; i++) {
            iFormel = i+(i/2);
            if(!kollision)
              kollision=testePosition(xPositionBrick[2],yPositionBrick[2]-2+i+(i/2));
          }
          if(!kollision){
            for(int i=0; i<3; i++) {
              iFormel = i+(i/2);
              dieGUI->loescheSegment(xPositionBrick[iFormel],yPositionBrick[iFormel]);
              xPositionBrick[iFormel] = xPositionBrick[2];
              yPositionBrick[iFormel] = yPositionBrick[2]-2+i+(i/2);
              dieGUI->setzeSegment(xPositionBrick[iFormel],yPositionBrick[iFormel],typStein);
            }
          }
        }
        break;
      case 1:
        switch(drehungStein) {
          case 0:
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[1]-1;
              xPositionBrick[0] = xPositionBrick[1]-1;
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[1];
              xPositionBrick[2] = xPositionBrick[1]+1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

              dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
              yPositionBrick[3] = yPositionBrick[1];
              xPositionBrick[3] = xPositionBrick[1]-1;
              dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);

            }
            break;
          case 1:
            if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]+1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[1]-1;
              xPositionBrick[0] = xPositionBrick[1];
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[1]-1;
              xPositionBrick[2] = xPositionBrick[1]+1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

              dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
              yPositionBrick[3] = yPositionBrick[1]+1;
              xPositionBrick[3] = xPositionBrick[1];
              dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
            }
            break;
          case 2:
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]+1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[1];
              xPositionBrick[0] = xPositionBrick[1]-1;
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[1];
              xPositionBrick[2] = xPositionBrick[1]+1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

              dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
              yPositionBrick[3] = yPositionBrick[1]+1;
              xPositionBrick[3] = xPositionBrick[1]+1;
              dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
            }
            break;
          case 3:
            if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]+1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]+1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[1]+1;
              xPositionBrick[0] = xPositionBrick[1];
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[1]-1;
              xPositionBrick[2] = xPositionBrick[1];
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

              dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
              yPositionBrick[3] = yPositionBrick[1]+1;
              xPositionBrick[3] = xPositionBrick[1]-1;
              dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
            }
            break;
        }
        break;
      case 2:
        switch(drehungStein) {
          case 0:
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]+1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[1]+1;
              xPositionBrick[0] = xPositionBrick[1]-1;
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[1];
              xPositionBrick[2] = xPositionBrick[1]+1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

              dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
              yPositionBrick[3] = yPositionBrick[1];
              xPositionBrick[3] = xPositionBrick[1]-1;
              dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
            }
            break;
          case 1:
            if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]+1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[1]-1;
              xPositionBrick[0] = xPositionBrick[1];
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[1]-1;
              xPositionBrick[2] = xPositionBrick[1]-1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

              dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
              yPositionBrick[3] = yPositionBrick[1]+1;
              xPositionBrick[3] = xPositionBrick[1];
              dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
            }
            break;
          case 2:
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]-1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[1];
              xPositionBrick[0] = xPositionBrick[1]-1;
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[1];
              xPositionBrick[2] = xPositionBrick[1]+1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

              dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
              yPositionBrick[3] = yPositionBrick[1]-1;
              xPositionBrick[3] = xPositionBrick[1]+1;
              dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
            }
            break;
          case 3:
            if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]+1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]+1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[1]+1;
              xPositionBrick[0] = xPositionBrick[1];
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[1]-1;
              xPositionBrick[2] = xPositionBrick[1];
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

              dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
              yPositionBrick[3] = yPositionBrick[1]+1;
              xPositionBrick[3] = xPositionBrick[1]+1;
              dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
            }
            break;
        }
        break;
      case 4:
        if(drehungStein==0 || drehungStein==2) {
          if(!kollision)
              kollision = testePosition(xPositionBrick[2],yPositionBrick[2]-1);
          if(!kollision)
              kollision = testePosition(xPositionBrick[2]+1,yPositionBrick[2]-1);

          if(!kollision){
            dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
            yPositionBrick[0] = yPositionBrick[2]-1;
            xPositionBrick[0] = xPositionBrick[2];
            dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

            dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
            yPositionBrick[3] = yPositionBrick[2]-1;
            xPositionBrick[3] = xPositionBrick[2]+1;
            dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
          }
        }else if(drehungStein==1 || drehungStein==3) {
          if(!kollision)
              kollision = testePosition(xPositionBrick[1],yPositionBrick[1]-1);
          if(!kollision)
              kollision = testePosition(xPositionBrick[2],yPositionBrick[2]+1);

          if(!kollision){
            dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
            yPositionBrick[0] = yPositionBrick[1]-1;
            xPositionBrick[0] = xPositionBrick[1];
            dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

            dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
            yPositionBrick[3] = yPositionBrick[2]+1;
            xPositionBrick[3] = xPositionBrick[2];
            dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
          }
        }
        break;
      case 5:
        switch(drehungStein){
          case 0:
            if(!kollision)
              kollision = testePosition(xPositionBrick[3],yPositionBrick[3]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[3]+1,yPositionBrick[3]-1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[1],yPositionBrick[1]);
              yPositionBrick[1] = yPositionBrick[3]-1;
              xPositionBrick[1] = xPositionBrick[3];
              dieGUI->setzeSegment(xPositionBrick[1],yPositionBrick[1],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[3]-1;
              xPositionBrick[2] = xPositionBrick[3]+1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);
            }
            break;
          case 1:
            if(!kollision)
              kollision = testePosition(xPositionBrick[3]+1,yPositionBrick[3]);
            if(!kollision)
              kollision = testePosition(xPositionBrick[3]+1,yPositionBrick[3]+1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[3];
              xPositionBrick[0] = xPositionBrick[3]+1;
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[1],yPositionBrick[1]);
              yPositionBrick[1] = yPositionBrick[3]+1;
              xPositionBrick[1] = xPositionBrick[3]+1;
              dieGUI->setzeSegment(xPositionBrick[1],yPositionBrick[1],typStein);
            }
            break;
          case 2:
            if(!kollision)
              kollision = testePosition(xPositionBrick[3],yPositionBrick[3]+1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[3]-1,yPositionBrick[3]+1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[3]+1;
              xPositionBrick[0] = xPositionBrick[3];
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[3]+1;
              xPositionBrick[2] = xPositionBrick[3]-1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);
            }
            break;
          case 3:
            if(!kollision)
              kollision = testePosition(xPositionBrick[3]-1,yPositionBrick[3]-1);
            if(!kollision)
              kollision = testePosition(xPositionBrick[3]-1,yPositionBrick[3]);
            if(!kollision)
              kollision = testePosition(xPositionBrick[3]-1,yPositionBrick[3]+1);

            if(!kollision){
              dieGUI->loescheSegment(xPositionBrick[0],yPositionBrick[0]);
              yPositionBrick[0] = yPositionBrick[3]-1;
              xPositionBrick[0] = xPositionBrick[3]-1;
              dieGUI->setzeSegment(xPositionBrick[0],yPositionBrick[0],typStein);

              dieGUI->loescheSegment(xPositionBrick[1],yPositionBrick[1]);
              yPositionBrick[1] = yPositionBrick[3];
              xPositionBrick[1] = xPositionBrick[3]-1;
              dieGUI->setzeSegment(xPositionBrick[1],yPositionBrick[1],typStein);

              dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
              yPositionBrick[2] = yPositionBrick[3]+1;
              xPositionBrick[2] = xPositionBrick[3]-1;
              dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);
            }
            break;
        }
        break;
      case 6:
        if(drehungStein==0 || drehungStein==2) {
          if(!kollision)
            kollision = testePosition(xPositionBrick[0]-1,yPositionBrick[0]);
          if(!kollision)
            kollision = testePosition(xPositionBrick[1]+1,yPositionBrick[1]);

          if(!kollision){
            dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
            yPositionBrick[2] = yPositionBrick[0];
            xPositionBrick[2] = xPositionBrick[0]-1;
            dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

            dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
            yPositionBrick[3] = yPositionBrick[1];
            xPositionBrick[3] = xPositionBrick[1]+1;
            dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
          }
        }else if(drehungStein==1 || drehungStein==3) {
          if(!kollision)
            kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]);
          if(!kollision)
            kollision = testePosition(xPositionBrick[1]-1,yPositionBrick[1]+1);

          if(!kollision){
            dieGUI->loescheSegment(xPositionBrick[2],yPositionBrick[2]);
            yPositionBrick[2] = yPositionBrick[1];
            xPositionBrick[2] = xPositionBrick[1]-1;
            dieGUI->setzeSegment(xPositionBrick[2],yPositionBrick[2],typStein);

            dieGUI->loescheSegment(xPositionBrick[3],yPositionBrick[3]);
            yPositionBrick[3] = yPositionBrick[1]+1;
            xPositionBrick[3] = xPositionBrick[1]-1;
            dieGUI->setzeSegment(xPositionBrick[3],yPositionBrick[3],typStein);
          }
        }
        break;
    }
    if(!kollision){
      drehungStein++;
    }
  }
}

void Steuerung::initialisiereStein(int typ) {
  //Überprüfe auf volle Reihen:
  int count=0;
  while(dieDaten->testeReihen()!=-1){
    int fund = dieDaten->testeReihen();
    loescheReihe(fund);
    count++;
  }
  dieDaten->setzePunktestand(dieDaten->gibPunktestand()+10*count);
  dieGUI->zeigePunkte(dieDaten->gibPunktestand());

  //Steininitialisierung

  if(typ < 0 || typ > 7)
   typ = dieGUI->random(7);

  typStein = typ;
  //Brick Startpositionen festlegen

  naechsterStein = dieGUI->random(7);
  dieGUI->vorschau(naechsterStein);

  drehungStein = 0;
  switch(typStein) {
    case 0:                                     // #
      for(int i=0; i<4; i++) {                  // #
        xPositionBrick[i] = 4;                  // #
        yPositionBrick[i] = -2+i;               // #
      }
      break;
    case 1:                                     //  #
      for(int i=0; i<4; i++) {                  //  #
        xPositionBrick[i] = 5-(i/3);            // ##
        yPositionBrick[i] = i-1-(i/3);
      }
      break;
    case 2:                                     // #
      for(int i=0; i<4; i++) {                  // #
        xPositionBrick[i] = 4+(i/3);            // ##
        yPositionBrick[i] = i-1-(i/3);
      }
      break;
    case 3:                                     // ##
      for(int i=0; i<4; i++) {                  // ##
        xPositionBrick[i] = 4+(i/2);
        yPositionBrick[i] = i-(i/2)-(2*(i/3));
      }
      break;
    case 4:                                     // #
      for(int i=0; i<4; i++) {                  // ##
        xPositionBrick[i] = 4+(i/2);            //  #
        yPositionBrick[i] = -1+i-(i/2);
      }
      break;
    case 5:                                     // #
      for(int i=0; i<4; i++) {                  // ##
        xPositionBrick[i] = 4+(i/3);            // #
        yPositionBrick[i] = -1+i-(2*(i/3));
      }
      break;
    case 6:                                     //  #
      for(int i=0; i<4; i++) {                  // ##
        xPositionBrick[i] = 5-(i/2);            // #
        yPositionBrick[i] = -1+i-(i/2);
      }
      break;
  }

  //zeigen wir den neuen Stein an!
  for(int i=0; i<4; i++) {
    dieGUI->setzeSegment(xPositionBrick[i],yPositionBrick[i],typStein);
  }
}

void Steuerung::schreibeDaten() {
  bool error=false;
  for(int u=0;u<4;u++){
    if(yPositionBrick[u]<0){
    	error=true;
    }else{
      dieDaten->setzeDaten(xPositionBrick[u],yPositionBrick[u],typStein);
    }
  }

  dieDaten->setzePunktestand(dieDaten->gibPunktestand()+1);
  dieGUI->zeigePunkte(dieDaten->gibPunktestand());
  if(error){
	  spielBeenden();
  }
}

void Steuerung::loescheReihe(int y) {
  int temp;
  for(int i=y; i>=0; i--)
    dieGUI->loescheReihe(i);

  for(int i=y; i>=0; i--) {
    for(int j=0; j<10; j++){
      temp = dieDaten->gibDaten(j,i-1);
      dieDaten->setzeDaten(j,i-1,-1);
      dieDaten->setzeDaten(j,i,temp);
    }
  }

  reihen++;
  dieGUI->zeigeAnzahlReihen(reihen);

  if(reihen%10 == 0 && dieGUI->getTimerInterval() >= 200){
    dieGUI->setTimerStatus(false);
    dieGUI->setTimerInterval(dieGUI->getTimerInterval()-100);
    dieGUI->setTimerStatus(true);
    level++;
    dieGUI->zeigeLevel(level);
  }

  aktualisiereSpielfeld();
}


void Steuerung::aktualisiereSpielfeld(){
  for(int x=0; x<10; x++){
    for(int y=0; y<20; y++){
      dieGUI->setzeSegment(x,y,dieDaten->gibDaten(x,y));
    }
  }
}

void Steuerung::test(){
  /*bool lol = createConnection();
  QSqlQuery query;
  query.exec("insert into person values(101, 'Danny', 'Young')");
*/
}
