/** **************************
 * File System Viewer Example
 * ***************************
 */
#include <QApplication>
#include <QDir>
#include <QFileSystemModel>
#include <QListView>
#include <QSplitter>
#include <QTreeView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSplitter *splitter = new QSplitter;

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    splitter->setWindowTitle("Two views onto same file system model");
    splitter->show();

    return app.exec();
}
