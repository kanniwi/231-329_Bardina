#ifndef HISTORICALEVENT_H
#define HISTORICALEVENT_H

#include <QString>
#include <QJsonObject>

class HistoricalEvent
{
public:
    QString startDate;
    QString endDate;
    QString title;
    QString category;
    bool isPeaceful;

    // Конструктор
    HistoricalEvent(QString startDate, QString endDate, QString title, QString category, bool isPeaceful);

    HistoricalEvent()
        : startDate(""), endDate(""), title(""), category(""), isPeaceful(false) {}

    // Метод для десериализации JSON в объект
    static HistoricalEvent fromJson(const QJsonObject &json);
};

#endif // HISTORICALEVENT_H
