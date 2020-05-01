#include "ordersystemworker.h"

OrderSystemWorker::OrderSystemWorker(QObject *parent) : QObject(parent)
{

}

void OrderSystemWorker::init(){
    orderSystem = new OrderSystem;
    connect(this, &OrderSystemWorker::receiveOrder, orderSystem, &OrderSystem::receiveOrder);
    connect(this, &OrderSystemWorker::changeRakutenInfo, orderSystem, &OrderSystem::changeRakutenInfo);
    connect(orderSystem, &OrderSystem::sendOrderResult, this, &OrderSystemWorker::sendOrderResult);
    connect(orderSystem, &OrderSystem::log, this, &OrderSystemWorker::log);
}
