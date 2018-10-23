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

    int sequence[1000];

public:

    //constructor
    Model();

    void computersTurn();
    void gameOver();
    void blinkColor(int color,int duration);
    void blinkTheSequence();

public slots:

    void startButtonClicked();
    void redButtonClicked();
    void yellowButtonClicked();
    void greenButtonClicked();
    void blueButtonClicked();

signals:

    void setGameStateTextBoxSignal(QString text);
    void setLevelTextBoxSignal(QString text);
    void setProgressBarValueSignal(int value);
    void blinkRedSignal(int duration);
    void blinkYellowSignal(int duration);
    void blinkGreenSignal(int duration);
    void blinkBlueSignal(int duration);
    void disableColorButtonsSignal();
    void enableColorButtonsSignal();
};

#endif // MODEL_H
