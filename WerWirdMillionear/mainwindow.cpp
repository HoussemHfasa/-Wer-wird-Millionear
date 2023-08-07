#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

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
     ui->stackedWidget->setCurrentWidget(ui->SpielSeite);
}


void MainWindow::on_Answer1_4_clicked()
{

}

