#include "widget.h"

#include <QKeyEvent>
#include <QWheelEvent>

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this);  //为编辑器部件在本窗口上安装事件过滤器
    ui->spinBox->installEventFilter(this);

    QKeyEvent myEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    qApp->sendEvent(ui->spinBox, &myEvent);
}

Widget::~Widget() { delete ui; }

bool Widget::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui->textEdit)  //判断部件
    {
        if (event->type() == QEvent::Wheel)  //判断事件
        {
            //将event强制转换为发生的事件的类型
            QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
            if (wheelEvent->delta() > 0)
                ui->textEdit->zoomIn();
            else
                ui->textEdit->zoomOut();
            return true;  //该事件已经被处理
        }
        else
            return false;
    }
    else if (watched == ui->spinBox)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Space)
            {
                ui->spinBox->setValue(0);
                return true;
            }
            else
                return false;
        }
    }
    else
        return QWidget::eventFilter(watched, event);
}
