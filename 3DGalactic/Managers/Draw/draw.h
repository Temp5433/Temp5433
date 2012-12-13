#ifndef DRAW_H
#define DRAW_H

#include "Managers/Memory/memorymanager.h"
#include <qmainwindow.h>
class Draw : public QMainWindow
{
    Q_OBJECT
public:
    explicit Draw(QObject *parent = 0);

    void addModel(EmptyModel *model);
    void changeMode(QString *type);
private:
    void Configuration();
    void Test();


    //QTimer *timer;

signals:

public slots:

};

#endif // DRAW_H
