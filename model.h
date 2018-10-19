#ifndef MODEL_H
#define MODEL_H

#include <string>

class Model
{
private:
    std::string gameState;
    int playerProgress;
    int level;
    int sequence[1000];
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
