#include "phisicalobject.h"
#include <QGLWidget>
#include <math.h>
#include "Managers/Draw/glext.h"
#include <qdebug.h>
PhisicalObject::PhisicalObject(QObject *parent) :
        EmptyModel(parent)
{
    this->textureId=0;
}

void PhisicalObject::draw()
{
    if(textureId==0)
    {
        genTextures();
        return;
    }
    //yRot=xRot+=1.0f;

    // помещаем матрицу моделирования в стек матриц
    glPushMatrix();
       glTranslatef(xTra, yTra, zTra); // трансляция
       glRotatef(-xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
       glRotatef(-yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
       glRotatef(-zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
       // выбираем текстуру для наложения:
       glBindTexture(GL_TEXTURE_2D, textureId);
       paintGL(); // нарисовать фигуру
    // извлекаем матрицу моделирования из стека матриц
    glPopMatrix();

}

void PhisicalObject::getVerTexArrays()
{
    this->VertexArray->push_back(0.0f - radius/2);
    this->VertexArray->push_back(0.0f - radius/2);
    this->VertexArray->push_back(0.0f);

    this->TextureArray->push_back(0.0f);
    this->TextureArray->push_back(0.0f);

    this->VertexArray->push_back(0.0f + radius/2);
    this->VertexArray->push_back(0.0f - radius/2);
    this->VertexArray->push_back(0.0f);

    this->TextureArray->push_back(0.0f+1);
    this->TextureArray->push_back(0.0f);

    this->VertexArray->push_back(0.0f + radius/2);
    this->VertexArray->push_back(0.0f + radius/2);
    this->VertexArray->push_back(0.0f);

    this->TextureArray->push_back(0.0f+1);
    this->TextureArray->push_back(0.0f+1);

    this->VertexArray->push_back(0.0f - radius/2);
    this->VertexArray->push_back(0.0f + radius/2);
    this->VertexArray->push_back(0.0f);

    this->TextureArray->push_back(0.0f);
    this->TextureArray->push_back(0.0f+1);
}

void PhisicalObject::getIndexArray()
{
    // 0 треугольник
    this->IndexArray->push_back(0); // индекс (номер) 1-ой вершины
    this->IndexArray->push_back(1); // индекс (номер) 2-ой вершины
    this->IndexArray->push_back(2); // индекс (номер) 3-ей вершины

    // 1 треугольник
    this->IndexArray->push_back(3);
    this->IndexArray->push_back(0);
    this->IndexArray->push_back(2);
}

void PhisicalObject::genTextures()
{
    glGenTextures(1,&textureId);
    if(textureId==0)
    {
        qDebug()<<"OpenGL`s error-"<<glGetError();
        return;
    }
    // загрузка изображения
    //image->load(":/planets/texture/planets/Earth.jpg"); // загружаем изображение в переменную image1
    image->load(":/stars/texture/stars/small.jpg"); // загружаем изображение в переменную image1
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

void PhisicalObject::paintGL()
{
    // указываем, откуда нужно извлечь данные о массиве вершин
    glVertexPointer(3, GL_FLOAT, 0, VertexArray->begin());
    // указываем, откуда нужно извлечь данные о массиве текстурных координат
    glTexCoordPointer(2, GL_FLOAT, 0, TextureArray->begin());
    // используя массивы вершин и индексов, строим поверхности
    glDrawElements(GL_TRIANGLES, this->IndexArray->size(), GL_UNSIGNED_INT, IndexArray->begin());
    //glPointSize(5.0f); // размер точки примерно в пикселях
    //glDrawArrays(GL_POINTS, 0, VertexArray->size()/3); // изобразить массив в виде точек
}

void PhisicalObject::setBeginPosition(GLfloat xTra, GLfloat yTra, GLfloat zTra)
{
    this->xTra = xTra;
    this->yTra = yTra;
    this->zTra = zTra;
}

void PhisicalObject::setSize(GLfloat radius)
{
    this->radius = radius;
    this->VertexArray->clear();
    this->IndexArray->clear();
    this->getIndexArray();
    this->getVerTexArrays();
}
