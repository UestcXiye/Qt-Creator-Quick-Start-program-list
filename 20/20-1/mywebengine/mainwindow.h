#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}
class QWebEngineView;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    QWebEngineView* view;

    QLineEdit* locationEdit;
    int progress;

protected slots:
    void changeLocation();     // 改变路径
    void setProgress(int);     // 更新进度
    void adjustTitle();        // 更新标题显示
    void finishLoading(bool);  // 加载完成后进行处理
};

#endif  // MAINWINDOW_H
