#include "ToggleWidget.h"

ToggleWidget::ToggleWidget(QString state1, QString state2, QWidget *parent)
    : QWidget(parent)
    , state1(state1), state2(state2)
{
    // Erstelle Toggle-Button
    toggleButton = new QPushButton(state1, this);

    // Verbinde Signal mit Slot
    connect(toggleButton, &QPushButton::clicked, this, &ToggleWidget::toggleClicked);

    // Füge Button zum Layout hinzu
    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(toggleButton);
}

QString ToggleWidget::state() const {
    return m_state;
}

void ToggleWidget::setState(const QString &newState) {
    if (m_state != newState) {
        m_state = newState;
        emit stateChanged(m_state);
    }
}

void ToggleWidget::toggleClicked() {
    if (toggleButton->text() == state1) {
        toggleButton->setText(state2);
        setState(state2);
    } else {
        toggleButton->setText(state1);
        setState(state1);
    }
}
