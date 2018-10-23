#include "simon.h"
#include "ui_simon.h"
#include <QKeyEvent>
#include <QApplication>
#include <iostream>
#include <thread>

Simon::Simon(Model* m,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simon)
{
    ui->setupUi(this);

    //set up the model for Simon
    SimonModel = m;

    //give the progress bar a min and man
    // you can get the current value from the progress by calling
    // progressBar.value()s
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);

    // the proper way to do a two way connection from view -> model and model -> view
   //connect(this, SIGNAL(modelSignal()), SimonModel, SLOT(displayMessage()));
  // connect(SimonModel, SIGNAL(endModelSignal()), this, SLOT(viewDisplay()));



    //connecting the StartButton's signal 'clicked' to the function slot startButton_clicked

   connect(ui->redButton,SIGNAL(clicked(bool)),this,SLOT(redButton_clicked()));
   connect(ui->yellowButton,SIGNAL(clicked(bool)),this,SLOT(yellowButton_clicked()));
   connect(ui->blueButton,SIGNAL(clicked(bool)),this,SLOT(blueButton_clicked()));
   connect(ui->greenButton,SIGNAL(clicked(bool)),this,SLOT(greenButton_clicked()));




   // the proper connection
   connect(this, SIGNAL(startSignal()), SimonModel, SLOT(startButtonClicked()));

   connect(SimonModel, SIGNAL(disableColorButtonsSignal()), this, SLOT(disableButton()));
   connect(SimonModel, SIGNAL(enableColorButtonsSignal()), this, SLOT(enableButton()));
   connect(SimonModel, SIGNAL(setLevelTextBoxSignal(QString)), this, SLOT(displayLevelTextBox(QString)));
   connect(SimonModel, SIGNAL(setGameStateTextBoxSignal(QString)), this, SLOT(displayGameStateText(QString)));
   connect(SimonModel, SIGNAL(setProgressBarValueSignal(int)), this, SLOT(displayProgressBar(int)));

   //blink color slots connection

   connect(SimonModel, SIGNAL(blinkRedSignalOn()), this, SLOT(blinkRedButtonOn()));
   connect(SimonModel, SIGNAL(blinkGreenSignalOn()), this ,SLOT(blinkGreenButtonOn()));
   connect(SimonModel, SIGNAL(blinkBlueSignalOn()), this ,SLOT(blinkBlueButtonOn()));
   connect(SimonModel, SIGNAL(blinkYellowSignalOn()),this,SLOT(blinkYellowButtonOn()));

   connect(SimonModel, SIGNAL(blinkBlueSignalOff()), this, SLOT(blinkBlueButtonOff()));
   connect(SimonModel, SIGNAL(blinkRedSignalOff()), this, SLOT(blinkRedButtonOff()));
   connect(SimonModel, SIGNAL(blinkGreenSignalOff()), this, SLOT(blinkGreenButtonOff()));
   connect(SimonModel, SIGNAL(blinkYellowSignalOff()), this, SLOT(blinkYellowButtonOff()));

}

Simon::~Simon()
{
    delete ui;
}

void Simon::keyPressEvent(QKeyEvent *event){
    //all the keys are match to the numpad arrow
    // using number 8,4,2,6 numpad


    if(event->key() == Qt::Key_8){
        ui->redButton->setStyleSheet("background-color:red");
        //ui->progressBar->setValue(ui->progressBar->value() + 1);
    }

    if(event->key() == Qt::Key_4){
        ui->yellowButton->setStyleSheet("background-color:yellow");
        //ui->progressBar->setValue(ui->progressBar->value() + 1);
    }

    if(event->key() == Qt::Key_2){
        ui->blueButton->setStyleSheet("background-color:blue");
        //ui->progressBar->setValue(ui->progressBar->value() + 1);

    }

    if(event->key() == Qt::Key_6){
        ui->greenButton->setStyleSheet("background-color:green");
        //ui->progressBar->setValue(ui->progressBar->value() + 1);
    }
}


void Simon::keyReleaseEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_8){
        ui->redButton->setStyleSheet("background-color:white");

    }
    //check key press works
    if(event->key() == Qt::Key_4){
        ui->yellowButton->setStyleSheet("background-color:white");
    }
    //check key press works
    if(event->key() == Qt::Key_2){
        ui->blueButton->setStyleSheet("background-color:white");

    }
    //check key press works
    if(event->key() == Qt::Key_6){
        ui->greenButton->setStyleSheet("background-color:white");
    }
}




void Simon::redButton_clicked()
{
     ui->progressBar->setValue(ui->progressBar->value() + 1);
}

void Simon::greenButton_clicked()
{
     ui->progressBar->setValue(ui->progressBar->value() + 1);
}

void Simon::blueButton_clicked()
{
     ui->progressBar->setValue(ui->progressBar->value() + 1);
}

void Simon::yellowButton_clicked()
{
    ui->progressBar->setValue(ui->progressBar->value() + 1);

}



void Simon::on_StartButton_clicked()
{
    emit startSignal();
}

void Simon::viewDisplay()
{
    std::cout<< "viewDisplay is called from start button" << std::endl;
}

void Simon::disableButton()
{
    ui->StartButton->setDisabled(true);
    ui->redButton->setDisabled(true);
    ui->greenButton->setDisabled(true);
    ui->blueButton->setDisabled(true);
    ui->yellowButton->setDisabled(true);
}

void Simon::enableButton()
{
    ui->StartButton->setEnabled(true);
    ui->redButton->setEnabled(true);
    ui->greenButton->setEnabled(true);
    ui->blueButton->setEnabled(true);
    ui->yellowButton->setEnabled(true);
}

void Simon::displayLevelTextBox(QString text)
{
    ui->LevelBox->setText(text);
}

void Simon::displayGameStateText(QString text)
{
    ui->GameStateBox->setText(text);
}

void Simon::displayProgressBar(int progress)
{
    ui->progressBar->setValue(progress);
}

//Below methods blink the button on and off //
void Simon::blinkRedButtonOn()
{
    ui->redButton->setStyleSheet("background-color:white");
    ui->yellowButton->setStyleSheet("background-color:white");
    ui->greenButton->setStyleSheet("background-color:white");
    ui->blueButton->setStyleSheet("background-color:white");
    ui->redButton->setStyleSheet("background-color:red");
}


void Simon::blinkGreenButtonOn()
{
    ui->redButton->setStyleSheet("background-color:white");
    ui->yellowButton->setStyleSheet("background-color:white");
    ui->greenButton->setStyleSheet("background-color:white");
    ui->blueButton->setStyleSheet("background-color:white");
    ui->greenButton->setStyleSheet("background-color:green");

}

void Simon::blinkBlueButtonOn()
{
    ui->redButton->setStyleSheet("background-color:white");
    ui->yellowButton->setStyleSheet("background-color:white");
    ui->greenButton->setStyleSheet("background-color:white");
    ui->blueButton->setStyleSheet("background-color:white");
    ui->blueButton->setStyleSheet("background-color:blue");

}

void Simon::blinkYellowButtonOn()
{
    ui->redButton->setStyleSheet("background-color:white");
    ui->yellowButton->setStyleSheet("background-color:white");
    ui->greenButton->setStyleSheet("background-color:white");
    ui->blueButton->setStyleSheet("background-color:white");
    ui->yellowButton->setStyleSheet("background-color:yellow");

}

void Simon::blinkRedButtonOff()
{
    ui->redButton->setStyleSheet("background-color:white");
}

void Simon::blinkGreenButtonOff()
{
    ui->greenButton->setStyleSheet("background-color:white");
}

void Simon::blinkBlueButtonOff()
{
    ui->blueButton->setStyleSheet("background-color:white");
}

void Simon::blinkYellowButtonOff()
{
    ui->yellowButton->setStyleSheet("background-color:white");
}
