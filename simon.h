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
    explicit Simon(Model* SimonModel, QWidget *parent = nullptr);
    ~Simon();

public  slots:
    void redButton_clicked();
    void greenButton_clicked();
    void blueButton_clicked();
    void yellowButton_clicked();

    void on_StartButton_clicked();

    void viewDisplay();

    //slots that listen to model signals
    void enableButton();
    void disableButton();
    void displayLevelTextBox(QString);
    void displayGameStateText(QString);
    void displayProgressBar(int);

    //blinking slots for the view that listen to model signals

    void blinkRedButton(int);
    void blinkGreenButton(int);
    void blinkBlueButton(int);
    void blinkYellowButton(int);

signals:
    void startSignal();

private:
    Ui::Simon *ui;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    bool isButtonBlinked;

    Model* SimonModel;
    QTimer *timer;

    void blinkRedHelper();
    void blinkBlueHelper();
    void blinkGreenHelper();
    void blinkYellowHelper();

};

#endif // SIMON_H
