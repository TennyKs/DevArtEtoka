#include <QFileDialog>
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>

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
    setWindowFlags(Qt::WindowStaysOnTopHint);

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    QFileDialog *dialog = new QFileDialog();
//    dialog->show();

    QString file_name = QFileDialog::getExistingDirectory(this, tr("Open a folder.."));
    ui->stateLabel->clear();
    qDebug() << file_name;

    if (!file_name.isNull() && !file_name.isEmpty() && file_name.length() > 0) {
//        qDebug() << dialog->getExistingDirectory();
//        std::string path = dialog->getExistingDirectory().toStdString();
        std::string path = file_name.toStdString();

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
//    dialog->close();

}
