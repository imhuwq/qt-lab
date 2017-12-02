#include <QApplication>
#include <QPushButton>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QPushButton button;
    button.setText("My Text");
    button.setToolTip("A tooltip");

    QFont font ("Courier");
    button.setFont(font);

    button.setIcon(QIcon::fromTheme("face-smile"));

    button.show();

    return app.exec();
}
