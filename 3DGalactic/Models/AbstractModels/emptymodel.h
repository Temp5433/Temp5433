#ifndef EMPTYMODEL_H
#define EMPTYMODEL_H

#include <QObject>

class EmptyModel : public QObject
{
    Q_OBJECT
public:
    explicit EmptyModel(QObject *parent = 0);
    void draw();
    QString getName();
    int getTest();
    QDataStream &operator>>(QDataStream &stream);
    QDataStream &operator<<(QDataStream &stream);
private:
    int test;
    QString *name;


signals:

public slots:

};

#endif // EMPTYMODEL_H
