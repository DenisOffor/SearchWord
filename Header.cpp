#include <Header.h>

void SearchWord::FillingData()
{
  for(int i=0;i<2;i++)
    {
      QFile file(NameFile[i]);
      file.open(QIODevice::ReadOnly);
      QTextStream in(&file);
      if(i==1)
      in.setCodec("UTF-8");
      Text = in.readAll();
      Text = Text.toLower();
      file.close();
      words[i] = Text.split(QRegExp("[\n\r ,.!?]"),  Qt::SkipEmptyParts);
    }
  ExcludingShortWords();
}
void SearchWord::ExcludingShortWords()
{
  for(int i=0;i<2;i++)
    {
      for(int j=0;j<words[i].size();j++)
        {
          if(words[i][j].size()<4)
            {
            words[i].removeAt(j);
            j--;
            }
            if(j==0)
              j=0;
        }
    }
  for(int i=0;i < 2;i++)
      for(int j=0;j<words[i].size();j++)
    Data[i][words[i][j]]++;
    SearchOftenWords();
}
void SearchWord::SearchOftenWords()
{
  for(int i=0;i<2;i++)
    {
      max[i] = 0;
      auto iter = Data[i].begin();
      for(;iter!=Data[i].end();iter++){
          if(iter.value()>max[i]){
              max[i] = iter.value();
              MostOftenWord[i] = iter.key();
            }
        }
    }
  FileSave();
}

void SearchWord::FileSave()
{
  QFile File("C:\\Users\\Public\\word.txt");
  File.open(QIODevice::WriteOnly);
  QTextStream out(&File);
  for(int i=0;i<2;i++){
      out << MostOftenWord[i] << " - " << max[i]<<"\n";
    }
  File.close();
}
