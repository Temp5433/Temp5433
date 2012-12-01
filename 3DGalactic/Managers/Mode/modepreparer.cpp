#include "modepreparer.h"
#include <qdebug.h>

ModePreparer::ModePreparer(QObject *parent)
{
    qDebug()<<"Create"<<this->metaObject()->className();
    this->remode = new ReModeManager();
    this->math = new MathematicsManager();
    this->timer = new QTimer(this);

    this->Configuration();
}

void ModePreparer::Configuration()
{
    this->math->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

void ModePreparer::run()
{
    qDebug()<<"run thread: "<< this->metaObject()->className();
    exec();
}

void ModePreparer::connectionToMemory(MemoryManager *manager)
{
    this->remode->connectionToMemory(manager);
}

void ModePreparer::connectionToFiles(FileManager *manager)
{
    this->remode->connectionToFiles(manager);
}

void ModePreparer::update()
{

}
