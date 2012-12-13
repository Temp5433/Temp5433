#include "modepreparer.h"
#include <qdebug.h>
#include <qtimer.h>
#include <qqueue.h>

#include "Managers/ReMode/remodemanager.h"
#include "Managers/Mathematics/mathematicsmanager.h"

ReModeManager *remode;
MathematicsManager *math;


QQueue<QString *> askQue();


ModePreparer::ModePreparer(QObject *parent)
{
    qDebug()<<"Create"<<metaObject()->className();
    remode = new ReModeManager();
    math = new MathematicsManager();
    timer = new QTimer(this);

    Configuration();
}

void ModePreparer::Configuration()
{
    math->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

void ModePreparer::run()
{
    qDebug()<<"run thread: "<< metaObject()->className();
    exec();
}

void ModePreparer::connectionToMemory(MemoryManager *manager)
{
    remode->connectionToMemory(manager);
}

void ModePreparer::connectionToFiles(FileManager *manager)
{
    remode->connectionToFiles(manager);
}

void ModePreparer::update()
{

}
