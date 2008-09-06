#include "Daten.h"


int Daten::gibDaten(int x,int y) {
  if(x<10 && x>-1 && y<20 && y>=0){
    return (spielfeld[x][y]);
  }else if(y==-1){
    return -1;
  }else{
    return -3;
  }
}

void Daten::setzeDaten(int x, int y, int farbe) {
  if(x<10 && x>-1 && y<20 && y>-1)
    spielfeld[x][y]= farbe;
}

void Daten::initialisiereSpielfeld() {
  for (int x=0;x<10;x++)
    for (int y=0;y<20;y++)
      spielfeld[x][y]=-1;
}

int Daten::gibPunktestand(void) {
  return derPunktestand;
}

void Daten::setzePunktestand(int punkte) {
  derPunktestand = punkte;
}

int Daten::testeReihen(void) {
  int fund=0;
  int y=-1;
  while(fund<1 && y<19){
    fund=1;
    y++;
    for(int i=0; i<10; i++){
      if(spielfeld[i][y]==-1){
        fund=0;
      }
    }
  }
  if(fund==0){
    return -1;
  }else{
    return y;
  }
}
