#include "sender.h"

#include <QtNetwork>

#include "ui_sender.h"

Sender::Sender(QWidget* parent) : QDialog(parent), ui(new Ui::Sender)
{
    ui->setupUi(this);
    sender = new QUdpSocket(this);
}

Sender::~Sender() { delete ui; }

void Sender::on_pushButton_clicked()
{
    QByteArray datagram = "hello world!";
    sender->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 45454);
}
