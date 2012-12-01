#include "emptymodel.h"

EmptyModel::EmptyModel(QObject *parent) :
    QObject(parent)
{
    this->name = new QString("TEST_EMPTY");
    this->test = 13355;
}

QString EmptyModel::getName()
{
    return *this->name;
}

int EmptyModel::getTest()
{
    return this->test;
}

QDataStream &EmptyModel::operator>>(QDataStream &stream)
{
    stream<<*this->name;
    QString temp = (QString)this->test;
    stream<<temp;
    return stream;
}

QDataStream &EmptyModel::operator<<(QDataStream &stream)
{
    stream>>*this->name;
    QString temp;
    stream>>temp;
    this->test = temp.toInt();
    return stream;
}
