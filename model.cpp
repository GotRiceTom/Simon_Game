#include <iostream>
#include "model.h"
#include <vector>

using namespace std;

Model::Model()
{
    isGameRunning = false;
    level = 1;

    //fills the sequence with random numbers between 1 and 4
    for (int i = 0; i < 1000; i++)
    {
        //red = 1, yellow = 2, green = 3, blue = 4
        sequence[i] = rand()%4 + 1;
    }
}

void Model::startButtonClicked()
{
    //if the game is already running, do nothing
    if (isGameRunning)
        return;

    isGameRunning = true;

    //start computer's turn
    computersTurn();
}

void Model::computersTurn()
{
    //set the game state text box to "AI's Turn"

    //blink the colors
    int color = 0;
    for (int i = 0; i < level; i++)
    {
        color = sequence[i];
        blinkColor(color);
    }

    void playersTurn();
}

void Model::blinkColor(int color)
{

}
