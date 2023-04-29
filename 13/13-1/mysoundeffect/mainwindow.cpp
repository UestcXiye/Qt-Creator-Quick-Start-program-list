#include "mainwindow.h"

#include<QSoundEffect>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile("../mysoundeffect/sound.wav"));
    effect->setVolume(0.25f);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked()
{
    effect->play();
}

void MainWindow::on_pushButton_2_clicked()
{
    effect->stop();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    //setLoopCount()设置声音的播放次数
    effect->setLoopCount(arg1);
}
