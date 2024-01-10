#ifndef SERVERMANGER_H
#define SERVERMANGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class ServerManger : public QObject
{
    Q_OBJECT
public:
    explicit ServerManger(ushort port = 4500,
                          QObject *parent = nullptr);

signals:
    void newClientConnected(QTcpSocket* client);
    void clientDisconnected(QTcpSocket* client);

private slots:
    void newClientConnectionReceived();
    void onClientDisconnected();

private:
    QTcpServer *_server;
    QList<QTcpSocket *>_clients;
private:        // Methods
    void setupServer(ushort port);

};

#endif // SERVERMANGER_H
