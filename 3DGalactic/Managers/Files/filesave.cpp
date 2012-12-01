#include "filesave.h"

FileSave::FileSave(QObject *parent) :
    QObject(parent)
{

}

void FileSave::Configuration()
{

}

void FileSave::setPath(QString *path)
{
    this->path=path;
}

void FileSave::writeData(QString *data)
{

}
