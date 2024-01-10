#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConnect_triggered()
{
    _client = new ClientManger();

    connect(_client, &ClientManger::connected, [this](){
        ui->centralwidget->setEnabled(true);
    });
    connect(_client, &ClientManger::disconnected, [this](){
        ui->centralwidget->setEnabled(false);
    });
    connect(_client, &ClientManger::dataReceived, this, &MainWindow::dataReceived);
    _client->connectToServer();
}

void MainWindow::dataReceived(QByteArray data)
{
//    ui->lstMessage->addItem(data);
    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(data, true);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,65));
    ui->lstMessage->addItem(listItemWidget);
    listItemWidget->setBackground(QColor(0,0, 255));
    ui->lstMessage->setItemWidget(listItemWidget, chatWidget);


}
void MainWindow::on_btnSend_clicked()
{
    auto message = ui->lnMessage->text().trimmed().toUtf8();
    _client->sendMessage(message);
//    ui->lstMessage->addItem(message);
    ui->lnMessage->setText("");


    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(0,65));
    ui->lstMessage->addItem(listItemWidget);
    listItemWidget->setBackground(QColor(0,255, 0));
    ui->lstMessage->setItemWidget(listItemWidget, chatWidget);


}

