#if !defined(_STEUERUNG_H)
#define _STEUERUNG_H

#include "test005.h"
#include "Daten.h"
#include "Highscore.h"


class Steuerung {
public:
        Steuerung(void);
        Steuerung(TdieGUI *parent);
        void tasteGedruecktPause();
	void tasteGedruecktRechts();
	void tasteGedruecktLinks();
	void tasteGedruecktOben();
	void tasteGedruecktUnten();
	void fallen();
	void neuesSpiel();
    void spielBeenden();
    void ladeHighscores();
    QString gibName(int pPlatz);
	int gibScore(int pPlatz);
    void speichereHighscore(QString pName);
    int gibSpielstatus();   // 2 Spiel läuft
                            // 1 Spiel pausiert
                            // 0 Spiel beendet
    void test(void);

protected:
	bool pause;
        //bool beschaeftigt;
        bool gameOver; //true:game over, false: spiel läuft noch
        int typStein;
        int naechsterStein;
        int reihen; //Anzahl gelöschter Reihen
        int level;
        int drehungStein;  //0: nicht gedreht
                           //1: nach rechts
                           //2: auf dem Kopf
                           //3: nach links
	int xPositionBrick[4];
        int yPositionBrick[4];
	bool testePosition(int x, int y);
	void drehen();
	void initialisiereStein(int typ);
	void schreibeDaten();
	void loescheReihe(int y);
        void aktualisiereSpielfeld(void);
    	TdieGUI *dieGUI;
    	Daten *dieDaten;
        Highscore *dieHighscores;
};

#endif  //_STEUERUNG_H
