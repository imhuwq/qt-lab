//
// Created by john on 12/17/17.
//

#include <QtWidgets/QApplication>

#include "Window.h"
#include "RespondindEvents.h"

int RespondingEvents(int argc, char **argv) {
    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}