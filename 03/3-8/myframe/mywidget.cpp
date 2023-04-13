#include "mywidget.h"

#include <QMovie>
#include <QPixmap>

#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent), ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    QFont font;
    font.setFamily("华文行楷");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);

    QString string = tr("标题太长，需要进行省略！");
    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight, 180);
    ui->label->setText(str);

    ui->label->setPixmap(QPixmap("image/logo.png"));

    QMovie* movie = new QMovie("image/donghua.gif");
    ui->label->setMovie(movie);
    movie->start();
}

MyWidget::~MyWidget() { delete ui; }
