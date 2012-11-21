#include "filebase.h"

FileBase::FileBase(QString path, QObject *parent) :
    QObject(parent)
{
    this->path = path;
}
