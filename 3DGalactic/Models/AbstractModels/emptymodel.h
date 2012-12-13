#ifndef EMPTYMODEL_H
#define EMPTYMODEL_H

#include <QObject>
#include <qgl.h>
#include "Managers/Draw/glext.h"

class EmptyModel : public QObject
{
    Q_OBJECT
public:
    explicit EmptyModel(QObject *parent = 0);
    ~EmptyModel();

    virtual void draw();
    QString getName();
    int getTest();
    void setWidget(QGLWidget *widget);
    void setImage(QString name);

    virtual QDataStream &operator>>(QDataStream &stream);
    virtual QDataStream &operator<<(QDataStream &stream);

protected:

    virtual void getVerTexArrays(); // определить массив вершин
    virtual void getIndexArray();   // определить массив индексов вершин
    virtual void genTextures();     // создать текстуры
    virtual void paintGL();         //перерисовка

    //среда отрисовки
    QGLWidget *widget;

    //угол поворота для фигуры
    GLfloat xRot, yRot, zRot;

    //трансляция фигуры по осям
    GLfloat xTra, yTra, zTra;

    //размеры объекта (в сплайне радиус траектории)
    GLfloat radius;

    //номер текстуры
    GLuint textureId;

    QVector<GLfloat> *VertexArray;  // декларируем массив вершин
    QVector<GLfloat> *TextureArray; // декларируем массив текстурных координат
    QVector<GLuint> *IndexArray;    // декларируем массив индексов вершин

    int test;
    QString *name;

    QImage *image;  //текстура
signals:

public slots:

};

#endif // EMPTYMODEL_H
