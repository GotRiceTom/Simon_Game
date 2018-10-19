#ifndef MODEL_H
#define MODEL_H

#include <string>

class Model
{
private:
    //can either be "player", "AI", or "wait"
    std::string gameState;

    //how many times the player has clicked
    int playerProgress;

    //length of current sequence
    int level;

    int sequence[1000];

    //constructor
    Model();

public:
    void startButtonClicked();
    void computersTurn();
    void blinkColor(int color);
    void redButtonClicked();
    void yellowButtonClicked();
    void greenButtonClicked();
    void blueButtonClicked();
    void gameOver();
};

#endif // MODEL_H
