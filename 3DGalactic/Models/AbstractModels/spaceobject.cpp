#include "spaceobject.h"
#include <cmath>
#include <qdebug.h>

const GLfloat pi=3.141593, k=pi/180;
const GLuint np=36; // число частей, на которое делится полуокружность
const GLfloat step=pi/np; // шаг изменения углов

SpaceObject::SpaceObject(QObject *parent) :
    PhisicalObject(parent)
{
    this->spline = new Spline();
    this->spline->setRadius(1);
    this->spline->setSpeed(0.01);
    this->spline->setBeginTra(xTra,yTra,zTra);

    radius=0.25f; // радиус сферы
}

void SpaceObject::draw()
{
    if(textureId==0)
    {
        genTextures();
        return;
    }
    spline->move();

    // помещаем матрицу моделирования в стек матриц
    glPushMatrix();
       glTranslatef(spline->getX(), spline->getY(), spline->getZ()); // трансляция
       glScalef(spline->getZ(),spline->getZ(),spline->getZ());
       glRotatef(-spline->getAngleX(), 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
       glRotatef(-spline->getAngleY(), 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
       glRotatef(spline->getAngleZ(), 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
       // выбираем текстуру для наложения:
       glBindTexture(GL_TEXTURE_2D, textureId);
       paintGL(); // нарисовать фигуру
    // извлекаем матрицу моделирования из стека матриц
    glPopMatrix();
}

void SpaceObject::getVerTexArrays()
{

    GLfloat phi, theta; // углы фи и тэта

    // двойной цикл по углам
    for (GLuint i=0; i < 2*np+1; i++)
    {
      phi=i*step; // изменение угла фи

      for (GLuint j=0; j < np+1; j++)
      {
         theta=j*step; // изменение угла тэта

         if (j==0) // вершины "северный полюс"
         {
            if (i<2*np)
            {
               // добавляем в конец вектора:
               VertexArray->push_back(0.0f); // пространственная x-координата вершины
               VertexArray->push_back(0.0f); // пространственная y-координата вершины
               VertexArray->push_back(radius);    // пространственная z-координата вершины

               TextureArray->push_back((phi+step/2)/(2*pi)); // текстурная x-координата вершины
               TextureArray->push_back(1.0f);                // текстурная y-координата вершины
            }
         }
         else
         {
            if (j<np) // вершины между северными и южными полюсами
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
            else // вершины "южный полюс"
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
    // загрузка изображения
    //image->load(":/planets/texture/planets/Earth.jpg"); // загружаем изображение в переменную image1
    //image->load(":/stars/texture/stars/small.jpg"); // загружаем изображение в переменную image1
    //image->load(":/stars/texture/stars/medium.gif"); // загружаем изображение в переменную image1
    // конвертируем изображение в формат для работы с OpenGL:
    *image=QGLWidget::convertToGLFormat(*image);
    // создаём, связываем, загружаем, возвращаем уникальный номер:
    //glBindTexture(GL_TEXTURE_2D,textureId);
    //glTexImage2D(GL_TEXTURE_2D,0,3,(GLsizei)image->width(), (GLsizei)image->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image->bits());
    textureId=this->widget->bindTexture(*image, GL_TEXTURE_2D);
    // далее параметры текстурного объекта
    // при фильтрации игнорируются тексели, выходящие за границу текстуры для s координаты
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // при фильтрации игнорируются тексели, выходящие за границу текстуры для t координаты
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // цвет текселя полностью замещает цвет фрагмента фигуры
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
