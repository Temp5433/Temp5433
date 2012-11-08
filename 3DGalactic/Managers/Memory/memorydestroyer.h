#ifndef MEMORYDESTROYER_H
#define MEMORYDESTROYER_H

#include <QObject>

class MemoryDestroyer : public QObject
{
    Q_OBJECT
public:
    explicit MemoryDestroyer(QObject *parent = 0);

signals:

public slots:

};

#endif // MEMORYDESTROYER_H
