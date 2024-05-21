#include <QApplication>
#include <QColor>
#include <QListView>
#include <QPainter>
#include <QStringList>
#include <QStringListModel>
#include <QStyledItemDelegate>

// Custom Delegate to paint items in their respective colors
class ColorDelegate : public QStyledItemDelegate
{
public:
    // Inherit all constructor from QStyledItemDelegate
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override
    {
        // Get the color name from the model
        QString colorName = index.data().toString();
        QColor color(colorName);

        // Fill the background with the color
        painter->fillRect(option.rect, color);

        // Define the list of colors that should always use black text
        static const QSet<QString> alwaysBlackTextColor = {"aqua",
                                                           "chartreuse",
                                                           "cyan",
                                                           "lawngreen",
                                                           "lime",
                                                           "mediumspringgreen",
                                                           "springgreen",
                                                           "transparent",
                                                           "yellow",
                                                           "yellowgreen"};

        // Set the text color to white or black base on the color brightness or specific exceptions
        QColor textColor = (alwaysBlackTextColor.contains(colorName) || color.lightness() > 128)
                               ? Qt::black
                               : Qt::white;

        painter->setPen(textColor);

        // Draw the text
        painter->drawText(option.rect, Qt::AlignLeft | Qt::AlignVCenter, colorName);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the model
    QStringListModel model;
    QStringList colorNames = QColor::colorNames();
    model.setStringList(colorNames);

    // Create the view
    QListView view;
    view.setModel(&model);

    // Set the custom delegate
    ColorDelegate *delegate = new ColorDelegate(&view);
    view.setItemDelegate(delegate);

    // Show the view
    view.setWindowTitle("String List Model/View");
    view.resize(300, 200);
    view.show();

    return a.exec();
}
