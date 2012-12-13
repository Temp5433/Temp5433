#include "qopenglwidget.h"

#include <QtGui>      // ���������� ������ QtGui
#include <math.h>     // ���������� �������������� ����������
#include "Managers/Draw/glext.h"    // ���������� ������������ ���� glext.h
#include <qvector.h>

GLint viewport[4]; // ����������� ������� ���� ���������

//GLfloat VertexArray[6][3];  // ����������� ������ ������
//GLfloat TextureArray[6][2]; // ����������� ������ ���������� ���������
//GLuint IndexArray[8][3];    // ����������� ������ �������� ������
//GLuint textureID[2];        // ����������� ������ ���������� �������� (id �������)

GLint signs[2]={1, 1}; // ������ ������ +1 ��� -1 (����������� ��� ����������)
bool motionParameters[2]={1, 1}; // ������ ����������, ������������ ��������
int textureParameters[2]={0, 1}; // ������ �������� ������� ���������� ID



// ����������� ������ QOpenGlWidget:
QOpenGlWidget::QOpenGlWidget(QWidget* parent/*= 0*/) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    models = new QVector<EmptyModel*>();
   // ��������� ��������
   xRot1=-90.0f; yRot1=0.0f; zRot1=0.0f; zTra1=0.0f;
   xRot2=-90.0f; yRot2=0.0f; zRot2=0.0f; zTra2=0.0f;

   timer = new QTimer(this); // ������ ������
   // ��������� ������� � �����:
   connect(timer, SIGNAL(timeout()), this, SLOT(change()));
   timer->start(10); // ��������� ������

   // ������������� ������ � ��������:
//   QGLFormat frmt; // ������� ������ �� ���������
//   frmt.setSwapInterval(1); // ���������� ������������� � ������
//   setFormat(frmt); // ���������� ������ � ��������
   this->initializeGL();
}

QOpenGlWidget::~QOpenGlWidget() // ����������
{
    this->timer->stop();
}

void QOpenGlWidget::initializeGL() // �������������
{
   // ���� ��� ������� ������ ����������� - ����� ������ ��� ����
   qglClearColor(Qt::black);
   // ������������� ����� �������� ������� ��������
   glEnable(GL_DEPTH_TEST);
   // ������������� �����, ����� �������� ������ ������� �����������
   glEnable(GL_CULL_FACE);
   // ������������� ����� ��������� �������
   glEnable(GL_TEXTURE_2D);
   // �������� �������������
   glEnable(GL_MULTISAMPLE);

   //getVerTexArrays(); // ���������� ������ ������ � ���������� ���������
   //getIndexArray();   // ���������� ������ �������� ������
   //genTextures();     // ������� ��������

   // ������������ ������ ������
   glEnableClientState(GL_VERTEX_ARRAY);
   // ������������ ������ ���������� ���������
   glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

void QOpenGlWidget::resizeGL(int nWidth, int nHeight) // ���� �������
{
   // ������������� ������� ������������ �������
   glMatrixMode(GL_PROJECTION);
   // ����������� ������������ ������� ��������� �������
   glLoadIdentity();

   // ��������� ������ ���� ������� � ��� ������
   ratio=(GLfloat)nHeight/(GLfloat)nWidth;

   // ������� ����
   if (nWidth>=nHeight)
      // ��������� ��������� ������������� ��������:
      glOrtho(-2.0/ratio, 2.0/ratio, -2.0, 2.0, -10.0, 10.0);
   else
      glOrtho(-2.0, 2.0, -2.0*ratio, 2.0*ratio, -10.0, 10.0);

   // ���� ���������
   glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);

   // ��������� ������� ���� ��������� � viewport
   glGetIntegerv(GL_VIEWPORT, viewport);
}

void QOpenGlWidget::paintGL() // ���������
{
   // ������� ������ ����������� � �������
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // ������������� ������� ������������� �������
   glMatrixMode(GL_MODELVIEW);
   // ��������� ��������� ������� � ������� �������������
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

void QOpenGlWidget::mousePressEvent(QMouseEvent* pe) // ������� ������� ����
{
   // ��� ������� ������������� ������ ���� ���������� mousePosition �����
   QPoint mousePosition = pe->pos(); // ��������� ���������� ��������� ����

   this->selectFigures(mousePosition); // ������� ������
}

void QOpenGlWidget::selectFigures(QPoint mp) // ������� ������
{
   GLuint selectBuffer[4]; // ����� ������ (����� ����������)
   GLint hits; // ������� ������������
   glSelectBuffer(4, selectBuffer); // ������������ ��������� ����� ������

   glMatrixMode(GL_PROJECTION); // ������� �������� ����� ��������
   glPushMatrix(); // ��������� ������� ������� � ���� ������
   glRenderMode(GL_SELECT); // ������� � ����� ������
   glLoadIdentity(); // ��������� ��������� �������

   // ����� ����� ��� ���������� ����
   gluPickMatrix((GLdouble)mp.x(), (GLdouble)(viewport[3]-mp.y()), 1.0, 1.0, viewport);
   // ������� ����
   if (width()>=height())
      // ��������� ��������� ������������� ��������:
      glOrtho(-2.0/ratio, 2.0/ratio, -2.0, 2.0, -10.0, 10.0);
   else
      glOrtho(-2.0, 2.0, -2.0*ratio, 2.0*ratio, -10.0, 10.0);

   glMatrixMode(GL_MODELVIEW); // ��������-������� ������� ����� ��������
   glLoadIdentity();           // ����������� ��������� ������� �������������

   glInitNames(); // ���������������� � ��������� ���� ���
   glPushName(0); // � ���� ��� ���������� �������� 0
   // (����������� ������ ��������� ���� �� ���� �������)

//   glPushMatrix(); // ��������� ������� ������������� � ���� ������
//      glTranslatef(-1.0f/ratio, zTra1, 0.0f); // ����������
//      glRotatef(xRot1, 1.0f, 0.0f, 0.0f); // ������� ������ ��� X
//      glRotatef(yRot1, 0.0f, 1.0f, 0.0f); // ������� ������ ��� Y
//      glRotatef(zRot1, 0.0f, 0.0f, 1.0f); // ������� ������ ��� Z
//      glLoadName(1); // ��������� ��� �� ������� ����� ���
//      drawFigure(); // ���������� ������
//   glPopMatrix(); // ������� ������� ������������� �� ����� ������

//   glPushMatrix(); // ��������� � ���� ������� �������������
//      glTranslatef(1.0f/ratio, zTra2, 0.0f); // ����������
//      glRotatef(xRot2, 1.0f, 0.0f, 0.0f); // ������� ������ ��� X
//      glRotatef(yRot2, 0.0f, 1.0f, 0.0f); // ������� ������ ��� Y
//      glRotatef(zRot2, 0.0f, 0.0f, 1.0f); // ������� ������ ��� Z
//      glLoadName(2); // ��������� ��� �� ������� ����� ���
//      drawFigure(); // ���������� ������
//   glPopMatrix(); // ����� �� ����� ������� �������������

   // glPopName(); // �������� ��� �� ����� ���

   // ����� ���������� � ������� � ����� ���������
   hits=glRenderMode(GL_RENDER);

   if (hits>0) // ���� ���������� � ��� ������
   {
      int figureName=selectBuffer[3]; // ��� ������

      // ��������� ���������� ��������
      if (motionParameters[figureName-1])
         motionParameters[figureName-1]=0;
         // ���� � �������� ���������� �� ����������
      else
         motionParameters[figureName-1]=1;
         // ���� � �������� ���������� ����������
   }

   glMatrixMode(GL_PROJECTION); // ������� �������� ����� ��������
   glPopMatrix(); // ������� ������� �� ����� ������
}

// ���� - ��������� ����� �������� � �������� ����������
void QOpenGlWidget::change()
{



//   if (motionParameters[0]) // ��������� ��� ������ ������
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

//   if (motionParameters[1]) // ��������� ��� ������ ������
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

   updateGL(); // �������� �����������
}

void QOpenGlWidget::stopTmr() // ���� - ���������� ������
{
   timer->stop();
}

void QOpenGlWidget::startTmr() // ���� - ��������� ������
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
