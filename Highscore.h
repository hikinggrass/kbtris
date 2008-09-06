#if !defined(_HIGHSCORE_H)
#define _HIGHSCORE_H
#include <QStringList>
#include <QFile>
#include <QTextStream>

#include <QCryptographicHash>
#include "connection.h"
#include <QVariant>

class Highscore {
protected:
	QStringList scores;
	QString berechneChecksumme(int pScore, QString pName);
	bool ueberpruefeChecksumme(int pScore, QString pName, QString pChecksumme);
	bool schreibeScore(int pScore, QString pName);
	QString leseName(int pPlatz);
	int leseScore(int pPlatz);
    QString leseChecksumme(int pPlatz);
public:
        Highscore();
	bool sendeScore(int pScore, QString pName);
	QString gibName(int pPlatz);
	int gibScore(int pPlatz);
        void ueberpruefeHighscores();
        void ladeHighscores();

};

#endif  //_HIGHSCORE_H
