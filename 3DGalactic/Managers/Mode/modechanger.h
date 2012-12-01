#ifndef MODECHANGER_H
#define MODECHANGER_H

#include <QObject>

#include "Managers/Draw/draw.h"
#include "Managers/Mode/modepreparer.h"
#include "Managers/Memory/memorymanager.h"
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

    void saveLevel();

    Draw *drawManager;
    ModePreparer *preparer;
signals:

public slots:

};

#endif // MODECHANGER_H
