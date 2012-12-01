#include "file3d.h"

File3d::File3d(QString *path,QObject *parent) :
    QObject(parent)
{
    this->path = path;
}
