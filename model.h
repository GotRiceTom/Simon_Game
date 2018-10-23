#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <cstring>
#include <QObject>
#include <QString>
#include <QTimer>

class Model : public QObject
{

    Q_OBJECT

private:
    //can either be "player", "AI", or "wait"
    std::string gameState;

    QTimer* timer;

    //how many times the player has clicked
    int playerProgress;
    int AIProgress;

    //length of current sequence
    int level;

    int sequence[25];

public:

    //constructor
    Model();

    void computersTurn();
    void gameOver();
    void blinkColor(int color);

public slots:

    void startButtonClicked();
    void redButtonClicked();
    void yellowButtonClicked();
    void greenButtonClicked();
    void blueButtonClicked();
    void blinkTheSequence();
    void setColorsWhite();

signals:

    void setGameStateTextBoxSignal(QString text);
    void setLevelTextBoxSignal(QString text);
    void setProgressBarValueSignal(int value);
    void setColorsWhiteSignal();

    void blinkRedSignalOn();
    void blinkYellowSignalOn();
    void blinkGreenSignalOn();
    void blinkBlueSignalOn();

    void setAllColorButtonsWhite();
    void disableColorButtonsSignal();
    void enableColorButtonsSignal();
    void disableStartButtonSignal();
    void enableStartButtonSignal();
};

#endif // MODEL_H
