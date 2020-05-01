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
    void sendOrderResult(OrderResult);

public slots:
    // StockBox
    void addStockBox(StockBox* stockBox);
    void removeStockBox(StockBox* stockBox);
    void changeTestCode(StockBox* stockBox, QString stockCode, QString shortname);
    void changeBuyingStatus(StockBox* stockBox, bool start, bool inverse);
    void changeSellingStatus(StockBox* stockBox, bool start, bool inverse);
    void changeMatchingStatus(StockBox* stockBox, bool start, bool inverse);

    // Mainwindow
    void changeRakutenInfo(RakutenInfo info);

    // DataSystem
    void receiveData(QString code, StockData data);

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
