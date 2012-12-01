#ifndef FILE3D_H
#define FILE3D_H

#include <QObject>

class File3d : public QObject
{
    Q_OBJECT
public:
    explicit File3d(QString *path, QObject *parent = 0);
private:
    QString *path;

signals:

public slots:

};

#endif // FILE3D_H
