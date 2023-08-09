#include "win.h"
#include "ui_win.h"
#include <QProcess>


win::win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
}

win::~win()
{
    delete ui;
}

void win::on_pushButton_clicked()
{
    close();
    QProcess::startDetached(QCoreApplication::applicationFilePath());

    QCoreApplication::quit();
}

