#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QDebug>
#include <QString>
class myserver:public QObject{
    Q_OBJECT
public:
    myserver(QObject *parent = 0);
    ~myserver();

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconect();
    void slotSendMessage();
    void sendRequest();
signals:
    void readyWrite();
    void apendToMainWindow(QString str);
    void connectClient();
private:
    QTcpSocket * mTcpSocket;
    QTcpServer * mTcpServer;
};

#endif // MYSERVER_H
