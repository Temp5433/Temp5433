#ifndef EMPTYMODELFACTORY_H
#define EMPTYMODELFACTORY_H

#include <QObject>

class EmptyModelFactory : public QObject
{
    Q_OBJECT
public:
    explicit EmptyModelFactory(QObject *parent = 0);

signals:

public slots:

};

#endif // EMPTYMODELFACTORY_H
