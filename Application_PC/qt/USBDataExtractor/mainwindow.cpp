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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog *dialog = new QFileDialog();
    dialog->show();

    if (!dialog->getExistingDirectory().isEmpty()) {
        qDebug() << dialog->getExistingDirectory();
        std::string path = dialog->getExistingDirectory().toStdString();

        UsbReader usbReader(path);
        usbReader.completeMap();
        usbReader.display();

        SqlConnector sqlConnector;
        sqlConnector.execute(usbReader.getMap());

    }

    dialog->close();

}
