#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    QStringList stringList;

public:
    StringListModel(const QStringList& strings, QObject* parent = 0) : QAbstractListModel(parent), stringList(strings)
    {
    }
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};

#endif  // STRINGLISTMODEL_H
