#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QDialog>

namespace Ui
{
    class HelloDialog;
}

class HelloDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::HelloDialog* ui;

public:
    explicit HelloDialog(QWidget* parent = 0);
    ~HelloDialog();
};

#endif  // HELLODIALOG_H
