#ifndef ORDERSYSTEM_H
#define ORDERSYSTEM_H


#include <QSet>
#include <QHash>
#include <QObject>
#include <QString>
#include <QtNetwork>
#include <QByteArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

#include "aes.h"
#include "stockbox.h"
#include "datastruct.h"

#define RAKUTEN_PASSPHRASE "TRex+"

class OrderSystem : public QObject
{
    Q_OBJECT
public:
    explicit OrderSystem(QObject *parent = nullptr);
    void order(QString action, OrderStatus info, int qty, double price);

signals:
    void sendOrderResult(OrderResult result);

public slots:
    // StockBox
    void requestDone(QNetworkReply *reply);
    void receiveOrder(QString action, int id, QString code, QString name, int qty, double price);

    // Mainwindow
    void changeRakutenInfo(RakutenInfo info);

private:
    AES* aes;
    RakutenInfo info;
    QNetworkRequest networkRequest;
    QNetworkAccessManager* networkManager;
    QHash<QString, QSet<StockBox*>> codeToStockBoxes;
    QHash<StockBox*, OrderStatus> stockBoxToOrderStatus;
    QByteArray requestData(QString odrSide, QString mrktsym, int qty, double price);
};

#endif // ORDERSYSTEM_H
