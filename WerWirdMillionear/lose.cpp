#include "lose.h"
#include "ui_lose.h"
#include <QProcess>


lose::lose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lose)
{
    ui->setupUi(this);
}

lose::~lose()
{
    delete ui;
}

void lose::on_pushButton_clicked()
{
    close();

    QProcess::startDetached(QCoreApplication::applicationFilePath());

    QCoreApplication::quit();
}

