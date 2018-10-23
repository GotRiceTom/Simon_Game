/**
 * Eric Naegle and Tom Nguyen
 * CS 3505
 * Assignment 5
**/

#ifndef MODEL_H
#define MODEL_H

#include <QTimer>

/**
 * @brief The Model class holds all of the data and performs all of the hard computation for the Simon video game.
 * It communicates with the View (simon.h) to display data on the UI and receive user input.
 */
class Model : public QObject
{
    Q_OBJECT

private:

    // The game state can either be "player" for player's turn, "AI" for AI's turn, or "wait" for neither's turn
    std::string gameState;

    // This timer starts by firing once per second, then speeds up every round until it flattens out at just over three times per second
    QTimer* timer;

    // How many successful clicks the player has performed on their turn
    int playerProgress;

    // How many colors the AI has blinked in the sequence
    int AIProgress;

    // This is used to keep the AI from starting exactly when the player clicks the last time
    bool waitedOneBlink;

    // Length of current sequence
    int level;

    // The sequence of colors that will be followed each round
    int sequence[25];

    // This disables the UI and blinks the sequence
    void computersTurn();

    // This displays "GAME OVER" and allows the game to be restarted
    void gameOver();

    void blinkColor(int color);

public:

    Model();

public slots:

    void startButtonClicked();
    void redButtonClicked();
    void yellowButtonClicked();
    void greenButtonClicked();
    void blueButtonClicked();
    void setColorsWhite();

    // This listens to the timer and blinks the sequence of colors if it's the AI's turn
    void blinkTheSequence();

signals:

    void setGameStateTextBoxSignal(QString text);
    void setLevelTextBoxSignal(QString text);
    void setProgressBarValueSignal(int value);

    void blinkRedSignalOn();
    void blinkYellowSignalOn();
    void blinkGreenSignalOn();
    void blinkBlueSignalOn();
    void setColorsWhiteSignal();

    void disableColorButtonsSignal();
    void enableColorButtonsSignal();
    void disableStartButtonSignal();
    void enableStartButtonSignal();
};

#endif // MODEL_H
