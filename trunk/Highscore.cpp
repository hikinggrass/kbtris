#include "Highscore.h"

Highscore::Highscore() {
	if (!createConnection())
	{
		//false fallreturn 1;
	}else{
		createRelationalTables();
	    QSqlRelationalTableModel model;
	    initializeModel(&model);

	    //QTableView *view = createView(QObject::tr("Relational Table Model"), &model);
	    //view->show();
	}

}

void Highscore::initializeModel(QSqlRelationalTableModel *model)
{
    model->setTable("scores");
    model->select();
}

void Highscore::createRelationalTables()
{
    QSqlQuery query;
    query.exec("create table scores(id INTEGER PRIMARY KEY AUTOINCREMENT, name varchar(20), score int, checksum varchar(32))");
}

bool Highscore::sendeScore(int pScore, QString pName) {
  return schreibeScore(pScore,pName);
}

QString Highscore::gibName(int pPlatz) {
  return leseName(pPlatz);
}

int Highscore::gibScore(int pPlatz) {
  return leseScore(pPlatz);
}


QString Highscore::berechneChecksumme(int pScore, QString pName) {
	QString hashstring =pName+QString::number(pScore);
	QCryptographicHash hashMaker(QCryptographicHash::Md5);
	hashMaker.addData(hashstring.toAscii());
	QByteArray checksum = hashMaker.result();
	QString hash = QString(checksum.toHex());
	return hash;
}

bool Highscore::ueberpruefeChecksumme(int pScore, QString pName, QString pChecksumme) {
  if(berechneChecksumme(pScore,pName) == pChecksumme){
    return true;
  }else{
    return false;
  }
}

/*int __fastcall Sortieren(QStringList *list, int Item1, int Item2)
{
  QString temp1,temp2;
  int pos;

  temp1 = list.value(Item1);
  pos = temp1.indexOf(";",0);
  temp1 = temp1.midRef(0,pos-1);

  temp2 = list->Strings[Item2];
  pos = temp2.indexOf(";",0);
  temp2 = temp2.midRef(0,pos-1);

  int t1,t2;

  t1 = temp1.toInt();
  t2 = temp2.toInt();

  if(t1==t2){
    return 0;
  }else if(t1>t2){
    return -1;
  }else{
    return 1;
  }
}*/

bool Highscore::schreibeScore(int pScore, QString pName) {
	//TODO: Scores limitieren?
    QString checksumme = berechneChecksumme(pScore,pName);
	QSqlQuery query;
	query.exec("insert into scores values(NULL, '"+pName+"', "+QString::number(pScore)+", '"+checksumme+"')");
	return true;
}

QString Highscore::leseName(int pPlatz) {
    QString result[10];
    int i=0;
    QSqlQuery query("SELECT name FROM scores ORDER BY score DESC LIMIT 10");
    //int fieldNo = query.record().indexOf("country");
    while (query.next()) {
        result[i] += query.value(0).toString();
        i++;
    }
    if(pPlatz>0 && pPlatz<=i+1){
    	return result[pPlatz-1];
    }else{
    	return "error";
    }
}

int Highscore::leseScore(int pPlatz) {
    int result[10];
    int i=0;
    QSqlQuery query("SELECT score FROM scores ORDER BY score DESC LIMIT 10");
    //int fieldNo = query.record().indexOf("country");
    while (query.next()) {
        result[i] += query.value(0).toInt();
        i++;
    }
    if(pPlatz>0 && pPlatz<=i+1){
    	return result[pPlatz-1];
    }else{
    	return -1;
    }
}

QString Highscore::leseChecksumme(int pPlatz) {
    QString result[10];
    int i=0;
    QSqlQuery query("SELECT checksumme FROM scores ORDER BY score DESC LIMIT 10");
    //int fieldNo = query.record().indexOf("country");
    while (query.next()) {
        result[i] += query.value(0).toString();
        i++;
    }
    if(pPlatz>0 && pPlatz<=i+1){
    	return result[pPlatz-1];
    }else{
    	return "error";
    }
}

void Highscore::ueberpruefeHighscores() {
	//TODO: maybe do something
}

void Highscore::ladeHighscores() {
	//do something stupid?!
}

void Highscore::test(){
}
