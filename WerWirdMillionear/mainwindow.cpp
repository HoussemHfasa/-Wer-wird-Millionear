#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Display the logo
    QPixmap pix(":/img/img/logo.png");
    ui->Logo_Label->setPixmap(pix);


    QPixmap pix2(":/img/img/logo.png");
    ui->LogoSpiel->setPixmap(pix2);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartButton_clicked()
{
    // Switch to AnmeldenSeite
    ui->stackedWidget->setCurrentWidget(ui->AnmeldenSeite);
}

void MainWindow::on_BestenlisteButton_clicked()
{
    // Switch to BestenlisteSeite
    ui->stackedWidget->setCurrentWidget(ui->BestenlisteSeite);
}

void MainWindow::on_SpielStartButton_clicked()
{
    QLineEdit *input_name = qobject_cast<QLineEdit *>(sender());
    if (!input_name)
        return;

    QString nickname = input_name->text();

    // Insert the name into the "benutzer" table
    QSqlQuery query;
    query.prepare("INSERT INTO benutzer (nickname) VALUES (:nickname)");
    query.bindValue(":nickname", nickname);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
    } else {
        qDebug() << "Name inserted successfully.";
    }


     ui->stackedWidget->setCurrentWidget(ui->SpielSeite);


}


void MainWindow::on_Answer1_4_clicked()
{

}

