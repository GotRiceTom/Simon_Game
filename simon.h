#ifndef SIMON_H
#define SIMON_H

#include "model.h"
#include <QWidget>
#include <QtGui>


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
    void setAllColorButtonsToWhite();

    void on_StartButton_clicked();

    void viewDisplay();

    //slots that listen to model signals
    void enableButton();
    void disableButton();
    void displayLevelTextBox(QString);
    void displayGameStateText(QString);
    void displayProgressBar(int);

    //blinking slots for the view that listen to model signals

    void blinkRedButtonOn();
    void blinkGreenButtonOn();
    void blinkBlueButtonOn();
    void blinkYellowButtonOn();

    void blinkRedButtonOff();
    void blinkGreenButtonOff();
    void blinkBlueButtonOff();
    void blinkYellowButtonOff();

signals:
    void startSignal();

private:
    Ui::Simon *ui;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    bool isButtonBlinked;

    Model* SimonModel;

};

#endif // SIMON_H
