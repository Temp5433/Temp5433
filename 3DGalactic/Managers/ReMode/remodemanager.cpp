#include "remodemanager.h"

ReModeManager::ReModeManager(QObject *parent) :
    QObject(parent)
{
    this->model = new ReModeChanger(this);
    this->texture = new ReTextureChanger(this);
}

void ReModeManager::connectionToMemory(MemoryManager *manager)
{
    this->memory = manager;
}
