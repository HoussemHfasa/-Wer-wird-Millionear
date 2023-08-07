#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <player.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include<QProgressDialog>

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
void MainWindow::refreshList() {
   /* // Show progress dialog
    QProgressDialog progress("Loading...", "Cancel", 0, 0, this);
    progress.show();

    // Clear previous data
    playerModel->clear();

    // Query database
    QSqlQuery query;
    query.prepare("SELECT nickname, highscore FROM benutzer");

    if(query.exec()) {

        // Add items for each row
        while(query.next()) {
            QString nickname = query.value(0).toString();
            int score = query.value(1).toInt();

            QStandardItem *item = new QStandardItem(nickname + " : " + QString::number(score));
            playerModel->appendRow(item);
        }

    } else {
        // Show error
    }

    // Set model on list view
    ui->listView->setModel(playerModel);

    // Hide progress
    progress.hide();*/
    playerModel->clear();

    // Create item with test string
    QStandardItem *item = new QStandardItem("3asba");

    // Add to model
    playerModel->appendRow(item);

    // Set model on list view
    ui->listView->setModel(playerModel);

}

MainWindow::~MainWindow()
{
    delete ui;
    playerModel = new QStandardItemModel(this);

    // Connect signal to refresh slot
    connect(ui->listView, &QListView::indexesMoved, this, &MainWindow::refreshList);

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


void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{
   /*  playerModel->clear();

     QSqlQuery query;
     query.prepare("SELECT nickname, highscore FROM benutzer");

     if(query.exec()) {
         while(query.next()) {
             QString nickname = query.value(0).toString();
             int highscore = query.value(1).toInt();

             // create item with nickname and highscore
             QStandardItem *item = new QStandardItem(nickname + ": " + QString::number(highscore));

             // add item to model
             playerModel->appendRow(item);
         }
     }
     if(!query.exec()) {
         qDebug() << "Error:" << query.lastError();
     }
     qDebug() << "Model row count:" << playerModel->rowCount();
     ui->listView->setModel(playerModel);
     ui->listView->update();*/
     playerModel->clear();

     // Create item with test string
     QStandardItem *item = new QStandardItem("3asba");

     // Add to model
     playerModel->appendRow(item);

     // Set model on list view
     ui->listView->setModel(playerModel);
}

