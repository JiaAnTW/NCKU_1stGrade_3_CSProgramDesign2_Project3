#include "record.h"
#include <iostream>
using namespace std;

record::record()
{
    save.resize(6);
    QFile *ReadRecord=new QFile("record.txt");
    if(!ReadRecord->open(QIODevice::ReadOnly)){
        cerr<< "open fail!"<<endl<<qPrintable(ReadRecord->errorString());
    }
    if(!ReadRecord->exists()){
        for(int i=0;i<6;++i)
            save[i]=0;
    }
    else{
        int i=0;
        QString deliver;
        while(!ReadRecord->atEnd()){
            deliver.clear();
            data=ReadRecord->readLine();
            deliver.append(data[0]);
            save[i]=deliver.toInt();
            ++i;
        }
    }
    ReadRecord->close();
    delete ReadRecord;
}

void record::recieveData(int level,int HP,int ult,int score){
    save[0]=(ult==3 && level>4)?1:save[0];
    save[1]=(score==87)?1:save[1];
    save[2]=(score>=100 && level>4)?1:save[2];
    save[3]=(HP<=20 && level>4)?1:save[3];
    save[4]=(score==60 && level>4)?1:save[4];
    save[5]=(level==1)?1:save[5];
    saveData();
}

void record::saveData(){
    QFile *Record=new QFile("record.txt");
    if(!Record->open(QIODevice::WriteOnly)){
        cerr<< "write fail!"<<endl<<qPrintable(Record->errorString());
    }
    QTextStream writer(Record);
        for(int i=0;i<6;++i)
            writer<<QString::number(save.at(i))<<endl;
    }


QVector<int> record::sendData(){
    return save;
}
