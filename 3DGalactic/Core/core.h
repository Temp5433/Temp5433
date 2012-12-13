#ifndef CORE_H
#define CORE_H

#include <QObject>

class Core : public QObject
{
    Q_OBJECT
public:
    explicit Core(QObject *parent = 0);
    void stop();

    void TEST();
    QString *test;
private:
    void Configuration();

signals:

public slots:

};

#endif // CORE_H
