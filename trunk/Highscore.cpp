#include "Highscore.h"

Highscore::Highscore() {
  //scores = new QStringList();
	if(createConnection()){
		//irgend n true fall
	}
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
	QString hash = QString(checksum);
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
    createConnection();
    QString checksumme = berechneChecksumme(pScore,pName);
	QSqlQuery query;

	query.exec("insert into scores values(NULL, '"+pName+"', "+pScore+", '"+checksumme+"')");
	return true;
	/*int count = scores.count();

  int score = 0;
  if(count>0){
    score = leseScore(count-1);
  }
  if(pScore > score){
    while(count>9){
      scores.removeAt(count-1);
      count--;
    }*/

    //scores << QString::number(pScore)+";"+pName+";"+checksumme+";";
    //scores->Add(QString::number(pScore)+";"+pName+";"+QString::number(checksumme)+";");
    //scores->CustomSort(Sortieren);
    //scores.sort();
    //scores >> "system/highscore.kb";
    /*QFile MyFile( "system/highscore.kb" );
    if (MyFile.open (QIODevice::ReadOnly | QIODevice::Text)) {
    	QTextStream stream( &MyFile );
    	for ( QStringList::Iterator it = scores.begin(); it != scores.end(); ++it ) {
			stream << *it << "\n";
    	}
    	MyFile.close();
    }*/
    /*QFile MyFile( "system/highscore.kb" );
    if (MyFile.open (QFile::WriteOnly | QFile::Truncate)) {
    	QTextStream stream( &MyFile );
    	for ( QStringList::Iterator it = scores.begin(); it != scores.end(); ++it ) {
    		stream << *it << "\n";
    	}
    	MyFile.close();
    }*/
    //scores->SaveToFile("system/highscore.kb");
  //}

}

QString Highscore::leseName(int pPlatz) {
  /*QString temp;
  int pos;
  int count = scores.count();
  if(pPlatz<count){
    temp = scores.value(pPlatz);
    pos = temp.indexOf(";",0);
    temp.midRef(pos+1,temp.length());
    pos = temp.indexOf(";",0);
    temp.midRef(0,pos-1);
    return temp;
  }else{
    return "error";
  }*/
    QString result[10];
    int i=0;
    QSqlQuery query("SELECT name FROM scores ORDER BY score DESC LIMIT 10");
    //int fieldNo = query.record().indexOf("country");
    while (query.next()) {
        result[i] += query.value(0).toString();
        i++;
        //doSomething(country);
    }
    if(pPlatz>0 && pPlatz<=i+1){
    	return result[pPlatz-1];
    }else{
    	return "error";
    }
}

int Highscore::leseScore(int pPlatz) {
  /*QString temp;
  int pos;
  int count = scores.count();
  if(pPlatz<count){
    temp = scores.value(pPlatz);
    pos = temp.indexOf(";",0);
    //pos = temp.Pos(";");
    temp.midRef(0,pos-1);
    if(temp!=""){
      return temp.toInt();
    }else{
      return -1;
    }
  }else{
    return -1;
  }*/
    int result[10];
    int i=0;
    QSqlQuery query("SELECT score FROM scores ORDER BY score DESC LIMIT 10");
    //int fieldNo = query.record().indexOf("country");
    while (query.next()) {
        result[i] += query.value(0).toInt();
        i++;
        //doSomething(country);
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
        //doSomething(country);
    }
    if(pPlatz>0 && pPlatz<=i+1){
    	return result[pPlatz-1];
    }else{
    	return "error";
    }
  /*int pos;
  int count = scores.count();
  if(pPlatz<count){
    temp = scores.value(pPlatz);
    pos = temp.indexOf(";",0);
    temp.midRef(pos+1,temp.length());
    pos = temp.indexOf(";",0);

    temp.midRef(pos+1,temp.length());
    pos = temp.indexOf(";",0);
    temp.midRef(0,pos-1);
    if(temp!=""){
      return temp.toInt();
    }else{
      return -1;
    }
  }else{
    return -1;
  }*/
}

void Highscore::ueberpruefeHighscores() {
  /*int count = scores.count();
  for(int i=0; i<count; i++){
    if(!ueberpruefeChecksumme(leseScore(i),leseName(i),leseChecksumme(i))){
      scores.removeAt(i);
      count--;
    }
  }*/
  //scores->SaveToFile("system/highscore.kb");
  /*QFile MyFile( "system/highscore.kb" );
  if (MyFile.open (QFile::WriteOnly | QFile::Truncate)) {
	  QTextStream stream( &MyFile );
	  for ( QStringList::Iterator it = scores.begin(); it != scores.end(); ++it ) {
		  stream << *it << "\n";
	  }
	  MyFile.close();
  }*/

	//TODO: maybe do something
}

void Highscore::ladeHighscores() {
	if(createConnection()){
		//do something stupid?!
	}
  //scores->Clear();
  //if(FileExists("system/highscore.kb")){
    //scores->LoadFromFile("system/highscore.kb");
  //}

	/*QFile data("output.txt");
	         if (data.open(QFile::WriteOnly | QFile::Truncate)) {
	             QTextStream out(&data);
	             out << "Result: " << qSetFieldWidth(10) << left << 3.14 << 2.7;
	             // writes "Result: 3.14      2.7       "
	         }*/
	//typedef QList<QString> StringList;
	//StringList strListe;
	//QStringList zahlenListe;
	/*scores.clear();

	QStringList lines;
		QFile file( "system/highscore.kb" );
	    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text ) ) {
	        QTextStream stream( &file );
	        QString line;
	        while ( !stream.atEnd() ) {
	            line = stream.readLine(); // line of text excluding '\n'
	            lines += line;
	        }
	        file.close();
	    }*/
	/*QFile file("system/highscore.kb");
	     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	         return;

	     QTextStream in(&file);
	     while (!in.atEnd()) {
	         QString line = in.readLine();
	         //process_line(line);
	     }
*/
////ahhh rework this shit
	/*for(int i=0; i<scores.count(); i++){
		scores.append(lines.value(i));
	}*/
}
