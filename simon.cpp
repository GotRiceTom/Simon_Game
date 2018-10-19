#include "simon.h"
#include "ui_simon.h"

Simon::Simon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simon)
{
    ui->setupUi(this);
}

Simon::~Simon()
{
    delete ui;
}
