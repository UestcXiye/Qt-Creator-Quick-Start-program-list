#include "mylineedit.h"

#include <QDebug>
#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget* parent) : QLineEdit(parent) {}

void MyLineEdit::keyPressEvent(QKeyEvent* event)
{
    qDebug() << tr("MyLineEdit键盘按下事件");
    QLineEdit::keyPressEvent(event);
    event->ignore();
}
