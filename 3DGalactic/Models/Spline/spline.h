#ifndef SPLINE_H
#define SPLINE_H

#include "Models/AbstractModels/emptymodel.h"

class Spline : public EmptyModel
{
    Q_OBJECT
public:
    explicit Spline(QObject *parent = 0);
    void setRadius(GLfloat radius);
    void setBeginTra(GLfloat xTra, GLfloat yTra, GLfloat zTra);
    void setBeginTime(GLfloat time);
    void setParametersRot(GLfloat xRot, GLfloat yRot, GLfloat zRot);
    void setSpeed(GLfloat speed);
    void move();

    GLfloat getX();
    GLfloat getY();
    GLfloat getZ();
    GLfloat getAngleX();
    GLfloat getAngleY();
    GLfloat getAngleZ();
private:
    GLfloat speed;
    GLfloat time;

    GLfloat startX,startY,startZ;
signals:

public slots:

};

#endif // SPLINE_H
