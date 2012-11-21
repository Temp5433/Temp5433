#include "filemanager.h"

FileManager::FileManager(QObject *parent) :
    QObject(parent)
{
}

void FileManager::Configuration(QString path)
{
    this->saver = new FileSave(this);
    this->loader = new FileLoad(this);

    this->path = path;

    /*********/


    this->data = new FileData(path+"data.txt",this);
    this->base = new FileBase(path+"base.txt", this);
    this->f3d  = new File3d(path+"f3d.txt", this);
}
