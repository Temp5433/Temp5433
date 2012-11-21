#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
    //Тестовый Core
    //Был добавлен для тестов.
    //В дальнейшем будет перемещен
    core = new Core();
}

Frame::~Frame()
{
    delete ui;

}

void Frame::on_Frame_destroyed()
{

}

void Frame::on_pushButton_clicked()
{
    core->TEST();
}
