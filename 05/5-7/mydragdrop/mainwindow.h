#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

protected:
    void dragEnterEvent(QDragEnterEvent* event);  //拖动进入事件
    void dropEvent(QDropEvent* event);            //放下事件
};

#endif  // MAINWINDOW_H
