//
// Created by john on 12/17/17.
//

#include <QApplication>
#include "QO_Window.h"

SlotSignalWindow::SlotSignalWindow(QWidget *pParent) : QWidget(pParent) {
    setFixedSize(100, 50);

    mButton = new QPushButton("Hello World", this);
    mButton->setGeometry(10, 10, 80, 30);

    mButton->setCheckable(true);
    connect(mButton, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    connect(this, SIGNAL(signalCounterReached()), QApplication::instance(), SLOT(quit()));
}

void SlotSignalWindow::slotButtonClicked(bool checked) {
    checked ? mButton->setText("Checked") : mButton->setText("Hello World");
    mCounter++;
    if (mCounter == 10) {
        emit signalCounterReached();
    }
}
