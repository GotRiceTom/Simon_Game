#ifndef SIMON_H
#define SIMON_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class Simon;
}

class Simon : public QWidget
{
    Q_OBJECT

public:
    explicit Simon(QWidget *parent = nullptr);
    ~Simon();

private:
    Ui::Simon *ui;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);


};

#endif // SIMON_H
