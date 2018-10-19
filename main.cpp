#include "simon.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Simon w;
    w.show();

    return a.exec();
}
