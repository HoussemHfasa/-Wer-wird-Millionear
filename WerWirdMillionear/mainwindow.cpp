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
        // Rufe die fiftyFifty-Funktion der Lifeline auf
        lifelines.fiftyFifty(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

        // Leere zwei Buttons mit falschen Antworten
        vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();

        // Zufällige Auswahl von zwei falschen Antworten
        int richtigeAntwortIndex = fragen[aktuelleFrageIndex].getRichtigeAntwort() - 'A';
        vector<int> falscheAntwortIndizes;
        int antwortsize=antworten.size();
        for (int i = 0; i < antwortsize; i++) {
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
    lifelines.isFiftyFiftyUsed();

}

// Wenn der "Publikum" Button geklickt wird
void MainWindow::on_audience_clicked()
{
    if (!lifelines.audienceUsed) {
        // Rufe die audience-Funktion der Lifeline auf
        lifelines.audience(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

        vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
        // Aktualisiere die Anzeige für den Publikumsjoker
        vector<int> stimmenProzent = lifelines.getAudienceStimmenProzent();
        ui->Answer1_4->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getAntworten()[0]) +
                               " (" + QString::number(stimmenProzent[0]) + "%)");
        ui->Answer2->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getAntworten()[1]) +
                             " (" + QString::number(stimmenProzent[1]) + "%)");
        ui->Answer3->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getAntworten()[2]) +
                             " (" + QString::number(stimmenProzent[2]) + "%)");
        ui->Answer4->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getAntworten()[3]) +
                             " (" + QString::number(stimmenProzent[3]) + "%)");

        // Deaktiviere den Button für den Publikumsjoker
        //ui->audience->setEnabled(false);
    }
    lifelines.isAudienceUsed();
}




// Wenn der "Telefon" Button geklickt wird
void MainWindow::on_phone_clicked()
{
    if (!lifelines.phoneUsed) {
        // Rufe die phone-Funktion der Lifeline auf
        lifelines.phone(fragen[aktuelleFrageIndex].getAntworten(), fragen[aktuelleFrageIndex].getRichtigeAntwort());

        // Markiere die Antwort des Freundes auf den Buttons visuell
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
    std::cout << category.toStdString() << std::endl;
}

void MainWindow::onDifficultyChanged(QString difficulty) {
    std::cout << difficulty.toStdString() << std::endl;
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
void MainWindow::on_SpielStartButton_clicked()
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
    //Spiel.vorbereiteteFragen(difficulty.toStdString(),category.toStdString());
    fragen = Spiel.vorbereiteteFragen(difficulty.toStdString(),category.toStdString());

    // Store the index of the current question
    currentscore=player->getCurrentScore();
    cout<<currentscore<<endl;
    for(int i = 0; i < 16; i++) {
        if(Scores[i] == currentscore) {
            aktuelleFrageIndex=i;
            break ;
        }
    }
    highlightReachedQuestion();
    vector<string> antworten = fragen[aktuelleFrageIndex].getAntworten();
    ui->getFrage->setText(QString::fromStdString(fragen[aktuelleFrageIndex].getFrage()));
    ui->Answer1_4->setText(QString::fromStdString(antworten[0]));
    ui->Answer2->setText(QString::fromStdString(antworten[1]));
    ui->Answer3->setText(QString::fromStdString(antworten[2]));
    ui->Answer4->setText(QString::fromStdString(antworten[3]));
    ui->stackedWidget->setCurrentWidget(ui->SpielSeite);
}

void MainWindow::handleAnswerClick(char selectedAnswer)
{
    int Fragenanzahl=fragen.size();

    const Frage& aktuelleFrage = fragen[aktuelleFrageIndex];


    if (aktuelleFrage.istAntwortKorrekt(selectedAnswer)) {
        aktuelleFrageIndex+=1;
        cout<<aktuelleFrageIndex <<endl;

        cout<<Fragenanzahl<<endl;
        if (aktuelleFrageIndex < Fragenanzahl) {
            cout<<fragen[aktuelleFrageIndex].getFrage()<<endl;
            cout<<fragen[aktuelleFrageIndex].getRichtigeAntwort()<<endl;
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
        player->updateScore(Scores[aktuelleFrageIndex]);
    }
    else {
        // User's answer is incorrect
        // Handle accordingly, e.g., show incorrect message
        ui->getFrage->setText("Leider falsch. Das Spiel ist vorbei.");
        ui->Answer1_4->setText("");
        ui->Answer2->setText("");
        ui->Answer3->setText("");
        ui->Answer4->setText("");
        player->updateScore(Scores[0]);

    }

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
