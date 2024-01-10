#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ServerManger.h"
#include "ClientChatWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void newClientConnected(QTcpSocket* client);
    void clientDisconnected(QTcpSocket* client);

private:
    Ui::MainWindow *ui;
    ServerManger* _server;

private:
    // Here where your methods lay..
    void setupServer();
};
#endif // MAINWINDOW_H
