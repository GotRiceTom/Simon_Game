#include <iostream>
#include "model.h"
#include <vector>
#include <thread>
#include <QThread>
#include <QTimer>

using namespace std;

Model::Model()
{
    level = 0;
    playerProgress = 0;
    AIProgress = 0;
    gameState = "wait";
    waitedOneBlink = false;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(blinkTheSequence()));
}

void Model::startButtonClicked()
{
    timer->start(1000);

    emit disableStartButtonSignal();

    cout << "START CLICKED" << endl;

    //if the game is already running, do nothing
    if (gameState != "wait")
        return;

    //fill the sequence with new numbers
    for (int i = 0; i < 25; i++)
    {
        srand(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));

        //red = 1, yellow = 2, green = 3, blue = 4
        sequence[i] = rand()%4 + 1;
    }

    //start computer's turn
    computersTurn();
}

void Model::computersTurn()
{
    gameState = "AI";

    emit disableColorButtonsSignal();

    level++;

    //set the game's level box to the current level
    emit setLevelTextBoxSignal(QString::number(level));

    //set the game state text box to "AI's Turn"
    emit setGameStateTextBoxSignal("AI's Turn");
}

void Model::blinkTheSequence()
{
    cout << "BLINK" << endl;

    if (gameState == "AI")
    {
        if (AIProgress == level)
        {
            AIProgress = 0;

            if (timer->interval() > 300)
            {
                timer->stop();
                timer->setInterval(timer->interval()-100);
                timer->start();
            }

            gameState = "player";
            emit setGameStateTextBoxSignal("Your Turn");
            emit setColorsWhiteSignal();
            emit enableColorButtonsSignal();
            playerProgress = 0;

            //set the progress bar to 0%
            emit setProgressBarValueSignal(0);

            return;
        }

        if (AIProgress == 0 && !waitedOneBlink)
        {
            waitedOneBlink = true;
            cout << "WAITED" << endl;
            return;
        }

        if (AIProgress < level)
        {
            waitedOneBlink = false;
            blinkColor(sequence[AIProgress]);
            AIProgress++;
        }
    }
}

void Model::redButtonClicked()
{
    cout << "RED CLICKED" << endl;
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
    cout << "YELLOW CLICKED" << endl;
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
    cout << "GREEN CLICKED" << endl;
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
    cout << "BLUE CLICKED" << endl;
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
    timer->stop();

    gameState = "wait";

    level = 0;

    //set the progress bar to 0%
    emit setProgressBarValueSignal(0);

    //set the level box to 0
    emit setLevelTextBoxSignal("0");

    //set the game state box to "Game Over"
    emit setGameStateTextBoxSignal("GAME OVER");

    emit enableStartButtonSignal();
}

void Model::blinkColor(int color)
{
    int wait;
    if (level < 5)
        wait = 200;
    else wait = 40;

    if (color == 1)
    {
        emit blinkRedSignalOn();
    }

    if (color == 2)
    {
        emit blinkYellowSignalOn();
    }

    if (color == 3)
    {
        emit blinkGreenSignalOn();
    }

    if (color == 4)
    {
        emit blinkBlueSignalOn();
    }

    QTimer::singleShot(timer->interval()-wait, this, SLOT(setColorsWhite()));
}

void Model::setColorsWhite()
{
    emit setColorsWhiteSignal();
}
