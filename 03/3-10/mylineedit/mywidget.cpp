#include "mywidget.h"

#include <QCompleter>
#include <QDebug>

#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent), ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //新建验证器，指定范围为100~999
    QValidator* validator = new QIntValidator(100, 999, this);
    //在行编辑器中使用验证器
    ui->lineEdit3->setValidator(validator);

    QStringList wordList;
    wordList << "Qt"
             << "Qt Creator" << tr("你好");
    //新建自动完成器
    QCompleter* completer = new QCompleter(wordList, this);
    //设置大小写不敏感
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit4->setCompleter(completer);
}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::on_lineEdit2_returnPressed()  //回车键按下信号的槽
{
    ui->lineEdit3->setFocus();                 //让lineEdit3获得焦点
    qDebug() << ui->lineEdit2->text();         //输出lineEdit2的内容
    qDebug() << ui->lineEdit2->displayText();  //输出lineEdit2显示的内容
}
