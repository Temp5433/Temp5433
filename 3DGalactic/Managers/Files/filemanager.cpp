#include "filemanager.h"
#include <qdebug.h>

FileManager::FileManager(QObject *parent)
{
    qDebug()<<"Create"<<this->metaObject()->className();
    this->saver = new FileSave(this);
    this->loader = new FileLoad(this);
}

void FileManager::Configuration(QString path)
{
    this->path = path;

    /*********/

    this->data = new FileData(path+"data.txt",this);
    this->base = new FileBase(path+"base.txt", this);
    this->f3d  = new File3d(path+"f3d.txt", this);
}

void FileManager::run()
{
    qDebug()<<"run thread: "<< this->metaObject()->className();
    exec();
}

