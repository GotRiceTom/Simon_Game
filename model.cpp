#include <iostream>
#include "model.h"
#include <vector>
#include <thread>

using namespace std;

Model::Model()
{
    level = 0;

    //fills the sequence with random numbers between 1 and 4
    for (int i = 0; i < 1000; i++)
    {
        //red = 1, yellow = 2, green = 3, blue = 4
        sequence[i] = rand()%4 + 1;
    }

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

    emit disableColorButtonsSignal();

    //set the game's level box to the current level
    emit setLevelTextBoxSignal(QString::number(level));

    //set the game state text box to "AI's Turn"
    emit setGameStateTextBoxSignal("AI's Turn");

    //wait for 1 second before showing player colors
    std::this_thread::sleep_for(std::chrono::seconds(1));

    //set the progress bar to 0%
    emit setProgressBarValueSignal(0);

    //blink the colors
    blinkTheSequence();

    //set the game state text box to "Your Turn"
    emit setGameStateTextBoxSignal("Your Turn");

    playerProgress = 0;

    gameState = "player";

    emit enableColorButtonsSignal();
}

void Model::blinkTheSequence()
{
    for (int i = 0; i < level; i++)
    {
        int duration = 1000 - (level*100);
        if (duration < 200)
        {
            duration = 200;
        }
        blinkColor(sequence[i],duration);
    }
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
        emit setProgressBarValueSignal((playerProgress*100) / level);

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
        emit setProgressBarValueSignal((playerProgress*100) / level);

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
        emit setProgressBarValueSignal((playerProgress*100) / level);

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
        emit setProgressBarValueSignal((playerProgress*100) / level);

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}

void Model::gameOver()
{
    gameState = "wait";

    level = 0;

    //set the progress bar to 0%
    emit setProgressBarValueSignal(0);

    //set the level box to 0
    emit setLevelTextBoxSignal("0");

    //set the game state box to "Game Over"
    emit setGameStateTextBoxSignal("GAME OVER");

}

void Model::blinkColor(int color,int duration)
{
    if (color == 1)
    {
        //blink the red button
        emit blinkRedSignal();
    }

    if (color == 2)
    {
        //blink the yellow button
        emit blinkYellowSignal();
    }

    if (color == 3)
    {
        //blink the green button
        emit blinkGreenSignal();
    }

    if (color == 4)
    {
        //blink the blue button
        emit blinkBlueSignal();
    }
}
