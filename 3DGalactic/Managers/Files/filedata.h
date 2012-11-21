#ifndef FILEDATA_H
#define FILEDATA_H

#include <QObject>

class FileData : public QObject
{
    Q_OBJECT
public:
    explicit FileData( QString path, QObject *parent = 0);

private:
    QString path;
signals:

public slots:

};

#endif // FILEDATA_H
