#include "filemanager.h"
#include <qdebug.h>
#include <qdir.h>
FileManager::FileManager(QObject *parent)
{
    qDebug()<<"Create"<<this->metaObject()->className();
    this->saver = new FileSave(this);
    this->loader = new FileLoad(this);

    this->data = new FileData(this);
    this->queAskData = new QQueue<QPair<QString *,QString *> *>();
    this->queTakeData = new QQueue<EmptyModel *>();
    this->queWriteData = new QQueue<EmptyModel *>();
    this->timer = new QTimer(this);

    Configuration();
}

void FileManager::setPath(QString path)
{
    this->path = &path;
    QString *temp;

    this->data->setPath(path);
    //temp = new QString(*path+(QString)"/f3d");
    //this->f3d  = new File3d(temp, this);
}

void FileManager::Configuration()
{
    QDir *dir = new QDir(QDir::currentPath());

    qDebug()<<"Current Path- "<<dir->currentPath();
    QString *temp=new QString(dir->currentPath());
    this->data->setPath(*temp);

    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

void FileManager::run()
{
    qDebug()<<"run thread: "<< this->metaObject()->className();
    exec();
}

void FileManager::update()
{
    if(queAskData->size())
    {
        EmptyModel* temp;
        temp = this->data->askData(queAskData->first()->first,queAskData->first()->second);
        this->queTakeData->push_back(temp);
        qDebug()<<"FILES  READ - find -"<<temp;
        this->queAskData->pop_front();
    }
    else if(queWriteData->size())
    {
        EmptyModel *model = queWriteData->first();
        bool temp=this->data->writeData(model);
        qDebug()<<"FILES-write: "<<queWriteData->first()->metaObject()->className()<<" - "<<temp;
        if(temp)this->queWriteData->pop_front();
    }
}

void FileManager::askData(QString *type, QString *name)
{
    this->queAskData->push_back(new QPair<QString *, QString *>(type, name));
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
    this->queWriteData->push_back(model);
}
