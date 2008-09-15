#ifndef TEST005_H
#define TEST005_H

#include <QApplication>
#include <QtGui/QWidget>
#include <QLabel>
#include <QImage>
#include <QString>
#include <QTimer>
#include <QKeyEvent>
#include <QErrorMessage>
#include <QInputDialog>
#include "ui_test005.h"




class TdieGUI: public QWidget
{
    Q_OBJECT

public:
	TdieGUI(QWidget *parent = 0);
    ~TdieGUI();
    void randomize(void);
    int random(int range);
    void initialisiereSpielfeld();
    void setzeSegment(int x, int y, int farbe);
    void setzeSegment(int x, int y, int farbe, bool vorschau);
    void loescheSegment(int x, int y);
    void loescheSegment(int x, int y, bool vorschau);
    void gameOver(bool highscore);
    void loescheReihe(int reihe);
    void pause(bool pause);
    void vorschau(int steinTyp);
    void zeigeAnzahlReihen(int anzahlReihen);
    void zeigePunkte(int pPunkte);
    void zeigeLevel(int pLevel);
    void keyPressEvent(QKeyEvent *event);

    //timerfunktionen
    void setTimerStatus(bool status);
    void setTimerInterval(int interval);
    bool getTimerStatus(void);
    int getTimerInterval(void);

    //interface funktionen
    void hidegame(void);
    void showgame(void);
    void hidemenu(void);
    void showmenu(void);



private:
    Ui::test005Class ui;


    //my own stuff
    QLabel *spielfeld[10][20];
    QLabel *vorschaufeld[10][20];
    QPixmap bild[7];
    QTimer *timer;
    int xPositionVorschauBrick[4];
    int yPositionVorschauBrick[4];
    bool timerstatus;
    int timerinterval;

protected:


private slots:
	void fallen(void);
    void start(void);
    void showHighscores(void);
    void showCredits(void);
    void savehighscore(void);

};

#endif // TEST005_H
