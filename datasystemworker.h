#ifndef DATASYSTEMWORKER_H
#define DATASYSTEMWORKER_H

#include <QObject>
#include "stockbox.h"
#include "datastruct.h"
#include "datasystem.h"

class DataSystemWorker : public QObject
{
    Q_OBJECT
public:
    explicit DataSystemWorker(QObject *parent = nullptr);

signals:
    void subscribe(StockBox* stockBox, QString code);
    void unsubscribe(StockBox* stockBox, QString code);
    void update(QString code, StockData data);
    void log(QString msg);

public slots:
    void init();

private:
    DataSystem* dataSystem;
};

#endif // DATASYSTEMWORKER_H
