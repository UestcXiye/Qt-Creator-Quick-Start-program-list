#include <QApplication>

#include "mydialog.h"
#include "mywidget.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MyDialog dialog;
    if (dialog.exec() == QDialog::Accepted)//判断dialog执行结果
    {
        //若按下了“进入主界面”按钮，则显示主界面
        MyWidget w;
        w.show();
        return a.exec();//程序正常运行
    }
    else
        return 0;//否则，退出程序
}
