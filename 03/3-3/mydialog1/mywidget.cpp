#include "mywidget.h"

#include <QDialog>

#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent), ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    // QDialog dialog(this);
    // dialog.exec();
    QDialog* dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->show();
}

MyWidget::~MyWidget() { delete ui; }
