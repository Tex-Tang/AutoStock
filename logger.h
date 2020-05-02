#ifndef LOGGER_H
#define LOGGER_H

#include <QDir>
#include <QFile>
#include <QObject>
#include <QDateTime>
#include <QTextStream>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

public slots:
    void log(QString msg);

private:
    QFile* file;
    QTextStream* text;
};

#endif // LOGGER_H
