#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "historicalevents.h"
#include "clientinterface.h"
#include <C:/Qt/6.8.2/msvc2022_64/include/QtNetwork/QNetworkAccessManager.h>
#include <C:/Qt/6.8.2/msvc2022_64/include/QtNetwork/QNetworkReply.h>
#include <C:/Qt/6.8.2/msvc2022_64/include/QtNetwork/QNetworkRequest.h>
#include <QUrl>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_get_1_event_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");

    HistoricalEvent event = client->GetHistoricalEvent(1);

}

void MainWindow::on_get_events_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");
    client->GetHistoricalEvents();
}

void MainWindow::on_delete_button_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");
    client->DeleteHistoricalEvents(13);
}

void MainWindow::on_create_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");
    client->CreateHistoricalEvents();
}


void MainWindow::on_update_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");
    client->UpdateHistoricalEvents(14);
}

