#include "ClientManger.h"








ClientManger::ClientManger(QHostAddress ip, ushort port, QObject *parent):
    QObject(parent),
    _ip(ip),
    _port(port)
{
    _socket = new QTcpSocket(this);
    connect(_socket, &QTcpSocket::connected,this, &ClientManger::connected );
    connect(_socket, &QTcpSocket::disconnected,this, &ClientManger::disconnected );
    connect(_socket, &QTcpSocket::readyRead,this, &ClientManger::readyRead );

}

void ClientManger::connectToServer()
{
    _socket->connectToHost(_ip, _port);
}

void ClientManger::sendMessage(QString message)
{
    _socket->write(message.toUtf8());
}

void ClientManger::readyRead()
{
    auto data = _socket->readAll();
    emit dataReceived(data);
}

