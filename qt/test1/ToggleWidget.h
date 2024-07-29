#ifndef TOGGLEWIDGET_H
#define TOGGLEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>

class ToggleWidget : public QWidget {
    Q_OBJECT
    Q_PROPERTY(QString state READ state WRITE setState NOTIFY stateChanged FINAL)

public:
    ToggleWidget(QString state1, QString state2, QWidget *parent = nullptr);

    QString state() const;

signals:
    void stateChanged(const QString& newState);

public slots:
    void setState(const QString &newState);

private slots:
    void toggleClicked();

private:
    QPushButton *toggleButton;
    QVBoxLayout *layout;

    QString m_state;
    const QString state1, state2;
};

#endif // TOGGLEWIDGET_H
