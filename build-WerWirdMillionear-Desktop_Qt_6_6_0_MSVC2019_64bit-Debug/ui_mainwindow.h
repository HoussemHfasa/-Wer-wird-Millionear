/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *BestenlisteSeite;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_4;
    QListView *listView;
    QSpacerItem *verticalSpacer_7;
    QWidget *AnmeldenSeite;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_5;
    QPushButton *SpielStartButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QWidget *SpielSeite;
    QLabel *label_2;
    QPushButton *Answer2;
    QPushButton *Answer3;
    QPushButton *Answer4;
    QLabel *LogoSpiel;
    QPushButton *Answer1_4;
    QLabel *label_22;
    QPushButton *pushButton_6;
    QLabel *label_15;
    QLabel *E200;
    QLabel *label_16;
    QLabel *label_21;
    QLabel *label_20;
    QLabel *E100;
    QPushButton *pushButton_5;
    QLabel *label_19;
    QLabel *label_11;
    QLabel *E300;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_13;
    QLabel *label_10;
    QPushButton *pushButton_7;
    QLabel *label_18;
    QLabel *label_12;
    QWidget *Startseite;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *Logo_Label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *StartButton;
    QPushButton *BestenlisteButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1207, 622);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 14, 35);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        BestenlisteSeite = new QWidget();
        BestenlisteSeite->setObjectName("BestenlisteSeite");
        verticalLayout_4 = new QVBoxLayout(BestenlisteSeite);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_6);

        label_4 = new QLabel(BestenlisteSeite);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("background-color: #4B8A90;\n"
"border: none;\n"
"color: white;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;"));

        verticalLayout_4->addWidget(label_4);

        listView = new QListView(BestenlisteSeite);
        listView->setObjectName("listView");

        verticalLayout_4->addWidget(listView);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_7);

        stackedWidget->addWidget(BestenlisteSeite);
        AnmeldenSeite = new QWidget();
        AnmeldenSeite->setObjectName("AnmeldenSeite");
        verticalLayout = new QVBoxLayout(AnmeldenSeite);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(AnmeldenSeite);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"color: white;\n"
""));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(AnmeldenSeite);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: none;\n"
"color: Black;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
""));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_5);

        SpielStartButton = new QPushButton(AnmeldenSeite);
        SpielStartButton->setObjectName("SpielStartButton");
        SpielStartButton->setCursor(QCursor(Qt::PointingHandCursor));
        SpielStartButton->setStyleSheet(QString::fromUtf8("background-color: #4B8A90;\n"
"border: none;\n"
"color: white;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;"));

        verticalLayout->addWidget(SpielStartButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_4);

        stackedWidget->addWidget(AnmeldenSeite);
        SpielSeite = new QWidget();
        SpielSeite->setObjectName("SpielSeite");
        label_2 = new QLabel(SpielSeite);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 190, 731, 91));
        label_2->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: none;\n"
"color: Black;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
""));
        Answer2 = new QPushButton(SpielSeite);
        Answer2->setObjectName("Answer2");
        Answer2->setGeometry(QRect(560, 310, 221, 81));
        Answer2->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: none;\n"
"color: Black;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 25px;\n"
""));
        Answer3 = new QPushButton(SpielSeite);
        Answer3->setObjectName("Answer3");
        Answer3->setGeometry(QRect(160, 440, 221, 81));
        Answer3->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: none;\n"
"color: Black;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 25px;\n"
""));
        Answer4 = new QPushButton(SpielSeite);
        Answer4->setObjectName("Answer4");
        Answer4->setGeometry(QRect(560, 430, 221, 81));
        Answer4->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: none;\n"
"color: Black;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 25px;\n"
""));
        LogoSpiel = new QLabel(SpielSeite);
        LogoSpiel->setObjectName("LogoSpiel");
        LogoSpiel->setGeometry(QRect(230, 40, 521, 131));
        LogoSpiel->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        LogoSpiel->setScaledContents(true);
        Answer1_4 = new QPushButton(SpielSeite);
        Answer1_4->setObjectName("Answer1_4");
        Answer1_4->setGeometry(QRect(160, 320, 221, 71));
        Answer1_4->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: none;\n"
"color: Black;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 25px;\n"
""));
        label_22 = new QLabel(SpielSeite);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(890, 10, 201, 551));
        label_22->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: Black;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;"));
        pushButton_6 = new QPushButton(SpielSeite);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(1020, 40, 61, 51));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("back-ground-color: transparent;\n"
"border-image:url(:/img/call.png);\n"
"border:none;\n"
"background-repeat:none;"));
        label_15 = new QLabel(SpielSeite);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(910, 270, 161, 37));
        label_15->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        E200 = new QLabel(SpielSeite);
        E200->setObjectName("E200");
        E200->setGeometry(QRect(910, 480, 161, 37));
        QFont font1;
        font1.setBold(true);
        E200->setFont(font1);
        E200->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        E200->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_16 = new QLabel(SpielSeite);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(910, 240, 161, 37));
        label_16->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_21 = new QLabel(SpielSeite);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(910, 90, 161, 37));
        label_21->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_20 = new QLabel(SpielSeite);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(910, 120, 161, 37));
        label_20->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        E100 = new QLabel(SpielSeite);
        E100->setObjectName("E100");
        E100->setGeometry(QRect(910, 510, 161, 37));
        E100->setFont(font1);
        E100->setAutoFillBackground(false);
        E100->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        E100->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_5 = new QPushButton(SpielSeite);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(960, 30, 51, 61));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("back-ground-color: transparent;\n"
"border-image:url(:/img/half.png);\n"
"border:none;\n"
"background-repeat:none;"));
        label_19 = new QLabel(SpielSeite);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(910, 150, 161, 37));
        label_19->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(SpielSeite);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(910, 390, 161, 37));
        label_11->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        E300 = new QLabel(SpielSeite);
        E300->setObjectName("E300");
        E300->setGeometry(QRect(910, 450, 161, 37));
        E300->setFont(font1);
        E300->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        E300->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_14 = new QLabel(SpielSeite);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(910, 300, 161, 37));
        label_14->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(SpielSeite);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(910, 210, 161, 38));
        label_17->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_13 = new QLabel(SpielSeite);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(910, 330, 161, 37));
        label_13->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(SpielSeite);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(910, 420, 161, 37));
        label_10->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_7 = new QPushButton(SpielSeite);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(900, 30, 51, 61));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("back-ground-color: transparent;\n"
"border-image:url(:/img/img/people.png);\n"
"border:none;\n"
"background-repeat:none;"));
        label_18 = new QLabel(SpielSeite);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(910, 180, 161, 37));
        label_18->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(SpielSeite);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(910, 360, 161, 38));
        label_12->setStyleSheet(QString::fromUtf8("background-color: #473662;\n"
"border: none;\n"
"color: White;\n"
"\n"
"font-weight: bold;\n"
"\n"
""));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stackedWidget->addWidget(SpielSeite);
        Startseite = new QWidget();
        Startseite->setObjectName("Startseite");
        verticalLayout_3 = new QVBoxLayout(Startseite);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        Logo_Label = new QLabel(Startseite);
        Logo_Label->setObjectName("Logo_Label");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Logo_Label->sizePolicy().hasHeightForWidth());
        Logo_Label->setSizePolicy(sizePolicy);
        Logo_Label->setPixmap(QPixmap(QString::fromUtf8("img/logo.png")));
        Logo_Label->setScaledContents(true);

        verticalLayout_2->addWidget(Logo_Label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        StartButton = new QPushButton(Startseite);
        StartButton->setObjectName("StartButton");
        StartButton->setCursor(QCursor(Qt::PointingHandCursor));
        StartButton->setStyleSheet(QString::fromUtf8("background-color: #4B8A90;\n"
"border: none;\n"
"color: white;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;"));

        horizontalLayout_3->addWidget(StartButton);

        BestenlisteButton = new QPushButton(Startseite);
        BestenlisteButton->setObjectName("BestenlisteButton");
        BestenlisteButton->setCursor(QCursor(Qt::PointingHandCursor));
        BestenlisteButton->setStyleSheet(QString::fromUtf8("background-color: #4B8A90;\n"
"border: none;\n"
"color: white;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;"));

        horizontalLayout_3->addWidget(BestenlisteButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        stackedWidget->addWidget(Startseite);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1207, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rangtabelle", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Geben Sie Ihre Spielenname:", nullptr));
        SpielStartButton->setText(QCoreApplication::translate("MainWindow", "Beginne zu spielen", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Answer2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        Answer3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        Answer4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        LogoSpiel->setText(QString());
        Answer1_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_22->setText(QString());
        pushButton_6->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "16.000\342\202\254", nullptr));
        E200->setText(QCoreApplication::translate("MainWindow", "200\342\202\254", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "32.000\342\202\254", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "1.000.000\342\202\254", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "500.000\342\202\254", nullptr));
        E100->setText(QCoreApplication::translate("MainWindow", "100\342\202\254", nullptr));
        pushButton_5->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "250.000\342\202\254", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "1.000\342\202\254", nullptr));
        E300->setText(QCoreApplication::translate("MainWindow", "300\342\202\254", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "8.000\342\202\254", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "64.000\342\202\254", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "4.000\342\202\254", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "500\342\202\254", nullptr));
        pushButton_7->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "125.000\342\202\254", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "2.000\342\202\254", nullptr));
        Logo_Label->setText(QString());
        StartButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        BestenlisteButton->setText(QCoreApplication::translate("MainWindow", "Bestenliste", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
