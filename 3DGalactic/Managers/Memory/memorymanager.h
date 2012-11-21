#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <QObject>
#include <QTimer.h>
#include <QQueue.h>
#include <qthread.h>

#include "memoryadder.h"
#include "memorydestroyer.h"
#include "Models/AbstractModels/emptymodel.h"

class MemoryManager : public  QThread
{
    Q_OBJECT
public:
    explicit MemoryManager(QObject *parent = 0);

    void askModel(QString *type);
    EmptyModel* takeModel();
    void destroy(EmptyModel* model);
private:
    void Configuration();
    void run();
    MemoryAdder *adder;
    MemoryDestroyer *destroyer;

    QQueue<QString *> *queAskModel;
    QQueue<EmptyModel *> *queTakeModel;
    QQueue<EmptyModel *> *queDestruction;
    QTimer *timer;
signals:

private slots:
    void update();
};

#endif // MEMORYMANAGER_H
