#ifndef MODECHANGER_H
#define MODECHANGER_H

#include "Managers/Files/filemanager.h"

class ModeChanger : public QObject
{
    Q_OBJECT
public:
    explicit ModeChanger(QObject *parent = 0);
    void changeMode(QString *type);

    void connectionToMemory(MemoryManager *manager);
    void connectionToFiles(FileManager *manager);
private:
    void Configuration();


signals:

public slots:

};

#endif // MODECHANGER_H
