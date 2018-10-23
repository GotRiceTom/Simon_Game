#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <cstring>
#include <QObject>
#include <QString>

class Model : public QObject
{

    Q_OBJECT

private:
    //can either be "player", "AI", or "wait"
    std::string gameState;

    //how many times the player has clicked
    int playerProgress;

    //length of current sequence
    int level;

    int sequence[25];

public:

    //constructor
    Model();

    void computersTurn();
    void gameOver();

    void blinkTheSequence();

public slots:

    void startButtonClicked();
    void redButtonClicked();
    void yellowButtonClicked();
    void greenButtonClicked();
    void blueButtonClicked();
    void blinkColor(int color,int duration);

    //below methods will use the single shot
    void blinkBlueOff();
    void blinkGreenOff();
    void blinkYellowOff();
    void blinkRedOff();

signals:

    void setGameStateTextBoxSignal(QString text);
    void setLevelTextBoxSignal(QString text);
    void setProgressBarValueSignal(int value);

    void blinkRedSignalOn();
    void blinkYellowSignalOn();
    void blinkGreenSignalOn();
    void blinkBlueSignalOn();

    void blinkRedSignalOff();
    void blinkYellowSignalOff();
    void blinkGreenSignalOff();
    void blinkBlueSignalOff();

    void setAllColorButtonsWhite();
    void disableColorButtonsSignal();
    void enableColorButtonsSignal();
};

#endif // MODEL_H
