#if !defined(_DATEN_H)
#define _DATEN_H

class Daten {
public:
	int gibDaten(int x, int y);
	void setzeDaten(int x, int y, int farbe);
	void initialisiereSpielfeld();
        int gibPunktestand(void);
        void setzePunktestand(int punkte);
        int testeReihen(void);
protected:
	int spielfeld[10][20];
        int derPunktestand;
};

#endif  //_DATEN_H
