#include "qopenglwidget.h"

#include <QtGui>      // подключаем модуль QtGui
#include <math.h>     // подключаем математическую библиотеку
#include "Managers/Draw/glext.h"    // подключаем заголовочный файл glext.h
#include <qvector.h>

GLint viewport[4]; // декларируем матрицу поля просмотра

//GLfloat VertexArray[6][3];  // декларируем массив вершин
//GLfloat TextureArray[6][2]; // декларируем массив текстурных координат
//GLuint IndexArray[8][3];    // декларируем массив индексов вершин
//GLuint textureID[2];        // декларируем массив текстурных объектов (id текстур)

GLint signs[2]={1, 1}; // массив знаков +1 или -1 (понадобятся при трансляции)
bool motionParameters[2]={1, 1}; // массив параметров, определяющих движение
int textureParameters[2]={0, 1}; // массив индексов массива текстурных ID



// конструктор класса QOpenGlWidget:
QOpenGlWidget::QOpenGlWidget(QWidget* parent/*= 0*/) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    models = new QVector<EmptyModel*>();
   // начальные значения
   xRot1=-90.0f; yRot1=0.0f; zRot1=0.0f; zTra1=0.0f;
   xRot2=-90.0f; yRot2=0.0f; zRot2=0.0f; zTra2=0.0f;

   timer = new QTimer(this); // создаём таймер
   // связываем сигналы и слоты:
   connect(timer, SIGNAL(timeout()), this, SLOT(change()));
   timer->start(10); // запускаем таймер

   // синхронизация кадров с дисплеем:
//   QGLFormat frmt; // создать формат по умолчанию
//   frmt.setSwapInterval(1); // установить синхронизацию в формат
//   setFormat(frmt); // установить формат в контекст
   this->initializeGL();
}

QOpenGlWidget::~QOpenGlWidget() // деструктор
{
    this->timer->stop();
}

void QOpenGlWidget::initializeGL() // инициализация
{
   // цвет для очистки буфера изображения - будет просто фон окна
   qglClearColor(Qt::black);
   // устанавливаем режим проверки глубины пикселей
   glEnable(GL_DEPTH_TEST);
   // устанавливаем режим, когда строятся только внешние поверхности
   glEnable(GL_CULL_FACE);
   // установливаем режим двумерных текстур
   glEnable(GL_TEXTURE_2D);
   // включаем мультивыборку
   glEnable(GL_MULTISAMPLE);

   //getVerTexArrays(); // определить массив вершин и текстурных координат
   //getIndexArray();   // определить массив индексов вершин
   //genTextures();     // создать текстуры

   // активизируем массив вершин
   glEnableClientState(GL_VERTEX_ARRAY);
   // активизируем массив текстурных координат
   glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

void QOpenGlWidget::resizeGL(int nWidth, int nHeight) // окно виджета
{
   // устанавливаем текущей проекционную матрицу
   glMatrixMode(GL_PROJECTION);
   // присваиваем проекционной матрице единичную матрицу
   glLoadIdentity();

   // отношение высоты окна виджета к его ширине
   ratio=(GLfloat)nHeight/(GLfloat)nWidth;

   // мировое окно
   if (nWidth>=nHeight)
      // параметры видимости ортогональной проекции:
      glOrtho(-2.0/ratio, 2.0/ratio, -2.0, 2.0, -10.0, 10.0);
   else
      glOrtho(-2.0, 2.0, -2.0*ratio, 2.0*ratio, -10.0, 10.0);

   // поле просмотра
   glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);

   // извлекаем матрицу поля просмотра в viewport
   glGetIntegerv(GL_VIEWPORT, viewport);
}

void QOpenGlWidget::paintGL() // рисование
{
   // очищаем буферы изображения и глубины
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // устанавливаем матрицу моделирования текущей
   glMatrixMode(GL_MODELVIEW);
   // загружаем единичную матрицу в матрицу моделирования
   glLoadIdentity();

    EmptyModel *temp;

   QVector<EmptyModel*>::iterator iterator = models->begin();
   while(iterator!=models->end())
   {
       temp = *iterator;
       temp->draw();
       ++iterator;
   }
}

void QOpenGlWidget::mousePressEvent(QMouseEvent* pe) // нажатие клавиши мыши
{
   // при нажатии пользователем кнопки мыши переменной mousePosition будет
   QPoint mousePosition = pe->pos(); // присвоена координата указателя мыши

   this->selectFigures(mousePosition); // выбрать фигуру
}

void QOpenGlWidget::selectFigures(QPoint mp) // выбрать фигуру
{
   GLuint selectBuffer[4]; // буфер выбора (буфер совпадений)
   GLint hits; // счетчик соответствий
   glSelectBuffer(4, selectBuffer); // использовать указанный буфер выбора

   glMatrixMode(GL_PROJECTION); // матрица проекции стала активной
   glPushMatrix(); // поместить текущую матрицу в стек матриц
   glRenderMode(GL_SELECT); // переход в режим выбора
   glLoadIdentity(); // загрузить единичную матрицу

   // новый объём под указателем мыши
   gluPickMatrix((GLdouble)mp.x(), (GLdouble)(viewport[3]-mp.y()), 1.0, 1.0, viewport);
   // мировое окно
   if (width()>=height())
      // параметры видимости ортогональной проекции:
      glOrtho(-2.0/ratio, 2.0/ratio, -2.0, 2.0, -10.0, 10.0);
   else
      glOrtho(-2.0, 2.0, -2.0*ratio, 2.0*ratio, -10.0, 10.0);

   glMatrixMode(GL_MODELVIEW); // модельно-видовая матрица стала активной
   glLoadIdentity();           // загружается единичная матрица моделирования

   glInitNames(); // инициализируется и очищается стек имён
   glPushName(0); // в стек имён помещается значение 0
   // (обязательно должен храниться хотя бы один элемент)

//   glPushMatrix(); // поместить матрицу моделирования в стек матриц
//      glTranslatef(-1.0f/ratio, zTra1, 0.0f); // трансляция
//      glRotatef(xRot1, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
//      glRotatef(yRot1, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
//      glRotatef(zRot1, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
//      glLoadName(1); // загрузить имя на вершину стека имён
//      drawFigure(); // нарисовать фигуру
//   glPopMatrix(); // извлечь матрицу моделирования из стека матриц

//   glPushMatrix(); // поместить в стек матрицу моделирования
//      glTranslatef(1.0f/ratio, zTra2, 0.0f); // трансляция
//      glRotatef(xRot2, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
//      glRotatef(yRot2, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
//      glRotatef(zRot2, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
//      glLoadName(2); // загрузить имя на вершину стека имён
//      drawFigure(); // нарисовать фигуру
//   glPopMatrix(); // взять из стека матрицу моделирования

   // glPopName(); // вытащить имя из стека имён

   // число совпадений и переход в режим рисования
   hits=glRenderMode(GL_RENDER);

   if (hits>0) // есть совпадания и нет ошибок
   {
      int figureName=selectBuffer[3]; // имя фигуры

      // изменение параметров движения
      if (motionParameters[figureName-1])
         motionParameters[figureName-1]=0;
         // углы и величина трансляции не изменяется
      else
         motionParameters[figureName-1]=1;
         // углы и величина трансляция изменяются
   }

   glMatrixMode(GL_PROJECTION); // матрица проекции стала активной
   glPopMatrix(); // извлечь матрицу из стека матриц
}

// слот - изменение углов поворота и величины трансляции
void QOpenGlWidget::change()
{



//   if (motionParameters[0]) // изменение для первой фигуры
//   {
//      xRot1 -=0.05f;
//      yRot1 -=0.05f;
//      zRot1 +=0.05f;

//      if ((xRot1>360)||(xRot1<-360)) xRot1=0.0f;
//      if ((yRot1>360)||(yRot1<-360)) yRot1=0.0f;
//      if ((zRot1>360)||(zRot1<-360)) zRot1=0.0f;

//      if (abs(zTra1)>0.5f) signs[0] *=-1;
//      zTra1 -=signs[0]*0.005f;
//   }

//   if (motionParameters[1]) // изменение для второй фигуры
//   {
//      xRot2 +=0.05f;
//      yRot2 +=0.05f;
//      zRot2 -=0.05f;

//      if ((xRot2>360)||(xRot2<-360)) xRot2=0.0f;
//      if ((yRot2>360)||(yRot2<-360)) yRot2=0.0f;
//      if ((zRot2>360)||(zRot2<-360)) zRot2=0.0f;

//      if (abs(zTra2)>0.5f) signs[1] *=-1;
//      zTra2 +=signs[1]*0.005f;
//   }

   updateGL(); // обновить изображение
}

void QOpenGlWidget::stopTmr() // слот - остановить таймер
{
   timer->stop();
}

void QOpenGlWidget::startTmr() // слот - запустить таймер
{
   timer->start();
}

void QOpenGlWidget::addModel(EmptyModel *model)
{
    this->models->push_back(model);
    model->setWidget(this);
}

void QOpenGlWidget::setMode(QString *type)
{
    //!!!!!!!
   this->mode = type;
}
