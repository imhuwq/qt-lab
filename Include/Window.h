//
// Created by john on 12/17/17.
//

#ifndef QT_TUTORIAL_WINDOW_H
#define QT_TUTORIAL_WINDOW_H

#include <QWidget>

class QPushButton;

class Window : public QWidget {
public:
    explicit Window(QWidget *pParent = 0);

private:
    QPushButton *mButton;
};

#endif //QT_TUTORIAL_WINDOW_H
