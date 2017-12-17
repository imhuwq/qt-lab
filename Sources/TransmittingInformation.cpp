//
// Created by john on 12/17/17.
//

#include <QWidget>
#include <QSlider>
#include <QProgressBar>
#include <QApplication>

#include "TransmittingInformation.h"

int TransmittingInformation(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 80);

    QSlider *slider = new QSlider(&window);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 10, 180, 30);

    QProgressBar *progressBar = new QProgressBar(&window);
    progressBar->setOrientation(Qt::Horizontal);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 40, 180, 30);

    window.show();
    QObject::connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
    return app.exec();
}