#include "widget.h"

#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QDebug>
#include <QFileDialog>

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if (cameras.count() > 0)
    {
        foreach (const QCameraInfo& cameraInfo, cameras)
        {
            // qDebug() << cameraInfo.deviceName();
            qDebug() << cameraInfo.description();
        }

        camera = new QCamera(cameras.at(0));
    }
    viewfinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewfinder);
    viewfinder->resize(600, 350);
    imageCapture = new QCameraImageCapture(camera);
    camera->start();
}

Widget::~Widget() { delete ui; }

void Widget::on_pushButton_clicked()
{
    camera->setCaptureMode(QCamera::CaptureStillImage);
    QString fileName = QFileDialog::getSaveFileName();
    camera->searchAndLock();
    //必须使用绝对路径
    imageCapture->capture(fileName);
    camera->unlock();
}
