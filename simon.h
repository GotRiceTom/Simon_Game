#ifndef SIMON_H
#define SIMON_H

#include <QWidget>

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
};

#endif // SIMON_H
