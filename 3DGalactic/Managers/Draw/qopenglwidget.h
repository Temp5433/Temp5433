#ifndef QOPENGLWIDGET_H
#define QOPENGLWIDGET_H

#include <QGLWidget>
#include "Models/AbstractModels/emptymodel.h"

class QOpenGlWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit QOpenGlWidget(QWidget *parent = 0);
    ~QOpenGlWidget();

    void addModel(EmptyModel *model);
    void setMode(QString *type);
private:
   GLfloat ratio; // ��������� ������ ���� ������� � ��� ������

   QVector<EmptyModel*> *models;
    QString *mode;
   // ��� ������ ������
   GLfloat xRot1; // ���� �������� ������ ��� X
   GLfloat yRot1; // ���� �������� ������ ��� Y
   GLfloat zRot1; // ���� �������� ������ ��� Z
   GLfloat zTra1; // �������� ���������� �� ��� Z

   // ��� ������ ������
   GLfloat xRot2; // ���� �������� ������ ��� X
   GLfloat yRot2; // ���� �������� ������ ��� Y
   GLfloat zRot2; // ���� �������� ������ ��� Z
   GLfloat zTra2; // �������� ���������� �� ��� Z

   QTimer *timer; // ����������� ������

   //void getVerTexArrays(); // ���������� ������ ������
   //void getIndexArray();   // ���������� ������ �������� ������
   //void genTextures();     // ������� ��������
   //void drawFigure();      // ��������� ������

   void selectFigures(QPoint mp); // ������� ������

protected:
   // ����� ��� ���������� �������������, ��������� � OpenGL:
   void initializeGL();
   // ����� ���������� ��� ��������� �������� ���� �������
   void resizeGL(int nWidth, int nHeight);
   // �����, ����� ������ ������������ ���������� �������
   void paintGL();
   // ����� ��������� ������� ���� ��� ������� ������� ����
   void mousePressEvent(QMouseEvent* pe);

private slots: // �����
   void change(); // ��������� ����� �������� � �������� ����������
   //void changeTex(); // �������� �������� �������
   void stopTmr(); // ���������� ������
   void startTmr(); // ��������� ������

public:
};

#endif // QOPENGLWIDGET_H
