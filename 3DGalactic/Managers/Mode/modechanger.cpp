#include "modechanger.h"

#include "Managers/Draw/draw.h"
#include "Managers/Mode/modepreparer.h"

Draw *drawManager;
ModePreparer *preparer;


ModeChanger::ModeChanger(QObject *parent) :
    QObject(parent)
{
    drawManager = new Draw(this);
    preparer = new ModePreparer(this);

    Configuration();
}

void ModeChanger::Configuration()
{
    //drawManager->start();
    preparer->start();
}

void ModeChanger::connectionToMemory(MemoryManager *manager)
{
    preparer->connectionToMemory(manager);
}

void ModeChanger::connectionToFiles(FileManager *manager)
{
    preparer->connectionToFiles( manager);
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
