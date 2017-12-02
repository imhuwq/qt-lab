#include "ParentingSystem.h"

int ParentingSystem(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(100, 50);

    QPushButton button("Hello World", &window);
    button.setGeometry(10, 10, 80, 30);

    window.show();
    return app.exec();
}
