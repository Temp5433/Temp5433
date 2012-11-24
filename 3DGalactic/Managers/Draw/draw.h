#ifndef DRAW_H
#define DRAW_H

#include <QObject>
#include <qqueue.h>
#include <qtimer.h>
#include <qthread.h>

#include <Models/ModelsLibrary.h>

class Draw : public QThread
{
    Q_OBJECT
public:
    explicit Draw(QObject *parent = 0);

    void addModel(EmptyModel *model);
    void changeMode(QString *type);
private:
    void Configuration();
    void run();

    QQueue<EmptyModel *> *queDraw;
    QTimer *timer;

signals:

public slots:
    void update();
};

#endif // DRAW_H
