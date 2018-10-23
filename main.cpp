/**
 * Eric Naegle and Tom Nguyen
 * CS 3505
 * Assignment 5
**/

#include "simon.h"
#include "model.h"
#include <QApplication>

/**
 * @brief This main creates the Model and View, and shows the ui
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Simon* w = new Simon(new Model());
    w->show();

    return a.exec();
}
