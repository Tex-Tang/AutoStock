#include "loggerworker.h"

LoggerWorker::LoggerWorker(QObject *parent) : QObject(parent)
{

}

void LoggerWorker::init(){
    logger = new Logger;
    connect(this, &LoggerWorker::log, logger, &Logger::log);
}
