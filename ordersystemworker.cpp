#include "ordersystemworker.h"

OrderSystemWorker::OrderSystemWorker(QObject *parent) : QObject(parent)
{

}

void OrderSystemWorker::init(){
    orderSystem = new OrderSystem;
    connect(this, &OrderSystemWorker::receiveOrder, orderSystem, &OrderSystem::receiveOrder);
    connect(orderSystem, &OrderSystem::sendOrderResult, this, &OrderSystemWorker::sendOrderResult);
}
