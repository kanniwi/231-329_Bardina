#include "clientinterface.h"
#include <QObject>


ClientInterface* ClientInterface::existing_object = nullptr;

HistoricalEvent ClientInterface::GetHistoricalEvent(const unsigned int id)
{
    QNetworkRequest request;
//  request.setUrl(QUrl(m_root_url + "historicalEvents/" + QString::number(id)));
    request.setUrl(QUrl("http://127.0.0.1:8000/historicalEvents/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_client->get(request);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec(); // Ждём завершения запроса

    QByteArray responseData = reply->readAll(); // Читаем ответ

    // Парсим JSON
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

    QList<HistoricalEvent> events; // Список событий

    if (jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();
        for (const QJsonValue &value : jsonArray) {
            if (value.isObject()) {
                events.append(HistoricalEvent::fromJson(value.toObject()));
            }
        }
    } else if (jsonDoc.isObject()) {
        events.append(HistoricalEvent::fromJson(jsonDoc.object()));
    } else {
        qDebug() << "Ошибка: Ожидался JSON-объект или массив!";
    }

    // Выводим данные для проверки
    qDebug() << "Получено событий:" << events.size();
    for (const HistoricalEvent &event : events) {
        qDebug() << "Title:" << event.title << "| Category:" << event.category
                 << "| Start Date:" << event.startDate << "| End Date:" << event.endDate
                 << "| Is Peaceful:" << event.isPeaceful;
    }

    // Очистка памяти
    reply->deleteLater();

    // Возвращаем первый найденный event, либо пустой объект
    return events.isEmpty() ? HistoricalEvent() : events.first();
}

void ClientInterface::GetHistoricalEvents()
{
    QNetworkRequest request;
    // request.setUrl(QUrl(m_root_url + "historicalEvents/" + QString::number(id)));
    request.setUrl(QUrl("http://127.0.0.1:8000/historicalEvents/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = m_client->get(request);


    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    QByteArray responseData = reply->readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

    QList<HistoricalEvent> events;

    if (jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();
        for (const QJsonValue &value : jsonArray) {
            if (value.isObject()) {
                events.append(HistoricalEvent::fromJson(value.toObject()));
            }
        }
    } else if (jsonDoc.isObject()) {
        events.append(HistoricalEvent::fromJson(jsonDoc.object()));
    } else {
        qDebug() << "Ошибка: Ожидался JSON-объект или массив!";
    }
    qDebug() << "Получено событий:" << events.size();
    for (const HistoricalEvent &event : events) {
        qDebug() << "Title:" << event.title << "| Category:" << event.category
                 << "| Start Date:" << event.startDate << "| End Date:" << event.endDate
                 << "| Is Peaceful:" << event.isPeaceful;
    }
    reply->deleteLater();
}


void ClientInterface::DeleteHistoricalEvents(const unsigned int id)
{
    QUrl url("http://127.0.0.1:8000/historicalEvents/" + QString::number(id) + "/");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_client->deleteResource(request);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Событие успешно удалено. ID:" << id;
    } else {
        qDebug() << "Ошибка при удалении события:" << reply->errorString();
    }
    reply->deleteLater();
}


void ClientInterface::CreateHistoricalEvents()
{
    QJsonObject json;
    json["title"] = "negotiations";
    json["category"] = "politics";
    json["start_date"] = "1900-08-23";
    json["end_date"] = "1901-08-25";
    json["is_peaceful"] = true;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QUrl url("http://127.0.0.1:8000/historicalEvents/");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_client->post(request, data);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Событие успешно создано!";
        qDebug() << "Ответ сервера:" << reply->readAll();
    } else {
        qDebug() << "Ошибка при создании события:" << reply->errorString();
    }

    reply->deleteLater();
}

void ClientInterface::UpdateHistoricalEvents(const unsigned int id)
{
    QJsonObject json;
    json["title"] = "peace";
    json["start_date"] = "1900-08-23";

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QUrl url("http://127.0.0.1:8000/historicalEvents/" + QString::number(id) + "/");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_client->sendCustomRequest(request, "PATCH", data);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Событие успешно обновлено!";
        qDebug() << "Ответ сервера:" << reply->readAll();
    } else {
        qDebug() << "Ошибка при создании события:" << reply->errorString();
    }

    reply->deleteLater();
}





