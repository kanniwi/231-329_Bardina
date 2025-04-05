#include "historicalevents.h"

// Конструктор
HistoricalEvent::HistoricalEvent(QString startDate, QString endDate, QString title, QString category, bool isPeaceful)
    : startDate(startDate), endDate(endDate), title(title), category(category), isPeaceful(isPeaceful) {}

// Метод десериализации JSON → C++ объект
HistoricalEvent HistoricalEvent::fromJson(const QJsonObject &json)
{
    return HistoricalEvent(
        json["start_date"].toString(),
        json["end_date"].toString(),
        json["title"].toString(),
        json["category"].toString(),
        json["is_peaceful"].toBool()
        );
}
