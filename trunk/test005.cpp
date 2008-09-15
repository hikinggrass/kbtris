#include "test005.h"
#include "Steuerung.h"

#include "main.cpp"
    Steuerung *dieSteuerung;

TdieGUI::TdieGUI(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	  grabKeyboard();
    QObject::connect(ui.btnSpielstarten, SIGNAL(clicked(bool)), this, SLOT( start() ));
    QObject::connect(ui.btnHighscores, SIGNAL(clicked(bool)), this, SLOT( showHighscores() ));
    QObject::connect(ui.btnCredits, SIGNAL(clicked(bool)), this, SLOT( showCredits() ));
    QObject::connect(ui.btnBeenden, SIGNAL(clicked(bool)), this, SLOT( close() ));
    QObject::connect(ui.btnSaveHighscore, SIGNAL(clicked(bool)), this, SLOT( savehighscore() ));
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(fallen()));

	dieSteuerung = new Steuerung(this);
	QPixmap background("system/gfx/background.jpg");
	ui.background->setPixmap(background);
	QPixmap menubg("system/gfx/menu_bg_all.jpg");
	ui.menubg->setPixmap(menubg);
	QPixmap highscore("system/gfx/highscore.jpg");
	ui.highscore->setPixmap(highscore);
	ui.highscore->setHidden(true);
	ui.edtName->setHidden(true);
	ui.btnSaveHighscore->setHidden(true);
	QString bildpfad[7];
	bildpfad[0] = "system/gfx/brick_25x25_hellblau.jpg";
	bildpfad[1] = "system/gfx/brick_25x25_blau.jpg";
	bildpfad[2] = "system/gfx/brick_25x25_orange.jpg";
	bildpfad[3] = "system/gfx/brick_25x25_gelb.jpg";
    bildpfad[4] = "system/gfx/brick_25x25_gruen.jpg";
	bildpfad[5] = "system/gfx/brick_25x25_lila.jpg";
	bildpfad[6] = "system/gfx/brick_25x25_rot.jpg";

	for(int i=0; i<7; i++){
		bild[i].load(bildpfad[i]);
	}

	QLabel *label2 = new QLabel(this);
	label2->setGeometry(50,0,50,50);
	label2->setText(QString::number( random(7) ));

	for(int x=0; x<10; x++) {
	    for(int y=0; y<20; y++) {
	      spielfeld[x][y] = new QLabel(this);
	      spielfeld[x][y]->setGeometry(10+x*25,y*25,25,25);
	      //testcode um zu zeigen das das Image Feld aufgebaut wird
	      spielfeld[x][y]->setPixmap(bild[random(7)]);
	     }
	}

	for(int x=0; x<2; x++) {
	    for(int y=0; y<4; y++) {
	      vorschaufeld[x][y] = new QLabel(this);
	      vorschaufeld[x][y]->setGeometry(286+x*25,50+y*25,25,25);
	      //testcode um zu zeigen das das Image Feld aufgebaut wird
	      vorschaufeld[x][y]->setPixmap(bild[random(7)]);
	    }
	  }

	hidegame();
	//start();

}

TdieGUI::~TdieGUI()
{

}

void TdieGUI::hidegame(void){
	for(int x=0; x<10; x++) {
		for(int y=0; y<20; y++) {
			spielfeld[x][y]->setHidden(true);
		}
	}
	for(int x=0; x<2; x++) {
		for(int y=0; y<4; y++) {
		    vorschaufeld[x][y]->setHidden(true);
		}
	}

	ui.lblLevel->setHidden(true);
	ui.lblReihen->setHidden(true);
	ui.lblScore->setHidden(true);
	ui.menubg->setHidden(false);

}

void TdieGUI::showgame(void){
	for(int x=0; x<10; x++) {
		for(int y=0; y<20; y++) {
			spielfeld[x][y]->setHidden(false);
		}
	}
	for(int x=0; x<2; x++) {
		for(int y=0; y<4; y++) {
		    vorschaufeld[x][y]->setHidden(false);
		}
	}

	ui.lblLevel->setHidden(false);
	ui.lblReihen->setHidden(false);
	ui.lblScore->setHidden(false);

	ui.btnSpielstarten->setHidden(true);
	ui.btnBeenden->setHidden(true);
	ui.btnCredits->setHidden(true);
	ui.btnHighscores->setHidden(true);

	ui.menubg->setHidden(true);

}

void TdieGUI::hidemenu(void){
	ui.btnSpielstarten->setHidden(true);
	ui.btnBeenden->setHidden(true);
	ui.btnCredits->setHidden(true);
	ui.btnHighscores->setHidden(true);
}
void TdieGUI::showmenu(void){
	ui.btnSpielstarten->setHidden(false);
	ui.btnBeenden->setHidden(false);
	ui.btnCredits->setHidden(false);
	ui.btnHighscores->setHidden(false);
}
void TdieGUI::showHighscores(void){

}
void TdieGUI::showCredits(void){

}




void TdieGUI::keyPressEvent(QKeyEvent *event)
{
   switch (event->key())
   {
      case Qt::Key_Enter:
      case Qt::Key_Return:
      case Qt::Key_Left:
    	  dieSteuerung->tasteGedruecktLinks();
    	  break;
      case Qt::Key_Up:
    	  dieSteuerung->tasteGedruecktOben();
    	  break;
      case Qt::Key_Right:
    	  dieSteuerung->tasteGedruecktRechts();
    	  break;
      case Qt::Key_Down:
    	  dieSteuerung->tasteGedruecktUnten();
    	  break;
   }
}

void TdieGUI::start(void){
	showgame();
	dieSteuerung->neuesSpiel();
	timer->start(1000);
}



void TdieGUI::randomize(void){
	srand( time(NULL) );
}
int TdieGUI::random(int range){
	int j = (rand()%range);
	return j;
}

void TdieGUI::initialisiereSpielfeld(){
  for(int x=0; x<10; x++){
    for(int y=0; y<20; y++){
      loescheSegment(x,y);
    }
  }
}

void TdieGUI::fallen(void){
	dieSteuerung->fallen();
}

void TdieGUI::setzeSegment(int x, int y, int farbe) {
  setzeSegment(x,y,farbe,false);
}
void TdieGUI::setzeSegment(int x, int y, int farbe, bool vorschau) {
  if(farbe >= 0 && farbe < 7) {
    if(vorschau){
      if( (x >= 0 && x < 2) && (y >= 0 && y < 4) ) {
        vorschaufeld[x][y]->setPixmap(bild[farbe]);
      }
    }else{
      if( (x >= 0 && x < 10) && (y >= 0 && y < 20) ) {
        spielfeld[x][y]->setPixmap(bild[farbe]);
      }
    }
  }
}
void TdieGUI::loescheSegment(int x, int y) {
  loescheSegment(x,y,false);
}
void TdieGUI::loescheSegment(int x, int y, bool vorschau) {
  if(vorschau){
    if( (x >= 0 && x < 2) && (y >= 0 && y < 4) ) {
      //vorschaufeld[x][y]->Picture->Bitmap->ReleaseHandle();
      vorschaufeld[x][y]->setPixmap(NULL);
    }
  }else{
    if( (x >= 0 && x < 10) && (y >= 0 && y < 20) ) {
      spielfeld[x][y]->setPixmap(NULL);
    }
  }
}

void TdieGUI::gameOver(bool highscore) {
    setTimerStatus(false);
	timer->stop();
	releaseKeyboard();
	//hier eigenen dialog implementieren
	for(int x=0; x<10; x++) {
	    for(int y=0; y<20; y++) {
		    spielfeld[x][y]->setPixmap(NULL);
		}
	}
	ui.highscore->setHidden(false);
	ui.edtName->setHidden(false);
	ui.btnSaveHighscore->setHidden(false);
}

void TdieGUI::savehighscore(void){
  grabKeyboard();
  dieSteuerung->speichereHighscore(ui.edtName->toPlainText());
  ui.highscore->setHidden(true);
  ui.edtName->setHidden(true);
  ui.btnSaveHighscore->setHidden(true);
  hidegame();
  showmenu();
}

void TdieGUI::loescheReihe(int reihe) {
  for(int x = 0; x<10; x++)
    loescheSegment(x,reihe);
}

void TdieGUI::pause(bool pause){
  //pnlPause->Visible = pause;
}

void TdieGUI::vorschau(int steinTyp){
switch(steinTyp) {
    case 0:                                     // #
      for(int i=0; i<4; i++) {                  // #
        xPositionVorschauBrick[i] = 0;          // #
        yPositionVorschauBrick[i] = i;          // #
      }
      break;
    case 1:                                     //  #
      for(int i=0; i<4; i++) {                  //  #
        xPositionVorschauBrick[i] = 1-(i/3);    // ##
        yPositionVorschauBrick[i] = 1+i-(i/3);
      }
      break;
    case 2:                                     // #
      for(int i=0; i<4; i++) {                  // #
        xPositionVorschauBrick[i] = (i/3);      // ##
        yPositionVorschauBrick[i] = 1+i-(i/3);
      }
      break;
    case 3:                                     // ##
      for(int i=0; i<4; i++) {                  // ##
        xPositionVorschauBrick[i] = (i/2);
        yPositionVorschauBrick[i] = 1+i-(i/2)-(2*(i/3));
      }
      break;
    case 4:                                     // #
      for(int i=0; i<4; i++) {                  // ##
        xPositionVorschauBrick[i] = (i/2);      //  #
        yPositionVorschauBrick[i] = 1+i-(i/2);
      }
      break;
    case 5:                                     // #
      for(int i=0; i<4; i++) {                  // ##
        xPositionVorschauBrick[i] = (i/3);      // #
        yPositionVorschauBrick[i] = 1+i-(2*(i/3));
      }
      break;
    case 6:                                     //  #
      for(int i=0; i<4; i++) {                  // ##
        xPositionVorschauBrick[i] = 1-(i/2);    // #
        yPositionVorschauBrick[i] = 1+i-(i/2);
      }
      break;
  }

  for(int x=0; x<2; x++) {
    for(int y=0; y<4; y++) {
      loescheSegment(x,y,true);
    }
  }

  for(int i=0; i<4; i++) {
    setzeSegment(xPositionVorschauBrick[i],yPositionVorschauBrick[i],steinTyp,true);
  }
}

void TdieGUI::zeigeAnzahlReihen(int anzahlReihen){
  ui.lblReihen->setText(QString::number(anzahlReihen));
}

void TdieGUI::zeigePunkte(int pPunkte){
  ui.lblScore->setText(QString::number(pPunkte));
}

void TdieGUI::zeigeLevel(int pLevel){
  ui.lblLevel->setText(QString::number(pLevel));
}

void TdieGUI::setTimerStatus(bool status){
	if(status){
		timer->start(timerinterval);
		timerstatus = true;
	}else{
		timer->stop();
		timerstatus = false;
	}
}
void TdieGUI::setTimerInterval(int interval){
  timerinterval = interval;
  timer->stop();
  timer->start(timerinterval);
}

bool TdieGUI::getTimerStatus(void){
  return timerstatus;
}
int TdieGUI::getTimerInterval(void){
  return timerinterval;
}

/*void TdieGUI::test(void){
	dieSteuerung->test();
}*/
