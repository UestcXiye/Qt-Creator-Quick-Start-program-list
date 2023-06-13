#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QStringList>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver, drivers)
        qDebug() << driver;
    return a.exec();
}
