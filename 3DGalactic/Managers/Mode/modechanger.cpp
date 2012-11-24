#include "modechanger.h"

ModeChanger::ModeChanger(QObject *parent) :
    QObject(parent)
{
    this->drawManager = new Draw(this);
    this->preparer = new ModePreparer(this);

    this->Configuration();
}

void ModeChanger::Configuration()
{
    this->drawManager->start();
    this->preparer->start();
}

void ModeChanger::connectionToMemory(MemoryManager *manager)
{
    this->preparer->connectionToMemory(manager);
}

void ModeChanger::connectionToFiles(FileManager *manager)
{
    this->files = manager;
}

void ModeChanger::changeMode(QString *type)
{
//    if(type=="1")
//    {

//    }
//    if(type=="1")
//    {

//    }
//    if(type=="1")
//    {

//    }
//    if(type=="1")
//    {

//    }
}
