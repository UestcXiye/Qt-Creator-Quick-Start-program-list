#include "mainwindow.h"

#include <QPalette>
#include <QStyleFactory>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setStyle(QStyleFactory::create("windows"));

    QPalette palette1 = ui->pushButton->palette();     //获取pushButton的调色板
    palette1.setColor(QPalette::ButtonText, Qt::red);  //设置按钮文本颜色为红色
    palette1.setColor(QPalette::Button, Qt::green);    //设置按钮背景颜色为绿色
    ui->pushButton->setPalette(palette1);              // pushButton使用修改后的调色板
    ui->spinBox->setDisabled(true);                    //设置spinBox不可用
    QPalette palette2 = ui->spinBox->palette();
    //设置spinBox不可用时的背景颜色为蓝色
    palette2.setColor(QPalette::Disabled, QPalette::Base, Qt::blue);
    ui->spinBox->setPalette(palette2);
}

MainWindow::~MainWindow() { delete ui; }
