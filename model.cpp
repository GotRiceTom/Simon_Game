#include <iostream>
#include "model.h"
#include <vector>
#include <thread>

using namespace std;

Model::Model()
{
    level = 0;

    //fills the sequence with random numbers between 1 and 4
    for (int i = 0; i < 10; i++)
    {
        //red = 1, yellow = 2, green = 3, blue = 4
        sequence[i] = rand()%4 + 1;
        std::cout<< sequence[i] << std::endl;
    }

    std::cout << "Length of array = " << (sizeof(sequence)/sizeof(*sequence)) << std::endl;

    gameState = "wait";
}

void Model::startButtonClicked()
{
    //if the game is already running, do nothing
    if (gameState != "wait")
        return;

    //start computer's turn
    computersTurn();
}

void Model::computersTurn()
{
    gameState = "AI";

    level++;

    //set the game's level box to the current level

    //set the game state text box to "AI's Turn"

    //wait for 1 second before showing player colors
    std::this_thread::sleep_for(std::chrono::seconds(1));

    //set the progress bar to 0%

    //blink the colors
    int color = 0;
    for (int i = 0; i < level; i++)
    {
        color = sequence[i];
       // blinkColor(color);
    }

    //set the game state text box to "Your Turn"

    //set the progress bar to 0%

    playerProgress = 0.0;

    gameState = "player";
}

void Model::redButtonClicked()
{
    //if it's not the player's turn, do nothing.
    if (gameState != "player")
    {
        return;
    }

    if (sequence[playerProgress] != 1)
    {
        gameOver();
    }

    else
    {
        playerProgress++;

        //update progress bar to ((playerProgress * 100) / level)

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}

void Model::yellowButtonClicked()
{
    //if it's not the player's turn, do nothing.
    if (gameState != "player")
    {
        return;
    }

    if (sequence[playerProgress] != 2)
    {
        gameOver();
    }

    else
    {
        playerProgress++;

        //update progress bar to ((playerProgress * 100) / level)

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}

void Model::greenButtonClicked()
{
    //if it's not the player's turn, do nothing.
    if (gameState != "player")
    {
        return;
    }

    if (sequence[playerProgress] != 3)
    {
        gameOver();
    }

    else
    {
        playerProgress++;

        //update progress bar to ((playerProgress * 100) / level)

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}

void Model::blueButtonClicked()
{
    //if it's not the player's turn, do nothing.
    if (gameState != "player")
    {
        return;
    }

    if (sequence[playerProgress] != 4)
    {
        gameOver();
    }

    else
    {
        playerProgress++;

        //update progress bar to ((playerProgress * 100) / level)

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}

int Model::getAICurrentLevel()
{
    return 0;
}

void Model::gameOver()
{
    gameState = "wait";

    level = 0;

    //set the progress bar to 0%

    //set the level box to 0

    //set the game state box to "Game Over"
}

void Model::getLevel()
{

}

