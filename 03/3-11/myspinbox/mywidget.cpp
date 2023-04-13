#include "mywidget.h"

#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent), ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    ui->timeEdit->setTime(QTime::currentTime());
    ui->dateEdit->setDate(QDate::currentDate());
    //设置时间为现在的系统时间
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    //设置时间的显示格式
    ui->dateTimeEdit->setDisplayFormat(tr("yyyy年MM月dd日dddHH时mm分ss秒"));
}

MyWidget::~MyWidget() { delete ui; }
