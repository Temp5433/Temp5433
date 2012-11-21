#include "mathematicsmanager.h"
#include <qdebug.h>

MathematicsManager::MathematicsManager(QObject *parent)
{
    this->queAsk = new QQueue<EmptyModel *>();
    this->queAnswer = new QQueue<EmptyModel *>();
    this->timer = new QTimer(this);
    Configuration();
}

void MathematicsManager::Configuration()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    this->timer->start(100);
}

/*class MathematicsManager �� ����� ����������� ��������
  � ����� � ��������� �����.
*/
void MathematicsManager::run()
{
    exec();
}

void MathematicsManager::update()
{
    if(queAsk->size())
    {
        //�����������, ���� ���� ������ �� ���������
        qDebug()<<"MATHEMATICS-Ask: "<<queAsk->first()->metaObject()->className();

        //��� ������ �������, ��� ����� �������� � ������� queAnswer
        //������:
        /*EmptyModel *temp = NULL;
        queAnswer->push_back(temp);*/
    }
}

/*�������� ��������� ������ ����������
  �������� ������� ��� �� ���� ���������.
*/
void MathematicsManager::changeMode(QString *type)
{

}

/*����� ���������� ������, �� ����� ����� ������
  ���� ����� ��� ����������� ����������
  ��������� ��� ��������� ��������
*/
int MathematicsManager::getCountOfModeElement(QString *type)
{

}

/*������ �� ��������� ������
*/
void MathematicsManager::askModel(EmptyModel *model)
{
    this->queAsk->push_back(model);
}

/*��������� �������, ���� �� ��� �����������
  ���� ������ ��� �� �����������, ����� ������� NULL
*/
EmptyModel* MathematicsManager::takeModel()
{
    EmptyModel* temp=NULL;
    if(queAnswer->size())
    {
        temp = queAnswer->first();
        qDebug()<<"MATHEMATICS-take Model: "<<temp->metaObject()->className();
        queAnswer->pop_front();
    }
    return temp;
}
