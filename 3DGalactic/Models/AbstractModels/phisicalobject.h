#ifndef PHISICALOBJECT_H
#define PHISICALOBJECT_H
#define DevideNumber

#include "emptymodel.h"


class PhisicalObject : public EmptyModel
{
    Q_OBJECT
public:
    explicit PhisicalObject(QObject *parent = 0);
    virtual void draw();
    virtual void setBeginPosition(GLfloat xTra, GLfloat yTra, GLfloat zTra);
    virtual void setSize(GLfloat radius);
//    virtual QDataStream &operator>>(QDataStream &stream);
//    virtual QDataStream &operator<<(QDataStream &stream);
protected:

    virtual void getVerTexArrays(); // определить массив вершин
    virtual void getIndexArray();   // определить массив индексов вершин
    virtual void genTextures();     // создать текстуры
    virtual void paintGL();         //перерисовка
signals:

public slots:

};

#endif // PHISICALOBJECT_H
