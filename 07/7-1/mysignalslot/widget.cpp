#include "widget.h"

#include "mydialog.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyDialog* dlg = new MyDialog(this);
    //将对话框的自定义信号与主界面中的自定义槽进行关联
    connect(dlg, SIGNAL(dlgReturn(int)), this, SLOT(showValue(int)));
    // connect(dlg, &MyDialog::dlgReturn, this, &Widget::showValue);  //另一种connect重载模式
    dlg->show();
}

Widget::~Widget() { delete ui; }

void Widget::showValue(int value) { ui->label->setText(tr("获取的值是：%1").arg(value)); }
