#include "simon.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Simon* w = new Simon(new Model());
    w->show();

    return a.exec();
}
