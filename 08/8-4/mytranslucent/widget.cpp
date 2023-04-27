#include "widget.h"

#include <QGraphicsDropShadowEffect>
#include <QGraphicsOpacityEffect>
#include <QPainter>

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    //    //设置窗口的不透明度为0.5
    //    setWindowOpacity(0.5);

    //    //实现窗体背景完全透明，但窗口没有了标题栏
    //    setWindowFlags(Qt::FramelessWindowHint);
    //    setAttribute(Qt::WA_TranslucentBackground);

    //创建阴影效果
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
    //设置阴影颜色
    effect->setColor(QColor(100, 100, 100, 100));
    //设置阴影模糊半径
    effect->setBlurRadius(2);
    //设置阴影偏移值
    effect->setOffset(10);
    //标签部件使用阴影效果
    ui->label->setGraphicsEffect(effect);

    //    //创建透明效果
    //    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect;
    //    opacityEffect->setOpacity(0.1);
    //    ui->label->setGraphicsEffect(opacityEffect);
}

Widget::~Widget() { delete ui; }

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.fillRect(rect(), QColor(255, 255, 255, 100));
}
