#include "widget.h"

#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QToolTip>

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 保证不按下鼠标按键也能触发鼠标移动事件
    setMouseTracking(true);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    angle = 0;
}

Widget::~Widget() { delete ui; }

void Widget::paintEvent(QPaintEvent*)
{
    angle += 10;
    if (angle == 360)
        angle = 0;
    int side = qMin(width(), height());
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QTransform transform;
    transform.translate(width() / 2, height() / 2);
    transform.scale(side / 300.0, side / 300.0);
    transform.rotate(angle);
    painter.setWorldTransform(transform);
    painter.drawEllipse(-120, -120, 240, 240);
    painter.drawLine(0, 0, 100, 0);
}

void Widget::mouseMoveEvent(QMouseEvent* event)
{
    QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}
