//
// Created by john on 12/17/17.
//

#include "QO_Window.h"

SlotSignalWindow::SlotSignalWindow(QWidget *pParent) : QWidget(pParent) {
    setFixedSize(100, 50);

    mButton = new QPushButton("Hello World", this);
    mButton->setGeometry(10, 10, 80, 30);

    mButton->setCheckable(true);
    connect(mButton, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
}

void SlotSignalWindow::slotButtonClicked(bool checked) {
    checked ? mButton->setText("Checked") : mButton->setText("Hello World");
}

#include "QO_Window.moc"