#include "spaceobject.h"
#include <cmath>
#include <qdebug.h>

const GLfloat pi=3.141593, k=pi/180;
const GLuint np=36; // ����� ������, �� ������� ������� ��������������
const GLfloat step=pi/np; // ��� ��������� �����

SpaceObject::SpaceObject(QObject *parent) :
    PhisicalObject(parent)
{
    this->spline = new Spline();
    this->spline->setRadius(1);
    this->spline->setSpeed(0.01);
    this->spline->setBeginTra(xTra,yTra,zTra);

    radius=0.25f; // ������ �����
}

void SpaceObject::draw()
{
    if(textureId==0)
    {
        genTextures();
        return;
    }
    spline->move();

    // �������� ������� ������������� � ���� ������
    glPushMatrix();
       glTranslatef(spline->getX(), spline->getY(), spline->getZ()); // ����������
       glScalef(spline->getZ(),spline->getZ(),spline->getZ());
       glRotatef(-spline->getAngleX(), 1.0f, 0.0f, 0.0f); // ������� ������ ��� X
       glRotatef(-spline->getAngleY(), 0.0f, 1.0f, 0.0f); // ������� ������ ��� Y
       glRotatef(spline->getAngleZ(), 0.0f, 0.0f, 1.0f); // ������� ������ ��� Z
       // �������� �������� ��� ���������:
       glBindTexture(GL_TEXTURE_2D, textureId);
       paintGL(); // ���������� ������
    // ��������� ������� ������������� �� ����� ������
    glPopMatrix();
}

void SpaceObject::getVerTexArrays()
{

    GLfloat phi, theta; // ���� �� � ����

    // ������� ���� �� �����
    for (GLuint i=0; i < 2*np+1; i++)
    {
      phi=i*step; // ��������� ���� ��

      for (GLuint j=0; j < np+1; j++)
      {
         theta=j*step; // ��������� ���� ����

         if (j==0) // ������� "�������� �����"
         {
            if (i<2*np)
            {
               // ��������� � ����� �������:
               VertexArray->push_back(0.0f); // ���������������� x-���������� �������
               VertexArray->push_back(0.0f); // ���������������� y-���������� �������
               VertexArray->push_back(radius);    // ���������������� z-���������� �������

               TextureArray->push_back((phi+step/2)/(2*pi)); // ���������� x-���������� �������
               TextureArray->push_back(1.0f);                // ���������� y-���������� �������
            }
         }
         else
         {
            if (j<np) // ������� ����� ��������� � ������ ��������
            {
               if (i<2*np)
               {
                  VertexArray->push_back(radius*sin(theta)*cos(phi));
                  VertexArray->push_back(radius*sin(theta)*sin(phi));
                  VertexArray->push_back(radius*cos(theta));

                  TextureArray->push_back(phi/(2*pi));
               }
               else
               {
                  VertexArray->push_back(radius*sin(theta));
                  VertexArray->push_back(0.0f);
                  VertexArray->push_back(radius*cos(theta));


                  TextureArray->push_back(1.0f);
               }
               TextureArray->push_back((pi-theta)/pi);
            }
            else // ������� "����� �����"
            {
               if (i<2*np)
               {
                  VertexArray->push_back(0.0f);
                  VertexArray->push_back(0.0f);
                  VertexArray->push_back(-radius);

                  TextureArray->push_back((phi+step/2)/(2*pi));
                  TextureArray->push_back(0.0f);
               }
            }
         }
      }
    }
}

void SpaceObject::getIndexArray()
{
    for (GLuint i=0; i < 2*np; i++)
    {
      for (GLuint j=0; j < np; j++)
      {
         if (j==0)
         {
            IndexArray->push_back(i*(np+1));
            IndexArray->push_back(i*(np+1)+1);
            if (i<(2*np-1))
               IndexArray->push_back((i+1)*(np+1)+1);
            else
               IndexArray->push_back((i+1)*(np+1));
         }
         else
         {
            if (j<(np-1))
            {
               if (i<(2*np-1))
               {
                  IndexArray->push_back(i*(np+1)+j);
                  IndexArray->push_back((i+1)*(np+1)+(j+1));
                  IndexArray->push_back((i+1)*(np+1)+j);

                  IndexArray->push_back(i*(np+1)+j);
                  IndexArray->push_back(i*(np+1)+(j+1));
                  IndexArray->push_back((i+1)*(np+1)+(j+1));
               }
               else
               {
                  IndexArray->push_back(i*(np+1)+j);
                  IndexArray->push_back((i+1)*(np+1)+j);
                  IndexArray->push_back((i+1)*(np+1)+(j-1));

                  IndexArray->push_back(i*(np+1)+j);
                  IndexArray->push_back(i*(np+1)+(j+1));
                  IndexArray->push_back((i+1)*(np+1)+j);
               }
            }
            else
            {

               IndexArray->push_back((i+1)*(np+1)-1);
               if (i<(2*np-1))
                  IndexArray->push_back((i+2)*(np+1)-2);
               else
                  IndexArray->push_back((i+2)*(np+1)-3);
               IndexArray->push_back((i+1)*(np+1)-2);
            }
         }
      }
    }
}

void SpaceObject::genTextures()
{
    glGenTextures(1,&textureId);
    if(textureId==0)
    {
        qDebug()<<"OpenGL`s error-"<<glGetError();
        return;
    }
    // �������� �����������
    //image->load(":/planets/texture/planets/Earth.jpg"); // ��������� ����������� � ���������� image1
    //image->load(":/stars/texture/stars/small.jpg"); // ��������� ����������� � ���������� image1
    //image->load(":/stars/texture/stars/medium.gif"); // ��������� ����������� � ���������� image1
    // ������������ ����������� � ������ ��� ������ � OpenGL:
    *image=QGLWidget::convertToGLFormat(*image);
    // ������, ���������, ���������, ���������� ���������� �����:
    //glBindTexture(GL_TEXTURE_2D,textureId);
    //glTexImage2D(GL_TEXTURE_2D,0,3,(GLsizei)image->width(), (GLsizei)image->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image->bits());
    textureId=this->widget->bindTexture(*image, GL_TEXTURE_2D);
    // ����� ��������� ����������� �������
    // ��� ���������� ������������ �������, ��������� �� ������� �������� ��� s ����������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // ��� ���������� ������������ �������, ��������� �� ������� �������� ��� t ����������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // ���� ������� ��������� �������� ���� ��������� ������
    //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void SpaceObject::setBeginTime(GLfloat time)
{
    this->spline->setBeginTime(time);
}

void SpaceObject::setBeginPosition(GLfloat xTra, GLfloat yTra, GLfloat zTra)
{
    this->spline->setBeginTra(xTra, yTra, zTra);
}

void SpaceObject::setRadius(GLfloat radius)
{
    this->spline->setRadius(radius);
}

void SpaceObject::setSize(GLfloat radius)
{
    this->radius = radius;
    this->VertexArray->clear();
    this->IndexArray->clear();
    this->getIndexArray();
    this->getVerTexArrays();
}

void SpaceObject::setSpeed(GLfloat speed)
{
    this->spline->setSpeed(speed);
}
