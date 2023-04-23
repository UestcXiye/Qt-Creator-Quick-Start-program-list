#include "widget.h"

#include <QPushButton>

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    QPushButton* button = new QPushButton(this);
    button->setObjectName("myButton");
    button->setText(tr("关闭"));
    ui->setupUi(this);  //要在定义了部件以后再调用这个函数
}

Widget::~Widget() { delete ui; }

void Widget::on_myButton_clicked() { close(); }
