#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>


class ClientManger : public QObject
{
    Q_OBJECT
public:
    explicit ClientManger(QHostAddress ip= QHostAddress::LocalHost, ushort port = 4500, QObject *parent = nullptr);
    void connectToServer();
    void sendMessage(QString message);

signals:
    void connected();
    void disconnected();
    void dataReceived(QByteArray data);
private slots:

    void readyRead();
private:
    //fields
    QTcpSocket* _socket;
    QHostAddress _ip;
    ushort _port;


};

#endif // CLIENTMANGER_H
