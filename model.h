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

    int sequence[10];



public:

    //constructor
    Model();

    void startButtonClicked();
    void computersTurn();
    void redButtonClicked();
    void yellowButtonClicked();
    void greenButtonClicked();
    void blueButtonClicked();

    //added helper method in the model class
    bool isCorrectSeq(int);
    int getAICurrentLevel();
    void gameOver();
    void getLevel();
    void addStep();
    void resertStep();
};

#endif // MODEL_H
