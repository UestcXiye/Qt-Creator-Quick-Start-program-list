#include <QApplication>
#include <QListView>
#include <QTableView>

#include "stringlistmodel.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QStringList list;
    list << "a"
         << "b"
         << "c";
    StringListModel model(list);

    QListView listView;
    listView.setModel(&model);
    listView.show();

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    return app.exec();
}
