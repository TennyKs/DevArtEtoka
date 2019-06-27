#include <QFileDialog>
#include <QDebug>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "sqlConnector.hpp"
#include "usbReader.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stateLabel->clear();
    ui->stateLabel->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog *dialog = new QFileDialog();
    dialog->show();
    ui->stateLabel->clear();

    if (!dialog->getExistingDirectory().isEmpty()) {
        qDebug() << dialog->getExistingDirectory();
        std::string path = dialog->getExistingDirectory().toStdString();

        UsbReader usbReader(path);
        usbReader.completeMap();
        usbReader.display();

        SqlConnector sqlConnector;
        sqlConnector.execute(usbReader.getMap());
        ui->stateLabel->setText("Réussite");
        ui->stateLabel->setStyleSheet("QLabel {color : #00e500; }");
    } else {
        ui->stateLabel->setText("Echec");
        ui->stateLabel->setStyleSheet("QLabel {color : #ff0000; }");
    }

    ui->stateLabel->show();
    dialog->close();

}
