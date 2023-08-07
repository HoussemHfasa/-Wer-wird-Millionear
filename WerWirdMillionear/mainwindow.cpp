#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <player.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include<QProgressDialog>
#include <QLineEdit>
#include <QtSql>
#include <QListView>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QFont>
#include <QBrush>


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
    // Create the playerModel and set it as the model for "Bestenliste" QListView
    playerModel = new QStandardItemModel(this); // Assuming you have playerModel as a member variable of MainWindow
    ui->Bestenliste->setModel(playerModel); // Assuming "Bestenliste" is the name of your QListView in the UI






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
    ui->Bestenliste->setModel(playerModel);

}

MainWindow::~MainWindow()
{
    delete ui;
    playerModel = new QStandardItemModel(this);

    // Connect signal to refresh slot
    connect(ui->Bestenliste, &QListView::indexesMoved, this, &MainWindow::refreshList);

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

    // Prepare the query to fetch data from the database
    QSqlQuery query;
    query.prepare("SELECT nickname, highscore FROM benutzer");

    if (query.exec()) {
        // Clear the existing data from the playerModel before adding new data
        playerModel->clear();

        while (query.next()) {
            QString nickname = query.value(0).toString();
            int highscore = query.value(1).toInt();

            // create item with nickname and highscore
            QStandardItem *item = new QStandardItem(nickname + ": " + QString::number(highscore));

            // Set the text alignment to center for the item
            item->setTextAlignment(Qt::AlignCenter);

            // add item to model
            playerModel->appendRow(item);
        }
    } else {
        qDebug() << "Error:" << query.lastError();
    }

    // Add a header item at the top of the list
    QList<QStandardItem*> headerItems;
    QStandardItem *headerItem = new QStandardItem("Nickname: Highscore");

    // Set text color to red for the header item
    QBrush redBrush(Qt::red);
    headerItem->setData(redBrush, Qt::ForegroundRole);
    headerItem->setTextAlignment(Qt::AlignCenter);

    headerItems.append(headerItem);
    playerModel->insertRow(0, headerItems); // Insert at the first row (top of the list)

    // Set the QListView to be read-only (disable item editing)
    ui->Bestenliste->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
     ui->Bestenliste->setModel(playerModel);
}

