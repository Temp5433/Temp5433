#ifndef FILEBASE_H
#define FILEBASE_H

#include <QObject>

class FileBase : public QObject
{
    Q_OBJECT
public:
    explicit FileBase(QString path, QObject *parent = 0);
private:
    QString path;
signals:

public slots:

};

#endif // FILEBASE_H
