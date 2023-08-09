#ifndef WIN_H
#define WIN_H

#include <QDialog>

namespace Ui {
class win;
}

class win : public QDialog
{
    Q_OBJECT

public:
    explicit win(QWidget *parent = nullptr);
    ~win();

private slots:
    void on_pushButton_clicked();

private:
    Ui::win *ui;
};

#endif // WIN_H
