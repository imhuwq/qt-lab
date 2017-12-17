//
// Created by john on 12/17/17.
//

#include <QApplication>


#include "QO_Window.h"
#include "CustomSlotSignal.h"

int CustomSlotSignal(int argc, char **argv) {
    QApplication app(argc, argv);
    SlotSignalWindow window;
    window.show();
    return app.exec();
}