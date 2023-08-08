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
#include <lifelines.h>
#include <iostream>
using namespace std ;

Lifeline lifelines;

// ...

// Wenn der "50:50" Button geklickt wird
void MainWindow::on_fiftyFifty_clicked()
{
    // Rufe die fiftyFifty-Funktion der Lifeline auf
    lifelines.fiftyFifty(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

    // Leere zwei Buttons mit falschen Antworten
    vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();

    // Zufällige Auswahl von zwei falschen Antworten
    int richtigeAntwortIndex = fragen[aktuelleFrageIndex].getRichtigeAntwort() - 'A';
    vector<int> falscheAntwortIndizes;
    for (int i = 0; i < antworten.size(); i++) {
        if (i != richtigeAntwortIndex) {
            falscheAntwortIndizes.push_back(i);
        }
    }

    random_shuffle(falscheAntwortIndizes.begin(), falscheAntwortIndizes.end());

    // Leere die Texte der ausgewählten falschen Antworten
    ui->Answer1_4->setText("");
    ui->Answer2->setText("");
    ui->Answer3->setText("");
    ui->Answer4->setText("");

    if (!falscheAntwortIndizes.empty()) {
        ui->Answer1_4->setText(QString::fromStdString(antworten[falscheAntwortIndizes[0]]));
    }
    if (falscheAntwortIndizes.size() > 1) {
        ui->Answer2->setText(QString::fromStdString(antworten[falscheAntwortIndizes[1]]));
    }
}

// Wenn der "Publikum" Button geklickt wird
void MainWindow::on_audience_clicked()
{
    // Rufe die audience-Funktion der Lifeline auf
    lifelines.audience(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

    vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
    // Aktualisiere die Anzeige für den Publikumsjoker
    vector<int> stimmenProzent = lifelines.getAudienceStimmenProzent();
    ui->Answer1_4->setText(QString::fromStdString(antworten[0]) + " - " + QString::number(stimmenProzent[0]) + "%");
    ui->Answer2->setText(QString::fromStdString(antworten[1]) + " - " + QString::number(stimmenProzent[1]) + "%");
    ui->Answer3->setText(QString::fromStdString(antworten[2]) + " - " + QString::number(stimmenProzent[2]) + "%");
    ui->Answer4->setText(QString::fromStdString(antworten[3]) + " - " + QString::number(stimmenProzent[3]) + "%");

    // Deaktiviere den Button für den Publikumsjoker
    ui->audience->setEnabled(false);
}




// Wenn der "Telefon" Button geklickt wird
void MainWindow::on_phone_clicked()
{
    // Rufe die phone-Funktion der Lifeline auf
    lifelines.phone(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

    // Markiere die Antwort des Freundes auf den Buttons visuell
    string freundRat = lifelines.getPhoneAntwort();
    cout <<freundRat<<endl;

    if (freundRat == "A") {
        ui->Answer1_4->setStyleSheet("color: green;");
    } else if (freundRat == "B") {
        ui->Answer2->setStyleSheet("color: green;");
    } else if (freundRat == "C") {
        ui->Answer3->setStyleSheet("color: green;");
    } else if (freundRat == "D") {
        ui->Answer4->setStyleSheet("color: green;");
    }
    // Hier könntest du die Anzeige für den Telefonjoker aktualisieren, z.B. den Button deaktivieren
}

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

    connect(ui->Answer1_4, &QPushButton::clicked, this, &MainWindow::on_Answer1_4_clicked);
    connect(ui->Answer2, &QPushButton::clicked, this, &MainWindow::on_Answer2_clicked);
    connect(ui->Answer3, &QPushButton::clicked, this, &MainWindow::on_Answer3_clicked);
    connect(ui->Answer4, &QPushButton::clicked, this, &MainWindow::on_Answer4_clicked);

    comboBox_Kategorie = new QComboBox(this);
    comboBox_Kategorie->addItem("allgemein");
    comboBox_Kategorie->addItem("Sport");
    comboBox_Kategorie->addItem("Wissenschaft");
    comboBox_Kategorie->addItem("Kunst und Kultur");
    comboBox_Kategorie->addItem("Geschichte");

    comboBox_Schwierigkeitsgrad = new QComboBox(this);
    comboBox_Schwierigkeitsgrad->addItem("einfach");
    comboBox_Schwierigkeitsgrad->addItem("mittelschwer");
    comboBox_Schwierigkeitsgrad->addItem("schwer");
    connect(ui->comboBox_Kategorie, SIGNAL(currentIndexChanged(QString)), this, SLOT(onCategoryChanged(QString)));


    connect(ui->comboBox_Schwierigkeitsgrad, SIGNAL(currentIndexChanged(QString)), this, SLOT(onDifficultyChanged(QString)));
    // Connect the answer buttons to handleAnswerClick
    connect(ui->Answer1_4, &QPushButton::clicked, this, [=]() { handleAnswerClick('A'); });
    connect(ui->Answer2, &QPushButton::clicked, this, [=]() { handleAnswerClick('B'); });
    connect(ui->Answer3, &QPushButton::clicked, this, [=]() { handleAnswerClick('C'); });
    connect(ui->Answer4, &QPushButton::clicked, this, [=]() { handleAnswerClick('D'); });

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

    GameSession Spiel(player);
    //Spiel.vorbereiteteFragen(difficulty.toStdString(),category.toStdString());
    fragen = Spiel.vorbereiteteFragen(difficulty.toStdString(),category.toStdString());

    // Spiel.vorbereiteteFragen("einfach","Geschichte");

    vector<string> antworten = fragen[0].getAntworten();
    ui->getFrage->setText(QString::fromStdString(fragen[0].getFrage()));
    ui->Answer1_4->setText(QString::fromStdString(antworten[0]));
    ui->Answer2->setText(QString::fromStdString(antworten[1]));
    ui->Answer3->setText(QString::fromStdString(antworten[2]));
    ui->Answer4->setText(QString::fromStdString(antworten[3]));

    // Store the index of the current question
    aktuelleFrageIndex = 0;



    ui->stackedWidget->setCurrentWidget(ui->SpielSeite);
}

void MainWindow::handleAnswerClick(char selectedAnswer)
{
    int Fragenanzahl=fragen.size();

    const Frage& aktuelleFrage = fragen[aktuelleFrageIndex];

    if (aktuelleFrage.istAntwortKorrekt(selectedAnswer)) {
        // User's answer is correct
        //
        aktuelleFrageIndex+=1;
        cout<<aktuelleFrageIndex <<endl;
        cout<<fragen[aktuelleFrageIndex].getFrage()<<endl;
        cout<<fragen[aktuelleFrageIndex].getRichtigeAntwort()<<endl;
        cout<<fragen.size()<<endl;


        if (aktuelleFrageIndex < Fragenanzahl) {
            vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
            ui->getFrage->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getFrage()));
            ui->Answer1_4->setText(QString::fromStdString(antworten[0]));
            ui->Answer2->setText(QString::fromStdString(antworten[1]));
            ui->Answer3->setText(QString::fromStdString(antworten[2]));
            ui->Answer4->setText(QString::fromStdString(antworten[3]));
        }
        else if (aktuelleFrageIndex==Fragenanzahl) {
            // End of the game
            // Handle accordingly, e.g., show final score
            ui->getFrage->setText("Herzlichen Glückwunsch! Du hast alle Fragen beantwortet.");
            ui->Answer1_4->setText("");
            ui->Answer2->setText("");
            ui->Answer3->setText("");
            ui->Answer4->setText("");
        }
    }

     else {
        // User's answer is incorrect
        // Handle accordingly, e.g., show incorrect message
        ui->getFrage->setText("Leider falsch. Das Spiel ist vorbei.");
        ui->Answer1_4->setText("");
        ui->Answer2->setText("");
        ui->Answer3->setText("");
        ui->Answer4->setText("");
    }
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
    // Retrieve the selected answer from the clicked button
    char selectedAnswer = 'A'; // For example, 'A' corresponds to Answer1_4 button
    // You need to update this based on the clicked button.
/*
    // Get the current question from the game session
    Frage aktuelleFrage = Spiel.getAktuelleFrage();

    // Check if the selected answer is correct
    if (aktuelleFrage.istAntwortKorrekt(selectedAnswer)) {
        // Update the player's score
        int gewinn = gewinnstufen[aktuelleFrageIndex]; // Gewinnstufe für die aktuelle Frage
        cout << "Richtig! Du erhältst " << gewinn << " Punkte.\n";
                                                     player.updateScore(player.getCurrentScore() + gewinn);

        // Proceed to the next question or end the game
        if (aktuelleFrageIndex < fragen.size() - 1) {
            aktuelleFrageIndex++;
            aktuelleFrage = Spiel.getAktuelleFrage();
            ui->getFrage->setText(QString::fromStdString(aktuelleFrage.getFrage()));
            // Update the answer buttons' text with the new answers
            // ...
        } else {
            // All questions answered, end the game
            beendeSpiel();
        }
    } else {
        // Incorrect answer, end the game
        cout << "Leider falsch. Das Spiel ist vorbei.\n";
        beendeSpiel();
    }
}*/

}


void MainWindow::on_Answer2_clicked()
{

}


void MainWindow::on_Answer3_clicked()
{

}


void MainWindow::on_Answer4_clicked()
{

}

