#include "logger.h"

Logger::Logger(QObject* parent) : QObject(parent)
{

}

// void Logger::dataChanged()
// {

// }

// void Logger::updateInfo(const QString& info)
// {
//     _text += info;
//     emit infoChanged();
// }

QString Logger::Info() const
{
    return _info;
}

void Logger::setInfo(QString t)
{
    _info = t;
}

Logger::msg_type Logger::Type() const
{
    return _type;
}

void Logger::setType(Logger::msg_type type)
{
    _type = type;
}

void Logger::Output(Logger::msg_type type, QString info)
{
    _type = type;
    _info = info;
    emit dataChanged();
}

Logger engine_logger;