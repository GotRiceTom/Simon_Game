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

    //give the progress bar a min and man
    // you can get the current value from the progress by calling
    // progressBar.value()s
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);



}

Simon::~Simon()
{
    delete ui;
}

void Simon::keyPressEvent(QKeyEvent *event){
    //all the keys are match to the numpad arrow
    //
    //check key press works
    if(event->key() == Qt::Key_8){
        ui->redButton->setStyleSheet("background-color:red");
        ui->progressBar->setValue(ui->progressBar->value() + 1);
    }
    //check key press works
    if(event->key() == Qt::Key_4){
        ui->yellowButton->setStyleSheet("background-color:yellow");
    }
    //check key press works
    if(event->key() == Qt::Key_2){
        ui->blueButton->setStyleSheet("background-color:blue");

    }
    //check key press works
    if(event->key() == Qt::Key_6){
        ui->greenButton->setStyleSheet("background-color:green");
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
