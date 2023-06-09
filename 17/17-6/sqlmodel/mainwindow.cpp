#include "mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QTableView>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlQueryModel* model = new QSqlQueryModel(this);

    model->setQuery("select * from student");
    model->setHeaderData(0, Qt::Horizontal, tr("学号"));
    model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, tr("课程"));

    QTableView* view = new QTableView(this);
    view->setModel(model);

    setCentralWidget(view);
}

MainWindow::~MainWindow() { delete ui; }
