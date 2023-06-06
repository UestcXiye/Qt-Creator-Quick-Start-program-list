#include <QApplication>
#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // 创建文件系统模型
    QFileSystemModel model;
    // 指定要监视的目录
    model.setRootPath(QDir::currentPath());
    // 创建树型视图
    QTreeView tree;
    tree.setModel(&model);                                // 为视图指定模型
    tree.setRootIndex(model.index(QDir::currentPath()));  // 指定根索引
    // 创建列表视图
    QListView list;
    list.setModel(&model);
    list.setRootIndex(model.index(QDir::currentPath()));

    tree.show();
    list.show();

    return app.exec();
}
