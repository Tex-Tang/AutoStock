#ifndef LOGGERWORKER_H
#define LOGGERWORKER_H

#include <QObject>
#include "logger.h"

class LoggerWorker : public QObject
{
    Q_OBJECT
public:
    explicit LoggerWorker(QObject *parent = nullptr);

public slots:
    void init();

signals:
    void log(QString msg);

private:
    Logger* logger;
};

#endif // LOGGERWORKER_H
