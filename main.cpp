#include <QApplication>
#include <QPushButton>

#include "qobjects/window.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  Window window;
  window.setFixedSize(100, 50);

  QPushButton button("button", &window);
  button.setGeometry(10, 10, 80, 30);

  window.show();

  return app.exec();
}
