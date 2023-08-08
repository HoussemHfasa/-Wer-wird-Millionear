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
#include <Frage.h>
#include <GameSession.h>

#include <iostream>
using namespace std ;


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
   /* Answer1 = ui->Answer1_4;
    Answer2 = ui->Answer2;
    Answer3 = ui->Answer3;
    Answer4 = ui->Answer4;
    getFrage = ui->getFrage;

    // Verknüpfung des Start-Buttons mit dem Slot
    connect(ui->SpielStartButton, &QPushButton::clicked, this, &MainWindow::on_SpielStartButton_clicked);*/
    input_nickname = ui->input_nickname;

   /* comboBox_Kategorie = new QComboBox(this);
    comboBox_Kategorie->addItem("Option 1");
    comboBox_Kategorie->addItem("Option 2");
    comboBox_Kategorie->addItem("Option 3");*/
    //comboBox_Schwierigkeitsgrad
    comboBox_Kategorie = new QComboBox(this);
    comboBox_Kategorie->addItem("Allgemein");
    comboBox_Kategorie->addItem("Sport");
    comboBox_Kategorie->addItem("Wissenschaft");
    comboBox_Kategorie->addItem("Kunst und Kultur");
    comboBox_Kategorie->addItem("Geschichte");

    comboBox_Schwierigkeitsgrad = new QComboBox(this);
    comboBox_Schwierigkeitsgrad->addItem("Einfach");
    comboBox_Schwierigkeitsgrad->addItem("Mittelschwer");
    comboBox_Schwierigkeitsgrad->addItem("Schwer");
    connect(ui->comboBox_Kategorie, SIGNAL(currentIndexChanged(QString)), this, SLOT(onCategoryChanged(QString)));


    connect(ui->comboBox_Schwierigkeitsgrad, SIGNAL(currentIndexChanged(QString)), this, SLOT(onDifficultyChanged(QString)));

}


MainWindow::~MainWindow()
{
    delete ui;
    playerModel = new QStandardItemModel(this);

}

void MainWindow::on_StartButton_clicked()
{
    // Switch to AnmeldenSeite
    ui->stackedWidget->setCurrentWidget(ui->AnmeldenSeite);
}
void MainWindow::on_BestenlisteButton_clicked()
{
    cout<<" ya nimmmm";
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

void MainWindow::onCategoryChanged(QString category) {
    std::cout << category.toStdString() << std::endl;
}

void MainWindow::onDifficultyChanged(QString difficulty) {
    std::cout << difficulty.toStdString() << std::endl;
}
void MainWindow::on_SpielStartButton_clicked()
{

    std::string nickname = input_nickname->text().toStdString();

    // Create a Player object with the entered nickname
    Player player(nickname);

    QString category = ui->comboBox_Kategorie->currentText();
    onCategoryChanged(category);

    QString difficulty = ui->comboBox_Schwierigkeitsgrad->currentText();
    onDifficultyChanged(difficulty);

    ui->stackedWidget->setCurrentWidget(ui->SpielSeite);

}

void MainWindow::on_Answer1_4_clicked()
{
   /* Player player("yassin");
    GameSession gameSession(player);

    // Starte das Spiel und erhalte die nächste Frage
    gameSession.starteSpiel();
    Frage aktuelleFrage = gameSession.getAktuelleFrage();

    // Zeige die Frage auf dem Label an
    getFrage->setText(QString::fromStdString(aktuelleFrage.getFrage()));

    // Zeige die Antworten auf den Buttons an
    vector<string> antworten = aktuelleFrage.getAntworten();
    Answer1->setText(QString::fromStdString(antworten[0]));
    Answer2->setText(QString::fromStdString(antworten[1]));
    Answer3->setText(QString::fromStdString(antworten[2]));
    Answer4->setText(QString::fromStdString(antworten[3]));*/

}
void MainWindow::Combobox()
{
   /*  QString selectedOption1 = comboBox_Kategorie->currentText();
    cout <<selectedOption1.toStdString();*/

}



