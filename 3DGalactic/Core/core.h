#ifndef CORE_H
#define CORE_H

#include <QObject>

#include "Managers/Memory/memorymanager.h"
#include "Managers/Files/filemanager.h"
#include "Managers/Mode/modemanager.h"
#include "Managers/User/user.h"
#include "Managers/Stream/streams.h"

class Core : public QObject
{
    Q_OBJECT
public:
    explicit Core(QObject *parent = 0);
    void stop();

    void TEST();
    QString *test;
private:
    void Configuration();

    MemoryManager *memories;
    FileManager *files;
    ModeManager *modes;
    User *users;
    Streams *streams;
signals:

public slots:

};

#endif // CORE_H
