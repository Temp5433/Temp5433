#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <qthread.h>
#include <QTimer.h>
#include "memoryadder.h"
#include "memorydestroyer.h"
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


    QTimer *timer;

signals:

private slots:
    void update();
};

#endif // MEMORYMANAGER_H
