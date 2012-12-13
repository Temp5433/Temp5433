#include "filemanager.h"
#include <qdebug.h>
#include <qdir.h>
#include <qtimer.h>
#include <qqueue.h>
#include <qpair.h>

#include "filedata.h"
#include "file3d.h"

QQueue<QPair< QString *, QString *> *> *queAskData;
QQueue<EmptyModel *> *queTakeData;
QQueue<EmptyModel *> *queWriteData;


FileData *data;
File3d *f3d;



FileManager::FileManager(QObject *parent)
{
    qDebug()<<"Create"<<metaObject()->className();

    data = new FileData(this);
    queAskData = new QQueue<QPair<QString *,QString *> *>();
    queTakeData = new QQueue<EmptyModel *>();
    queWriteData = new QQueue<EmptyModel *>();
    timer = new QTimer(this);

    Configuration();
}



void FileManager::Configuration()
{
    QDir *dir = new QDir(QDir::currentPath());

    qDebug()<<"Current Path- "<<dir->currentPath();
    QString *temp=new QString(dir->currentPath());
    data->setPath(*temp);

    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

void FileManager::setPath(QString pathToData)
{
    path = new QString(pathToData);

    data->setPath(pathToData);
}

void FileManager::connectionToMemory(MemoryManager *memory)
{
    data->connectionToMemory(memory);
}

void FileManager::run()
{
    qDebug()<<"run thread: "<< metaObject()->className();
    exec();
}

void FileManager::update()
{
    if(queAskData->size())
    {
        EmptyModel* temp;
        if(data->isFind()) temp = data->getData();
        else temp = data->askData(queAskData->first()->first,queAskData->first()->second);
        if(temp!=NULL || data->isFind()==false)
        {
            queTakeData->push_back(temp);
            qDebug()<<"FILES  READ - find -"<<temp;
            queAskData->pop_front();
        }
    }
    else if(queWriteData->size())
    {
        EmptyModel *model = queWriteData->first();
        bool temp=data->writeData(model);
        qDebug()<<"FILES-write: "<<queWriteData->first()->metaObject()->className()<<" - "<<temp;
        if(temp)queWriteData->pop_front();
    }
}

void FileManager::askData(QString *type, QString *name)
{
    queAskData->push_back(new QPair<QString *, QString *>(type, name));
}

EmptyModel* FileManager::takeData()
{
    EmptyModel* temp=NULL;
    if(queTakeData->size())
    {
        temp = queTakeData->first();
        qDebug()<<"FILES-take data: "<<temp;
        queTakeData->pop_front();
    }
    return temp;
}

void FileManager::writeData(EmptyModel *model)
{
    queWriteData->push_back(model);
}
