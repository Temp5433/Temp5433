#include <QtGui/QApplication>
#include "frame.h"
#include "Core/core.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Core core;
    return a.exec();
}
