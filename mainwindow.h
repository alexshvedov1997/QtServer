#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "myserver.h"
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    myserver * varaible;
private:
    Ui::MainWindow *ui;
private slots:
    void printNewConnection();
    void on_sendMessage_clicked();
    void printMessageStr(QString str);
signals:
    void sendRequestToClient();
};
#endif // MAINWINDOW_H
