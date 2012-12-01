#include "filedata.h"
#include "qdir.h"
#include "qdebug.h"

FileData::FileData(QObject *parent) :
    QObject(parent)
{

}

void FileData::Configuration()
{
    QDir *dir = new QDir();
    dir->setPath(this->path);
    if(!dir->exists())
    {
        dir->mkdir(this->path);
        qDebug()<<"FILE:Create directory - "<<this->path<<"-"<<dir->exists();
    }
}

void FileData::setPath(QString path)
{
    this->path = path+"/saver";
    Configuration();
}

QFile* FileData::findFile(QString *type, QString name)
{
    QDir *dir = new QDir();
    QString path = this->path+"/"+*type;
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
    QFile* temp = findFile(type,*name);
    if(!temp->exists()) return NULL;
    temp->open(QIODevice::ReadOnly|QIODevice::Text);
    QDataStream in(temp);
    EmptyModel *model = new EmptyModel();
    *model<<in;
    qDebug()<<"FILES - READ - name is -"<<model->getName();
    temp->close();
    return model;
}

//QString* FileData::readData(QFile *file)
//{
//    QString temp;
//    QDataStream in(file);
//    in >> temp;
//    qDebug()<<"FILE: Read from -"<<file->fileName()<<" data-"<< temp;
//    return &temp;
//}

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
