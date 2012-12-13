#include "spline.h"
#include <cmath>



Spline::Spline(QObject *parent) :
    EmptyModel(parent)
{
    this->time = 0;
}

void Spline::setRadius(GLfloat radius)
{
    this->radius= radius;
}

void Spline::setBeginTra(GLfloat xTra, GLfloat yTra, GLfloat zTra)
{
    this->startX = xTra;
    this->startY = yTra;
    this->startZ = zTra;
}

void Spline::setBeginTime(GLfloat time)
{
    this->time = time;
}

void Spline::setParametersRot(GLfloat xRot, GLfloat yRot, GLfloat zRot)
{
    this->xRot = xRot;
    this->yRot = yRot;
    this->zRot = zRot;
}

void Spline::setSpeed(GLfloat speed)
{
    this->speed = speed;
}

void Spline::move()
{
    time+=speed;
    this->yRot+=speed;
    this->xTra = startX+this->radius*cos(time);
    this->yTra = startY+this->radius*(0.3*sin(time)+0.2*cos(time));
    this->zTra = startZ+1-0.4*this->radius*sin(time);
}

GLfloat Spline::getX()
{
    return this->xTra;
}

GLfloat Spline::getY()
{
    return this->yTra;
}

GLfloat Spline::getZ()
{
    return this->zTra;
}

GLfloat Spline::getAngleZ()
{
    return this->zTra;
}

GLfloat Spline::getAngleY()
{
    return this->yTra;
}

GLfloat Spline::getAngleX()
{
    return this->xTra;
}
