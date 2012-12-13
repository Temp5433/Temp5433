#include "filedata.h"
#include "qdir.h"
#include "qdebug.h"

#include <qfile.h>

bool find;
MemoryManager *memory;
QFile  *current;
QString path;


FileData::FileData(QObject *parent) :
    QObject(parent)
{

}

void FileData::Configuration()
{
    QDir *dir = new QDir();
    dir->setPath(path);
    if(!dir->exists())
    {
        dir->mkdir(path);
        qDebug()<<"FILE:Create directory - "<<path<<"-"<<dir->exists();
    }
    find = false;
}

void FileData::setPath(QString path)
{
    path = path+"/saver";
    Configuration();
}

QFile* FileData::findFile(QString *type, QString name)
{
    QDir *dir = new QDir();
    QString path = path+"/"+*type;
    dir->setPath(path);
    name = path + "/" + name+".txt";
    if(!dir->exists())
    {
        dir->mkdir(path);
        qDebug()<<"FILE:Create directory - "<<*type<<"-"<<dir->exists();
    }
    QFile *temp = new QFile(name);
    qDebug()<<"FILE: find file - "<<name<<" - "<<temp->exists();
    return temp;
}

EmptyModel* FileData::askData(QString *type, QString *name)
{
    current = findFile(type,*name);
    if(!current->exists())
    {
        find = false;
        return NULL;
    }
    find = true;

    current->open(QIODevice::ReadOnly|QIODevice::Text);
    memory->askModel(type);

    return getData();
}

EmptyModel* FileData::getData()
{
    EmptyModel *model = memory->takeModel();
    if(model!=NULL)
    {
        QDataStream stream(current);
        *model<<stream;
        qDebug()<<"FILES - READ - name is -"<<model->getName();
        current->close();
        find = false;
    }
    return model;
}

void FileData::connectionToMemory(MemoryManager *memory)
{
    memory = memory;
}

bool FileData::isFind()
{
    return find;
}

bool FileData::writeData(EmptyModel *model)
{
    QString type = (QString) (model->metaObject()->className());
    QString name = (QString) model->getName();
    QFile *file = findFile(&type,name);
    file->open(QIODevice::WriteOnly|QIODevice::Text);
    QDataStream out(file);
    *model>>out;
    qDebug()<<"FILES - WRITE -"<<model;
    file->close();
    return true;
}
