#include "ServerManger.h"

ServerManger::ServerManger(ushort port, QObject *parent) : QObject(parent)
{
    setupServer(port);
}

void ServerManger::newClientConnectionReceived()
{
    auto client = _server->nextPendingConnection();
    _clients << client;
    auto id = _clients.length();
    client->setProperty("id", id);
    connect(client, &QTcpSocket::disconnected, this, &ServerManger::onClientDisconnected);
    emit newClientConnected(client);
}

void ServerManger::onClientDisconnected()
{
    auto client = qobject_cast<QTcpSocket* >(sender());
//    int id = client->property("id").toInt();
    _clients.removeOne(client);
     emit clientDisconnected(client);

}

void ServerManger::setupServer(ushort port)
{
    _server = new QTcpServer(this);
    connect(_server, &QTcpServer::newConnection, this, &ServerManger::newClientConnectionReceived);
    _server->listen(QHostAddress::Any, port);

}
