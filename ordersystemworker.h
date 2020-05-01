#ifndef ORDERSYSTEMWORKER_H
#define ORDERSYSTEMWORKER_H

#include <QObject>
#include <ordersystem.h>

class OrderSystemWorker : public QObject
{
    Q_OBJECT
public:
    explicit OrderSystemWorker(QObject *parent = nullptr);

public slots:
    void init();

signals:
    void receiveOrder(QString action, int id, QString code, QString name, int qty, double price);
    void sendOrderResult(OrderResult result);

private:
    OrderSystem* orderSystem;

};

#endif // ORDERSYSTEMWORKER_H
