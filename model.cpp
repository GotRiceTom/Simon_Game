#include <iostream>
#include "model.h"
#include <vector>
#include <thread>
#include <QThread>

using namespace std;

Model::Model()
{
    level = 4;

    gameState = "wait";
}

void Model::startButtonClicked()
{
    //if the game is already running, do nothing
    if (gameState != "wait")
        return;

    //fill the sequence with new numbers
    for (int i = 0; i < 25; i++)
    {
        //red = 1, yellow = 2, green = 3, blue = 4
        sequence[i] = rand()%4 + 1;
        std::cout << sequence[i] << std::endl;
    }

    //start computer's turn
    computersTurn();
}

void Model::computersTurn()
{
    gameState = "AI";

    level++;

    //emit disableColorButtonsSignal();
    cout << "disabling" << endl;

    //set the game's level box to the current level
    emit setLevelTextBoxSignal(QString::number(level));

    //set the game state text box to "AI's Turn"
    emit setGameStateTextBoxSignal("AI's Turn");

    //set the progress bar to 0%
    emit setProgressBarValueSignal(0);

    //blink the colors
    blinkTheSequence();

    //set the game state text box to "Your Turn"
    emit setGameStateTextBoxSignal("Your Turn");

    playerProgress = 0;

    gameState = "player";

    emit enableColorButtonsSignal();
    cout << "enabling" << endl;
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
        cout << "blinking " << i << endl;
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
        emit blinkRedSignal(duration);
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
        emit setAllColorButtonsWhite();
    }

    if (color == 2)
    {
        //blink the yellow button
        emit blinkYellowSignal(duration);
        QThread::msleep(duration);
        emit setAllColorButtonsWhite();
    }

    if (color == 3)
    {
        //blink the green button
        emit blinkGreenSignal(duration);
        QThread::msleep(duration);
        emit setAllColorButtonsWhite();
    }

    if (color == 4)
    {
        //blink the blue button
        emit blinkBlueSignal(duration);
        QThread::msleep(duration);
        emit setAllColorButtonsWhite();
    }
}
