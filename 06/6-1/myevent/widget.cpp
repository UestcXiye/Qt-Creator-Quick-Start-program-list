#include "widget.h"

#include <QDebug>
#include <QKeyEvent>

#include "mylineedit.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    lineEdit = new MyLineEdit(this);
    lineEdit->move(100, 100);
}

Widget::~Widget() { delete ui; }

void Widget::keyPressEvent(QKeyEvent* event) { qDebug() << tr("Widget键盘按下事件"); }
