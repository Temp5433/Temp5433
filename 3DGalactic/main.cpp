#include <QtGui/QApplication>
#include "frame.h"
#include "Core/core.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frame w;
    w.show();
    //�������� Core ����� �� ���������� :)
    //�� ���������� �� frame.cpp
    return a.exec();
}
