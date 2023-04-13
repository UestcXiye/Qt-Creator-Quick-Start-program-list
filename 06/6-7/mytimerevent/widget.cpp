#include "widget.h"

#include <QDebug>
#include <QTime>
#include <QTimer>

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);  //创建一个新的定时器
    //关联定时器的溢出信号到槽上
    connect(timer, &QTimer::timeout, this, &Widget::timerUpdate);
    timer->start(1000);  //设置溢出时间为1s，并启动定时器

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QTimer::singleShot(10000, this, &Widget::close);
}

Widget::~Widget() { delete ui; }

void Widget::timerUpdate()  //定时器溢出处理
{
    QTime time = QTime::currentTime();      //获取当前时间
    QString text = time.toString("hh:mm");  //转换为字符串
    if ((time.second() % 2) == 0)
    {
        text[2] = ' ';  //每隔1s就将“:”显示为空格
    }
    ui->lcdNumber->display(text);

    int rand = qrand() % 300;  // 产生300以内的正整数
    ui->lcdNumber->move(rand, rand);
}
