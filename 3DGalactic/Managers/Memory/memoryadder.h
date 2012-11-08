#ifndef MEMORYADDER_H
#define MEMORYADDER_H

#include <QObject>

class MemoryAdder : public QObject
{
    Q_OBJECT
public:
    explicit MemoryAdder(QObject *parent = 0);

signals:

public slots:

};

#endif // MEMORYADDER_H
