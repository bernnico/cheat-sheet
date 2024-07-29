#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <cmath>
#include <QDebug>

#include "ToggleWidget.h"

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // Erstelle LineEdits
        inputLineEdit = new QLineEdit(this);
        outputLineEdit1 = new QLineEdit(this);
        outputLineEdit2 = new QLineEdit(this);

        // Erstelle Toggle-Widget
        toggleWidget = new ToggleWidget("Degrees", "Radians", this);

        // Verbinde Signal des Toggle-Widgets mit einem Slot, um die Berechnungen zu aktualisieren
        connect(toggleWidget, &ToggleWidget::stateChanged, this, &MainWindow::updateCalculations);

        // Layout für LineEdits
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(inputLineEdit);
        layout->addWidget(outputLineEdit1);
        layout->addWidget(outputLineEdit2);

        // // Bestimme die maximale Breite der LineEdits und setze sie als Mindestbreite des Toggle-Widgets
        // int maxWidth = std::max({inputLineEdit->sizeHint().width(),
        //                          outputLineEdit1->sizeHint().width(),
        //                          outputLineEdit2->sizeHint().width()});
        // toggleWidget->setMinimumWidth(maxWidth);

        // Füge LineEdits und Toggle-Widget zum Hauptlayout hinzu
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addLayout(layout);
        mainLayout->addWidget(toggleWidget);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        setLayout(mainLayout);

        // Verbinde Slot, um Berechnungen zu aktualisieren, wenn der Benutzer Eingaben ändert
        connect(inputLineEdit, &QLineEdit::textChanged, this, &MainWindow::updateCalculations);
    }

private slots:
    void updateCalculations() {
        QString inputText = inputLineEdit->text();
        double x = inputText.toDouble();

        if (toggleWidget->state() == "Degrees") {
            // Umrechnung von Grad in Radiant
            x = x * M_PI / 180.0;
        }

        // Berechne sin(x) und sin(x)/2
        double sinValue = sin(x);
        double sinHalfValue = sinValue / 10.0;

        // Setze die Ergebnisse in die entsprechenden LineEdits
        outputLineEdit1->setText(QString::number(sinValue));
        outputLineEdit2->setText(QString::number(sinHalfValue));
    }

private:
    ToggleWidget *toggleWidget;
    QLineEdit *inputLineEdit;
    QLineEdit *outputLineEdit1;
    QLineEdit *outputLineEdit2;
};
