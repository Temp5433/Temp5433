#ifndef MODECHANGER_H
#define MODECHANGER_H

#include <QObject>

class ModeChanger : public QObject
{
    Q_OBJECT
public:
    explicit ModeChanger(QObject *parent = 0);

signals:

public slots:

};

#endif // MODECHANGER_H
