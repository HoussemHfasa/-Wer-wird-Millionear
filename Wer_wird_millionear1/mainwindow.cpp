#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //creating database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={MySQL ODBC 8.1 Unicode Driver};SERVER=localhost;DATABASE=werwirdmillionaer;USER=rama;PASSWORD=12345;");

    if(db.open())
    {
        cout << "Database connected" << endl;
    }
    else {
        cout << "Database connect failed" << endl;
        cout << db.lastError().text().toStdString() << endl;
    }
}

