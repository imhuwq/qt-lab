#ifndef QT_TUTORIAL_WINDOW_H
#define QT_TUTORIAL_WINDOW_H

#include <QWidget>

class Window : public QWidget {
 Q_OBJECT
 public:
  explicit Window(QWidget *parent = 0);

 signals:
 public slots:
};

#endif //QT_TUTORIAL_WINDOW_H
