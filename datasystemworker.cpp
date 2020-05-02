#include "datasystemworker.h"

DataSystemWorker::DataSystemWorker(QObject *parent) : QObject(parent){}

void DataSystemWorker::init(){
    dataSystem = new DataSystem;
    connect(this, &DataSystemWorker::subscribe, dataSystem, &DataSystem::subscribe);
    connect(this, &DataSystemWorker::unsubscribe, dataSystem, &DataSystem::unsubscribe);
    connect(dataSystem, &DataSystem::update, this, &DataSystemWorker::update);
    connect(dataSystem, &DataSystem::log, this, &DataSystemWorker::log);
}
