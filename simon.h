#ifndef SIMON_H
#define SIMON_H

#include "model.h"
#include <QWidget>
#include <QtGui>
#include <QTimer>

namespace Ui {
class Simon;
}

class Simon : public QWidget
{
    Q_OBJECT

public:
    explicit Simon(QWidget *parent = nullptr);
    ~Simon();

private slots:
    void startButton_clicked();
    void redButton_clicked();
    void greenButton_clicked();
    void blueButton_clicked();
    void yellowButton_clicked();

    void blink_Pattern();

    void blink_redButton();
    void blink_blueButton();
    void blink_greenButton();
    void blink_yellowButton();



private:
    Ui::Simon *ui;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    bool isButtonBlinked;

    Model *SimonModel;
    QTimer *timer;


};

#endif // SIMON_H
