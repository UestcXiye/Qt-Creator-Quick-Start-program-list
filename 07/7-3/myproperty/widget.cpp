#include "widget.h"

#include <QDebug>

#include "myclass.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyClass* my = new MyClass(this);
    connect(my, &MyClass::userNameChanged, this, &Widget::userChanged);
    my->setUserName("yafei");                       //设置属性的值
    qDebug() << "userName1:" << my->getUserName();  //输出属性的值
    //使用QObject类的setProperty()函数设置属性的值
    my->setProperty("userName", "linux");
    //输出属性的值，这里使用了QObject类的property()函数，它返回值类型为QVariant
    qDebug() << "userName2:" << my->property("userName").toString();
}

Widget::~Widget() { delete ui; }

void Widget::userChanged(QString userName) { qDebug() << "user changed:" << userName; }
