#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include "phisicalobject.h"
#include "Models/Spline/spline.h"

class SpaceObject : public PhisicalObject
{
    Q_OBJECT
public:
    explicit SpaceObject(QObject *parent = 0);
    virtual void draw();
    void setBeginTime(GLfloat time);
    void setBeginPosition(GLfloat xTra, GLfloat yTra, GLfloat zTra);
    void setSize(GLfloat radius);
    void setRadius(GLfloat radius);
    void setSpeed(GLfloat speed);

//    virtual QDataStream &operator>>(QDataStream &stream);
//    virtual QDataStream &operator<<(QDataStream &stream);
protected:
    Spline *spline;

    virtual void getVerTexArrays(); // определить массив вершин
    virtual void getIndexArray();   // определить массив индексов вершин
    virtual void genTextures();     // создать текстуры
    //virtual void paintGL();         //перерисовка
signals:

public slots:

};

#endif // SPACEOBJECT_H
