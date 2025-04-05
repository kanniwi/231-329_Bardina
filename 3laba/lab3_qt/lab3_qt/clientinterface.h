#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <C:/Qt/6.8.2/msvc2022_64/include/QtNetwork/QNetworkAccessManager.h>
#include <C:/Qt/6.8.2/msvc2022_64/include/QtNetwork/QNetworkReply.h>
#include <C:/Qt/6.8.2/msvc2022_64/include/QtNetwork/QNetworkRequest.h>
#include "historicalevents.h"
#include <QUrl>
#include <QEventLoop>


#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class ClientInterface {

public:
    static ClientInterface * getInstance(const QString & root_url) {
        //check if objects of clientinterface exists
        if (existing_object == nullptr) {
            if (existing_object == nullptr) {
                existing_object = new ClientInterface(root_url);
            }
        }
        return existing_object;
    }

    HistoricalEvent GetHistoricalEvent(unsigned int id);
    void DeleteHistoricalEvents(unsigned int id);
    void UpdateHistoricalEvents(unsigned int id);
    void CreateHistoricalEvents();
    void GetHistoricalEvents();

    ~ClientInterface() {
        delete m_client;
    }

    static void removeInstance() {
        if (existing_object)
            delete existing_object;
        existing_object = nullptr;
    }

private:
    static ClientInterface * existing_object;
    ClientInterface(const QString & root_url)
        :m_root_url(root_url)
    {
        m_client = new QNetworkAccessManager();
    }
    QNetworkAccessManager *m_client = nullptr;

    QString m_root_url;
};

#endif
