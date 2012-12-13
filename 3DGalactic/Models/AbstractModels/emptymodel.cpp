#include "emptymodel.h"
#include <qdatastream.h>
#include <qvector.h>

EmptyModel::EmptyModel(QObject *parent)
{
    this->name = new QString("TEST_EMPTY");
    this->image = new QImage();
    this->test = 13355;

    this->VertexArray = new QVector<GLfloat>();
    this->TextureArray = new  QVector<GLfloat>();
    this->IndexArray = new QVector<GLuint>();

    this->xTra=yTra=zTra=0;

    this->xRot=yRot=zRot=0;

    this->radius = 0;
}

EmptyModel::~EmptyModel()
{
    delete this->name;
    delete this->image;
    delete this->VertexArray;
    delete this->TextureArray;
    delete this->IndexArray;
}

QString EmptyModel::getName()
{
    return *this->name;
}

int EmptyModel::getTest()
{
    return this->test;
}

void EmptyModel::draw(){}

QDataStream &EmptyModel::operator>>(QDataStream &stream)
{
    stream<<*this->name;

    double temp = this->test;
    stream<<temp;
    return stream;
}

QDataStream &EmptyModel::operator<<(QDataStream &stream)
{
    stream>>*this->name;
    double temp;
    stream.setFloatingPointPrecision(QDataStream::DoublePrecision);
    stream>>temp;
    this->test = temp;
    return stream;
}

void EmptyModel::getVerTexArrays(){}

void EmptyModel::getIndexArray(){}

void EmptyModel::genTextures(){}

void EmptyModel::paintGL(){}

void EmptyModel::setWidget(QGLWidget *widget)
{
    this->widget = widget;
    this->getIndexArray();
    this->getVerTexArrays();
    this->genTextures();
}

void EmptyModel::setImage(QString name)
{
    this->image->load(name);

}
