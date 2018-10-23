/**
 * Eric Naegle and Tom Nguyen
 * CS 3505
 * Assignment 5
**/

#ifndef SIMON_H
#define SIMON_H

#include "model.h"
#include <QWidget>


namespace Ui {

/**
 * This is the View for the Simon video game. It listens to clicks from the UI, and communicates back and forth
 * with the Model (model.h) to help the user play the game.
 */
class Simon;
}

class Simon : public QWidget
{
    Q_OBJECT

private:
    Ui::Simon *ui;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    Model* SimonModel;

public:
    explicit Simon(Model* SimonModel, QWidget *parent = nullptr);
    ~Simon();

// Slots that listen to Model signals
public  slots:
    void setAllColorButtonsToWhite();
    void displayLevelTextBox(QString);
    void displayGameStateText(QString);
    void displayProgressBar(int);
    void enableColorButtons();
    void disableColorButtons();
    void enableStartButton();
    void disableStartButton();
    void blinkRedButtonOn();
    void blinkGreenButtonOn();
    void blinkBlueButtonOn();
    void blinkYellowButtonOn();

// Slots that listen to the ui
private slots:
    void on_redButton_clicked();
    void on_greenButton_clicked();
    void on_yellowButton_clicked();
    void on_blueButton_clicked();
    void on_StartButton_clicked();

// Signals sent from the View to the Model
signals:
    void startSignal();
    void redSignal();
    void yellowSignal();
    void greenSignal();
    void blueSignal();
};

#endif // SIMON_H
