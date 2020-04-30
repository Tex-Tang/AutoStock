#ifndef DATASYSTEM_H
#define DATASYSTEM_H


#include <QMap>
#include <QHash>
#include <QString>
#include <QObject>
#include <QtDebug>
#include "ddecomm.h"
#include "stockbox.h"
#include "datastruct.h"

class DataSystem : public QObject
{
    Q_OBJECT
public:
    explicit DataSystem(QObject *parent = nullptr);
    bool startAdvise(QString code);
    bool stopAdvise(QString code);
public slots:
    // Slots for StockBox
    void subscribe(StockBox* stockBox, QString code);
    void unsubscribe(StockBox* stockBox, QString code);

    // Slots for DdeComm
    void receiveData(QString code, QString item, QString value);

signals:
    void log(QString msg);
    void update(QString code, StockData data);
private:
    DdeComm* dde;
    unsigned long long conversationMY;
    unsigned long long conversationMD;
    QHash<QString, StockData> codeToStockData;
    QHash<QString, QMap<StockBox*,unsigned int>> codeToStockBoxes;
    QStringList itemsIndex = { "ask", "bid", "asksize", "bidsize" };
};

#endif // DATASYSTEM_H
