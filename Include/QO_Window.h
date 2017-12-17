//
// Created by john on 12/17/17.
//

#ifndef QT_TUTORIAL_QO_WINDOW_H
#define QT_TUTORIAL_QO_WINDOW_H

#include <QWidget>
#include <QPushButton>

class SlotSignalWindow : public QWidget {
Q_OBJECT
public:
    explicit SlotSignalWindow(QWidget *pParent = 0);

signals:

    void signalCounterReached();

private slots:

    void slotButtonClicked(bool checked);

private:
    int mCounter = 0;
    QPushButton *mButton;
};


#endif //QT_TUTORIAL_QO_WINDOW_H
