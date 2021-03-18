#ifndef HEADER_H
#define HEADER_H

#endif // HEADER_H
#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QMap>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QVector>

class SearchWord
{
private:
  int max[2];
  QString NameFile[2] = {"C:\\Users\\Public\\война.txt","C:\\Users\\Public\\11.txt"};
  QString Text;
  QString MostOftenWord[2];
  QStringList words[2];
  QMap <QString,int> Data[2];
public:
  SearchWord(){}
  void FillingData();
  void ExcludingShortWords();
  void SearchOftenWords();
  void FileSave();
};

