/********************************************************************************
** Form generated from reading UI file 'bestenliste.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BESTENLISTE_H
#define UI_BESTENLISTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bestenliste
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *Logo_Label;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Bestenliste)
    {
        if (Bestenliste->objectName().isEmpty())
            Bestenliste->setObjectName("Bestenliste");
        Bestenliste->resize(1373, 656);
        layoutWidget = new QWidget(Bestenliste);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(140, 110, 896, 285));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Logo_Label = new QLabel(layoutWidget);
        Logo_Label->setObjectName("Logo_Label");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Logo_Label->sizePolicy().hasHeightForWidth());
        Logo_Label->setSizePolicy(sizePolicy);
        Logo_Label->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        Logo_Label->setScaledContents(true);

        verticalLayout_2->addWidget(Logo_Label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #4B8A90;\n"
"border: none;\n"
"color: white;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #4B8A90;\n"
"border: none;\n"
"color: white;\n"
"padding: 10px 20px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border-radius: 10px;"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(Bestenliste);

        QMetaObject::connectSlotsByName(Bestenliste);
    } // setupUi

    void retranslateUi(QDialog *Bestenliste)
    {
        Bestenliste->setWindowTitle(QCoreApplication::translate("Bestenliste", "Dialog", nullptr));
        Logo_Label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Bestenliste", "Start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Bestenliste", "Bestenliste", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bestenliste: public Ui_Bestenliste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BESTENLISTE_H
