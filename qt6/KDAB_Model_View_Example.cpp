// https://www.youtube.com/watch?v=gs4_Edwx08E

#include <QAbstractListModel>
#include <QApplication>
#include <QListView>

// #include <QAbstractItemModelTester>

class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ListModel(QObject *parent = nullptr)
        : QAbstractListModel(parent)
    {
        list = QColor::colorNames();
    }

public:
    int rowCount(const QModelIndex &parent) const override
    {
        if (!parent.isValid())
            return list.size();
        return 0; // if root item
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
        if (!checkIndex(index, CheckIndexOption::IndexIsValid))
            return QVariant();

        const int row = index.row();
        const QString result = list.at(row);

        switch (role) {
        case Qt::DisplayRole:
            return result;
        case Qt::DecorationRole:
            return QVariant::fromValue(QColor(result));
        }

        return QVariant();
    }

private:
    QStringList list;
};

int main(int argc, char *argv[])
{
    QApplication::setApplicationName("Model/View Example");
    QApplication a(argc, argv);

    ListModel listModel;
    // QAbstractItemModelTester tester(&listModel);

    QListView listView;
    listView.setModel(&listModel);
    listView.show();

    return a.exec();
}

#include "main.moc"
