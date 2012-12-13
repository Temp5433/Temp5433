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

    // �������� ������� ������������� � ���� ������
    glPushMatrix();
       glTranslatef(xTra, yTra, zTra); // ����������
       glRotatef(-xRot, 1.0f, 0.0f, 0.0f); // ������� ������ ��� X
       glRotatef(-yRot, 0.0f, 1.0f, 0.0f); // ������� ������ ��� Y
       glRotatef(-zRot, 0.0f, 0.0f, 1.0f); // ������� ������ ��� Z
       // �������� �������� ��� ���������:
       glBindTexture(GL_TEXTURE_2D, textureId);
       paintGL(); // ���������� ������
    // ��������� ������� ������������� �� ����� ������
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
    // 0 �����������
    this->IndexArray->push_back(0); // ������ (�����) 1-�� �������
    this->IndexArray->push_back(1); // ������ (�����) 2-�� �������
    this->IndexArray->push_back(2); // ������ (�����) 3-�� �������

    // 1 �����������
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
    // �������� �����������
    //image->load(":/planets/texture/planets/Earth.jpg"); // ��������� ����������� � ���������� image1
    image->load(":/stars/texture/stars/small.jpg"); // ��������� ����������� � ���������� image1
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

void PhisicalObject::paintGL()
{
    // ���������, ������ ����� ������� ������ � ������� ������
    glVertexPointer(3, GL_FLOAT, 0, VertexArray->begin());
    // ���������, ������ ����� ������� ������ � ������� ���������� ���������
    glTexCoordPointer(2, GL_FLOAT, 0, TextureArray->begin());
    // ��������� ������� ������ � ��������, ������ �����������
    glDrawElements(GL_TRIANGLES, this->IndexArray->size(), GL_UNSIGNED_INT, IndexArray->begin());
    //glPointSize(5.0f); // ������ ����� �������� � ��������
    //glDrawArrays(GL_POINTS, 0, VertexArray->size()/3); // ���������� ������ � ���� �����
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
