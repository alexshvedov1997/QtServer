#include "myserver.h"

myserver::myserver(QObject *parent):QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &myserver::slotNewConnection);
    if(!mTcpServer->listen(QHostAddress::Any, 6000)){
        qDebug("Server can't start");
    }
    else{
        qDebug("Server started");
    }
}

myserver::~myserver(){}

void myserver::slotNewConnection(){
    qDebug("New connection");
    mTcpSocket = mTcpServer->nextPendingConnection();
    mTcpSocket->write("Hello world");
    emit connectClient();
    connect(mTcpSocket, &QTcpSocket::readyRead, this,&myserver::slotServerRead );
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &myserver::slotClientDisconect);

}

void myserver::slotServerRead(){
    while(mTcpSocket->bytesAvailable()>0){
        qDebug("Server get message");
        QString str = mTcpSocket->readAll();
        qDebug()<<str;
        emit apendToMainWindow(str);
    }
}

void myserver::slotClientDisconect(){
    mTcpSocket->close();
}


void myserver::slotSendMessage(){
    QByteArray array;
    qDebug("Server send");
    array.append("Write server data");
}

void myserver::sendRequest(){
    qDebug("Send 1");
    const char *str = "1";
    mTcpSocket->write(str);
}









