#ifndef EMPTYMODEL_H
#define EMPTYMODEL_H

#include <QObject>

class EmptyModel : public QObject
{
    Q_OBJECT
public:
    explicit EmptyModel(QObject *parent = 0);
    void draw();
signals:

public slots:

};

#endif // EMPTYMODEL_H
