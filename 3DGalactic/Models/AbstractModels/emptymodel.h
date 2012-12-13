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

    virtual void getVerTexArrays(); // ���������� ������ ������
    virtual void getIndexArray();   // ���������� ������ �������� ������
    virtual void genTextures();     // ������� ��������
    virtual void paintGL();         //�����������

    //����� ���������
    QGLWidget *widget;

    //���� �������� ��� ������
    GLfloat xRot, yRot, zRot;

    //���������� ������ �� ����
    GLfloat xTra, yTra, zTra;

    //������� ������� (� ������� ������ ����������)
    GLfloat radius;

    //����� ��������
    GLuint textureId;

    QVector<GLfloat> *VertexArray;  // ����������� ������ ������
    QVector<GLfloat> *TextureArray; // ����������� ������ ���������� ���������
    QVector<GLuint> *IndexArray;    // ����������� ������ �������� ������

    int test;
    QString *name;

    QImage *image;  //��������
signals:

public slots:

};

#endif // EMPTYMODEL_H
