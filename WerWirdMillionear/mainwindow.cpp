#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtSql>
#include <QSqlQuery>
using namespace std ;

Lifeline lifelines;

// Wenn der "50:50" Button geklickt wird
void MainWindow::on_fiftyFifty_clicked()
{
    if (!lifelines.fiftyFiftyUsed) {
        // Lifeline "50:50" wird verwendet
        lifelines.fiftyFifty(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

        // Sammle Informationen über Antworten und richtige Antwort
        vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
        int richtigeAntwortIndex = fragen[aktuelleFrageIndex].getRichtigeAntwort() - 'A';
        vector<int> falscheAntwortIndizes;

        // Wähle zufällig zwei falsche Antwortindizes aus
        int antwortsize = antworten.size();
        for (int i = 0; i < antwortsize; i++) {
            if (i != richtigeAntwortIndex) {
                falscheAntwortIndizes.push_back(i);
            }
        }

        random_shuffle(falscheAntwortIndizes.begin(), falscheAntwortIndizes.end());

        // Setze Texte der ausgewählten falschen Antworten zurück
        ui->Answer1_4->setText("");
        ui->Answer2->setText("");
        ui->Answer3->setText("");
        ui->Answer4->setText("");

        // Fülle die Texte mit den neuen Antwortmöglichkeiten
        if (!falscheAntwortIndizes.empty()) {
            ui->Answer1_4->setText(QString::fromStdString(antworten[falscheAntwortIndizes[0]]));
        }
        if (falscheAntwortIndizes.size() > 1) {
            ui->Answer2->setText(QString::fromStdString(antworten[falscheAntwortIndizes[1]]));
        }
    }
    lifelines.isFiftyFiftyUsed();
}

// Wenn der "Publikum" Button geklickt wird
void MainWindow::on_audience_clicked()
{
    if (!lifelines.audienceUsed) {
        // Lifeline "Publikum" wird verwendet
        lifelines.audience(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

        // Sammle Informationen über Antworten und Stimmenprozentsätze
        vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
        vector<int> stimmenProzent = lifelines.getAudienceStimmenProzent();

        // Aktualisiere die Anzeige für den Publikumsjoker
        ui->Answer1_4->setText(QString::fromStdString(antworten[0]) + " (" + QString::number(stimmenProzent[0]) + "%)");
        ui->Answer2->setText(QString::fromStdString(antworten[1]) + " (" + QString::number(stimmenProzent[1]) + "%)");
        ui->Answer3->setText(QString::fromStdString(antworten[2]) + " (" + QString::number(stimmenProzent[2]) + "%)");
        ui->Answer4->setText(QString::fromStdString(antworten[3]) + " (" + QString::number(stimmenProzent[3]) + "%)");
    }
    lifelines.isAudienceUsed();
}

// Wenn der "Telefon" Button geklickt wird
void MainWindow::on_phone_clicked()
{
    if (!lifelines.phoneUsed) {
        // Lifeline "Telefon" wird verwendet
        lifelines.phone(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

        // Zeige die Antwort des Freundes visuell auf den Buttons an
        string freundRat = lifelines.getPhoneAntwort();
        if (freundRat == "A") {
            ui->Answer1_4->setText(ui->Answer1_4->text() + "   (Freundrat)");
        } else if (freundRat == "B") {
            ui->Answer2->setText(ui->Answer2->text() + "   (Freundrat)");
        } else if (freundRat == "C") {
            ui->Answer3->setText(ui->Answer3->text() + "   (Freundrat)");
        } else if (freundRat == "D") {
            ui->Answer4->setText(ui->Answer4->text() + "   (Freundrat)");
        }
    }
    lifelines.isPhoneUsed();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Scores={0,100,200,300,500,1000,2000,4000,8000,16000,32000,64000,125000,250000,500000,1000000};

    ui->setupUi(this);
    e100Label = findChild<QLabel*>("E100");
    e200Label = findChild<QLabel*>("E200");
    e300Label = findChild<QLabel*>("E300");
    e500Label = findChild<QLabel*>("E500");
    e1000Label = findChild<QLabel*>("E1000");
    e2000Label = findChild<QLabel*>("E2000");
    e4000Label = findChild<QLabel*>("E4000");
    e8000Label = findChild<QLabel*>("E8000");
    e16000Label = findChild<QLabel*>("E16000");
    e32000Label = findChild<QLabel*>("E32000");
    e64000Label = findChild<QLabel*>("E64000");
    e125000Label = findChild<QLabel*>("E125000");
    e250000Label = findChild<QLabel*>("E250000");
    e500000Label = findChild<QLabel*>("E500000");
    e1000000Label = findChild<QLabel*>("E1000000");

    // Display the logo
    QPixmap pix(":/img/img/logo.png");
    ui->Logo_Label->setPixmap(pix);


    QPixmap pix2(":/img/img/logo.png");
    ui->LogoSpiel->setPixmap(pix2);
    // Create the playerModel and set it as the model for "Bestenliste" QListView
    playerModel = new QStandardItemModel(this); // Assuming you have playerModel as a member variable of MainWindow
    ui->Bestenliste->setModel(playerModel); // Assuming "Bestenliste" is the name of your QListView in the UI

    input_nickname = ui->input_nickname;

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
    cout << category.toStdString() << endl;
}

void MainWindow::onDifficultyChanged(QString difficulty) {
    cout << difficulty.toStdString() << endl;
}
void MainWindow::on_Neustart_clicked()
{
    nickname = input_nickname->text().toStdString();
    // Create a Player object with the entered nickname
    player=new Player(nickname);
    //Player player(nickname);

    QString category = ui->comboBox_Kategorie->currentText();
    onCategoryChanged(category);

    QString difficulty = ui->comboBox_Schwierigkeitsgrad->currentText();
    onDifficultyChanged(difficulty);

    GameSession Spiel(*player);
    player->updateScore(Scores[0]);
    //Spiel.vorbereiteteFragen(difficulty.toStdString(),category.toStdString());
    fragen = Spiel.vorbereiteteFragen(difficulty.toStdString(),category.toStdString());
    aktuelleFrageIndex=0;
    vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
    ui->getFrage->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getFrage()));
    ui->Answer1_4->setText(QString::fromStdString(antworten[0]));
    ui->Answer2->setText(QString::fromStdString(antworten[1]));
    ui->Answer3->setText(QString::fromStdString(antworten[2]));
    ui->Answer4->setText(QString::fromStdString(antworten[3]));
    ui->stackedWidget->setCurrentWidget(ui->SpielSeite);


}
// Wenn der "Spiel Start" Button geklickt wird
void MainWindow::on_SpielStartButton_clicked()
{
    // Holen des eingegebenen Nicknamens
    nickname = input_nickname->text().toStdString();

    // Erstellen eines Spielerobjekts mit dem eingegebenen Nicknamen
    player = new Player(nickname);

    // Ausgewählte Kategorie und Schwierigkeitsgrad abrufen
    QString category = ui->comboBox_Kategorie->currentText();
    onCategoryChanged(category);
    QString difficulty = ui->comboBox_Schwierigkeitsgrad->currentText();
    onDifficultyChanged(difficulty);

    // Neue Spielsitzung erstellen
    GameSession Spiel(*player);

    // Vorbereitete Fragen abrufen und speichern
    fragen = Spiel.vorbereiteteFragen(difficulty.toStdString(), category.toStdString());

    // Index der aktuellen Frage speichern und hervorheben
    currentscore = player->getCurrentScore();
    for (int i = 0; i < 16; i++) {
        if (Scores[i] == currentscore) {
            aktuelleFrageIndex = i;
            break;
        }
    }
    highlightReachedQuestion();

    // Fragen und Antworten in der Benutzeroberfläche anzeigen
    vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
    ui->getFrage->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getFrage()));
    ui->Answer1_4->setText(QString::fromStdString(antworten[0]));
    ui->Answer2->setText(QString::fromStdString(antworten[1]));
    ui->Answer3->setText(QString::fromStdString(antworten[2]));
    ui->Answer4->setText(QString::fromStdString(antworten[3]));

    // Zeige die Spiel-Seite in der Benutzeroberfläche an
    ui->stackedWidget->setCurrentWidget(ui->SpielSeite);
}

// Behandlung von Antwort-Klicks
void MainWindow::handleAnswerClick(char selectedAnswer)
{
    int Fragenanzahl = fragen.size();
    const Frage& aktuelleFrage = fragen[aktuelleFrageIndex];

    // Überprüfe, ob die ausgewählte Antwort korrekt ist
    if (aktuelleFrage.istAntwortKorrekt(selectedAnswer)) {
        // Aktualisiere den Index der aktuellen Frage
        aktuelleFrageIndex += 1;

        // Überprüfe, ob weitere Fragen vorhanden sind
        if (aktuelleFrageIndex < Fragenanzahl) {
            // Zeige die nächste Frage und Antworten an
            vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
            ui->getFrage->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getFrage()));
            ui->Answer1_4->setText(QString::fromStdString(antworten[0]));
            ui->Answer2->setText(QString::fromStdString(antworten[1]));
            ui->Answer3->setText(QString::fromStdString(antworten[2]));
            ui->Answer4->setText(QString::fromStdString(antworten[3]));
        }
        else if (aktuelleFrageIndex == Fragenanzahl) {
            // Ende des Spiels: Zeige den Abschlusstext an
            ui->getFrage->setText("Herzlichen Glückwunsch! Du hast alle Fragen beantwortet.");
                ui->Answer1_4->setText("");
            ui->Answer2->setText("");
            ui->Answer3->setText("");
            ui->Answer4->setText("");
        }

        // Aktualisiere den Spielerpunktestand
        player->updateScore(Scores[aktuelleFrageIndex]);
    }
    else {
        // Die ausgewählte Antwort ist falsch: Zeige entsprechende Nachricht an
        ui->getFrage->setText("Leider falsch. Das Spiel ist vorbei.");
        ui->Answer1_4->setText("");
        ui->Answer2->setText("");
        ui->Answer3->setText("");
        ui->Answer4->setText("");

        // Setze Spielerpunktestand zurück auf den Startwert
        player->updateScore(Scores[0]);
    }

    // Hervorhebung der erreichten Frage im Spielverlauf
    highlightReachedQuestion();
}

void MainWindow::on_Zurueckstartseite_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Startseite);
}


void MainWindow::on_spielanleitungButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->SpielanleitungPage);
}

void MainWindow::highlightReachedQuestion() {
    QLabel* labels[] = {
        e100Label, e200Label, e300Label, e500Label,
        e1000Label, e2000Label, e4000Label, e8000Label,
        e16000Label, e32000Label, e64000Label, e125000Label,
        e250000Label, e500000Label, e1000000Label
    };

    for (int i = 0; i < aktuelleFrageIndex && i < static_cast<int>(sizeof(labels) / sizeof(labels[0])); ++i) {
        if (i < 4) {
            labels[i]->setStyleSheet("background-color: #90EE90");
        } else if (i < 10) {
            labels[i]->setStyleSheet("background-color: #FFFF00");
        } else if (i < 14) {
            labels[i]->setStyleSheet("background-color: #FFA500");
        } else {
            labels[i]->setStyleSheet("background-color: #FF0000");
        }
    }
}
