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
    void setAllColorButtonsToWhite();
    //slots that listen to model signals
    void enableColorButtons();
    void disableColorButtons();
    void enableStartButton();
    void disableStartButton();
    void displayLevelTextBox(QString);
    void displayGameStateText(QString);
    void displayProgressBar(int);

    void blinkRedButtonOn();
    void blinkGreenButtonOn();
    void blinkBlueButtonOn();
    void blinkYellowButtonOn();

private slots:
    void on_redButton_clicked();
    void on_greenButton_clicked();
    void on_yellowButton_clicked();
    void on_blueButton_clicked();
    void on_StartButton_clicked();

    //blinking slots for the view that listen to model signals

signals:
    void startSignal();
    void redSignal();
    void yellowSignal();
    void greenSignal();
    void blueSignal();

private:
    Ui::Simon *ui;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    bool isButtonBlinked;

    Model* SimonModel;

};

#endif // SIMON_H
