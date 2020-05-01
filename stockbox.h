#ifndef STOCKBOX_H
#define STOCKBOX_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include "ddecomm.h"
#include "datastruct.h"
#include "stockboxtablemodel.h"
#include "stockboxtablespinboxdelegate.h"

namespace Ui {
class StockBox;
}

class StockBox : public QWidget
{
    Q_OBJECT

public:
    QVector<StockBoxData*> stocksData;
    explicit StockBox(QWidget *parent = nullptr);
    ~StockBox();

public slots:
    void changeCode();
    StockBoxData request(QString code);
    void update(QString code, StockData data);

signals:
    void subscribe(StockBox* self, QString code);
    void unsubscribe(StockBox* self, QString code);
    void startBuyingSignal(StockBox* self, bool start, bool inverse);
    void startSellingSignal(StockBox* self, bool start, bool inverse);

private:
    DdeComm* ddeComm;
    Ui::StockBox *ui;
    StockBoxTableModel* tableModel;
};

#endif // STOCKBOX_H
