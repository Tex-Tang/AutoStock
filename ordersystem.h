#ifndef ORDERSYSTEM_H
#define ORDERSYSTEM_H

#include <QObject>

class OrderSystem : public QObject
{
    Q_OBJECT
public:
    explicit OrderSystem(QObject *parent = nullptr);

signals:

};

#endif // ORDERSYSTEM_H
