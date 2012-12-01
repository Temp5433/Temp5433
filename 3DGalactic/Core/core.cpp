#include "core.h"
#include <qdebug.h>

#include "Models/AbstractModels/emptymodel.h"

Core::Core(QObject *parent) :
    QObject(parent)
{
    memories = new MemoryManager(this);
    files = new FileManager(this);
    modes = new ModeManager(this);
    users = new User(this);
    streams = new Streams(this);

    Configuration();
}

//Все методы Configuration созданны для настройки класса.
//Конструкторы используются для выделения предварительного памяти и не более.
void Core::Configuration()
{
    this->modes->connectionToFiles(files);
    this->modes->connectionToMemory(memories);

    this->files->start();
    this->memories->start();
}

//Для остановки потока, нужно его завершить.
void Core::stop()
{
    this->memories->exit();
}

//Тестовый метод
void Core::TEST()
{
    test = new QString("Asteroid");
    QString *temp = new QString("Fog");

    EmptyModel *t = this->memories->takeModel();
    if(t!=NULL)
    {
        if(((QString)t->metaObject()->className())==test)
            this->memories->askModel(temp);
        this->files->writeData(t);
        t = this->files->takeData();
        if(t!=NULL)
        qDebug()<<"READ"<<t->metaObject()->className()<<t->getName()<<t->getTest();
    }
    else this->memories->askModel(test);
    this->files->askData(test,new QString("TEST_EMPTY"));
}
