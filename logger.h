#pragma once

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <QObject>
#include <QString>
#include <QQuickItem>

class Logger : public QObject
{
    Q_OBJECT
public:
    enum msg_type : uint32_t
    {
        INFO = 0,
        FATAL = 1,
        WARNING = 2,
        ERROR = 3
    };
    Q_ENUM(msg_type)

    explicit Logger(QObject* parent = nullptr);

    QString Info() const;
    void setInfo(QString t);

    msg_type Type() const;
    void setType(msg_type type);

    
    Q_PROPERTY(msg_type Type MEMBER _type NOTIFY dataChanged)
    Q_PROPERTY(QString Info MEMBER _info NOTIFY dataChanged)

signals:
    void dataChanged();

public slots:
    void Output(msg_type type, QString info);

private:
    QString     _info{ "TEST!!!OTOOTOOTOOTOOTO" };
    msg_type    _type{ msg_type::INFO };
};

extern Logger engine_logger;

#endif
