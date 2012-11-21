#include "filedata.h"

FileData::FileData(QString path,QObject *parent) :
    QObject(parent)
{
    this->path = path;
}
