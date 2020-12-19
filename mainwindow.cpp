#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    varaible = new myserver;
    connect(varaible, &myserver::connectClient,this, &MainWindow::printNewConnection);
    connect(this, &MainWindow::sendRequestToClient, varaible, &myserver::sendRequest);
    connect(varaible, &myserver::apendToMainWindow, this, &MainWindow::printMessageStr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printNewConnection(){
    ui->textBrowser->setText("New connection");
}

void MainWindow::on_sendMessage_clicked()
{
    emit sendRequestToClient();
}

void MainWindow::printMessageStr(QString str){
    ui->textBrowser->append(str);

}
