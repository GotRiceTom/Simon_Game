#include "simon.h"
#include "ui_simon.h"
#include <QKeyEvent>
#include <QApplication>
#include <iostream>

Simon::Simon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simon)
{
    ui->setupUi(this);

    //set up the model for Simon
    SimonModel = new Model();

    //give the progress bar a min and man
    // you can get the current value from the progress by calling
    // progressBar.value()s
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(5);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),this,SLOT(blink_Pattern()));


    isButtonBlinked = true;


    //connecting the StartButton's signal 'clicked' to the function slot startButton_clicked
   connect(ui->StartButton, SIGNAL(clicked(bool)), this, SLOT(startButton_clicked()));

   connect(ui->redButton,SIGNAL(clicked(bool)),this,SLOT(redButton_clicked()));
   connect(ui->yellowButton,SIGNAL(clicked(bool)),this,SLOT(yellowButton_clicked()));
   connect(ui->blueButton,SIGNAL(clicked(bool)),this,SLOT(blueButton_clicked()));
   connect(ui->greenButton,SIGNAL(clicked(bool)),this,SLOT(greenButton_clicked()));


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
        ui->progressBar->setValue(ui->progressBar->value() + 1);
    }

    if(event->key() == Qt::Key_4){
        ui->yellowButton->setStyleSheet("background-color:yellow");
        ui->progressBar->setValue(ui->progressBar->value() + 1);
    }

    if(event->key() == Qt::Key_2){
        ui->blueButton->setStyleSheet("background-color:blue");
        ui->progressBar->setValue(ui->progressBar->value() + 1);

    }

    if(event->key() == Qt::Key_6){
        ui->greenButton->setStyleSheet("background-color:green");
        ui->progressBar->setValue(ui->progressBar->value() + 1);
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

void Simon::startButton_clicked(){
    std::cout<< "Start Button Pressed" << std::endl;
    timer->start(500);
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

// this method is called when the start button is pressed
// or it's the AI turn
// This method task is to blink the AI pattern from
// starting level to the current level
void Simon::blink_Pattern()
{
    if(isButtonBlinked){
        ui->redButton->setStyleSheet("background-color : white");
        isButtonBlinked = false;

    }else
    {
         ui->redButton->setStyleSheet("background-color : red");
         isButtonBlinked = true;
         timer->stop();
    }

    std::cout<< "Timer is calling the blink_Pattern"<< std::endl;


}

void Simon::blink_redButton()
{

}

void Simon::blink_blueButton()
{

}

void Simon::blink_greenButton()
{

}

void Simon::blink_yellowButton()
{

}
