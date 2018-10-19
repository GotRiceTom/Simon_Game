#ifndef MODEL_H
#define MODEL_H

#include <string>

class Model
{
private:
    bool isGameRunning;
    std::string gameState;
    int level;
    int sequence[1000];
    Model();

public:
    void startButtonClicked();
    void computersTurn();
    void blinkColor(int color);
    void playersTurn();
};

#endif // MODEL_H
