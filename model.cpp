/**
 * Eric Naegle and Tom Nguyen
 * CS 3505
 * Assignment 5
**/

#include "model.h"

using namespace std;

Model::Model()
{
    level = 0;
    playerProgress = 0;
    AIProgress = 0;
    gameState = "wait";
    waitedOneBlink = false;

    emit disableColorButtonsSignal();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(blinkTheSequence()));
}

void Model::startButtonClicked()
{
    timer->start(1000);

    emit disableStartButtonSignal();

    //if the game is already running, do nothing
    if (gameState != "wait")
        return;

    //otherwise, fill the sequence with new numbers
    for (int i = 0; i < 25; i++)
    {
        //seed the random function with the current time
        srand(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));

        //red = 1, yellow = 2, green = 3, blue = 4
        sequence[i] = rand()%4 + 1;
    }

    //then start the computer's turn
    computersTurn();
}

void Model::computersTurn()
{
    gameState = "AI";

    emit disableColorButtonsSignal();

    level++;

    emit setLevelTextBoxSignal(QString::number(level));

    emit setGameStateTextBoxSignal("AI's Turn");
}

void Model::blinkTheSequence()
{
    //only blink if it's the AI's turn
    if (gameState == "AI")
    {
        //if the AI has finished the sequence, speed up the timer and start the player's turn
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
            emit setProgressBarValueSignal(0);

            return;
        }

        //don't blink immediately when the AI's turn starts, wait one timer tick
        if (AIProgress == 0 && !waitedOneBlink)
        {
            waitedOneBlink = true;
            return;
        }

        //then blink the colors
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
    //if it's not the player's turn, do nothing.
    if (gameState != "player")
    {
        return;
    }

    //if the player misclicks, game over
    if (sequence[playerProgress] != 1)
    {
        gameOver();
    }

    //otherwise, proceed
    else
    {
        playerProgress++;

        emit setProgressBarValueSignal((playerProgress*100) / level);

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}

void Model::yellowButtonClicked()
{
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

        emit setProgressBarValueSignal((playerProgress*100) / level);

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}

void Model::greenButtonClicked()
{
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

        emit setProgressBarValueSignal((playerProgress*100) / level);

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}

void Model::blueButtonClicked()
{
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

        emit setProgressBarValueSignal((playerProgress*100) / level);

        if (playerProgress == level)
        {
            computersTurn();
        }
    }
}


void Model::gameOver()
{
    emit disableColorButtonsSignal();

    timer->stop();

    gameState = "wait";

    level = 0;

    emit setProgressBarValueSignal(0);

    emit setLevelTextBoxSignal("0");

    emit setGameStateTextBoxSignal("GAME OVER");

    emit enableStartButtonSignal();
}

void Model::blinkColor(int color)
{
    //"wait" is the duration that the box goes white before the next box blinks.
    //It speeds up a little bit as the rounds increase.
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

    //blinks the boxes white between blinks
    QTimer::singleShot(timer->interval()-wait, this, SLOT(setColorsWhite()));
}

void Model::setColorsWhite()
{
    emit setColorsWhiteSignal();
}
