#ifndef LOSE_H
#define LOSE_H

#include <QDialog>

namespace Ui {
class lose;
}

class lose : public QDialog
{
    Q_OBJECT

public:
    explicit lose(QWidget *parent = nullptr);
    ~lose();

private slots:
    void on_pushButton_clicked();

private:
    Ui::lose *ui;
};

#endif // LOSE_H
