/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *imageLabel;
    QLabel *stateLabel;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(450, 300);
        MainWindow->setMinimumSize(QSize(450, 300));
        MainWindow->setMaximumSize(QSize(450, 300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(75, 230, 300, 28));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(0, 50, 451, 141));
        imageLabel->setPixmap(QPixmap(QString::fromUtf8("devart.png")));
        imageLabel->setScaledContents(true);
        stateLabel = new QLabel(centralWidget);
        stateLabel->setObjectName(QString::fromUtf8("stateLabel"));
        stateLabel->setGeometry(QRect(0, 270, 451, 20));
        stateLabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(387, 234, 41, 20));
        label->setPixmap(QPixmap(QString::fromUtf8("logo-usb.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(22, 233, 41, 20));
        label_2->setPixmap(QPixmap(QString::fromUtf8("logo-usb_mirror.png")));
        label_2->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "USB Data Extractor", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "S\303\251lectionnez un p\303\251riph\303\251rique de stockage", nullptr));
        imageLabel->setText(QString());
        stateLabel->setText(QApplication::translate("MainWindow", "- State -", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
