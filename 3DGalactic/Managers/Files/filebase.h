#ifndef FILEBASE_H
#define FILEBASE_H

#include <QObject>

class FileBase : public QObject
{
    Q_OBJECT
public:
    explicit FileBase(QObject *parent = 0);

signals:

public slots:

};

#endif // FILEBASE_H
