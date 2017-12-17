//
// Created by john on 12/17/17.
//

#include <QApplication>
#include <QPushButton>

#include "Window.h"

Window::Window(QWidget *pParent) : QWidget(pParent) {
    setFixedSize(100, 50);

    mButton = new QPushButton("Hello World", this);
    mButton->setGeometry(10, 10, 80, 30);

    connect(mButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}