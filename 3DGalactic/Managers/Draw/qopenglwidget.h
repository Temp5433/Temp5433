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
   GLfloat ratio; // отношение высоты окна виджета к его ширине

   QVector<EmptyModel*> *models;
    QString *mode;
   // для первой фигуры
   GLfloat xRot1; // угол поворота вокруг оси X
   GLfloat yRot1; // угол поворота вокруг оси Y
   GLfloat zRot1; // угол поворота вокруг оси Z
   GLfloat zTra1; // величина трансляции по оси Z

   // для второй фигуры
   GLfloat xRot2; // угол поворота вокруг оси X
   GLfloat yRot2; // угол поворота вокруг оси Y
   GLfloat zRot2; // угол поворота вокруг оси Z
   GLfloat zTra2; // величина трансляции по оси Z

   QTimer *timer; // декларируем таймер

   //void getVerTexArrays(); // определить массив вершин
   //void getIndexArray();   // определить массив индексов вершин
   //void genTextures();     // создать текстуры
   //void drawFigure();      // построить фигуру

   void selectFigures(QPoint mp); // выбрать фигуру

protected:
   // метод для проведения инициализаций, связанных с OpenGL:
   void initializeGL();
   // метод вызывается при изменении размеров окна виджета
   void resizeGL(int nWidth, int nHeight);
   // метод, чтобы заново перерисовать содержимое виджета
   void paintGL();
   // метод обработки события мыши при нажатии клавиши мыши
   void mousePressEvent(QMouseEvent* pe);

private slots: // слоты
   void change(); // изменение углов поворота и величины трансляции
   //void changeTex(); // поменять текстуры местами
   void stopTmr(); // остановить таймер
   void startTmr(); // запустить таймер

public:
};

#endif // QOPENGLWIDGET_H
