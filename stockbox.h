#ifndef STOCKBOX_H
#define STOCKBOX_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
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
    explicit StockBox(int id, QWidget *parent = nullptr);
    ~StockBox();
    void load(StockBoxJsonObject obj);
    void test(StockData data);
    void closeEvent(QCloseEvent *event);
    void startBuying(bool start, bool inverse = false);
    void startSelling(bool start, bool inverse = false);
    void startMatching(bool start, bool inverse = false);

public slots:
    void changeCode();
    StockBoxData request(QString code);
    void update(QString code, StockData data);
    void copyAsk();
    void copyBid();
    void startBuyingButtonPressed();
    void startSellingButtonPressed();
    void startMatchingButtonPressed();
    void startInverseBuyingButtonPressed();
    void startInverseSellingButtonPressed();
    void startInverseMatchingButtonPressed();

signals:
    void removeStockBox(StockBox* self);
    void subscribe(StockBox* self, QString code);
    void unsubscribe(StockBox* self, QString code);
    void sendOrder(QString action, int id, QString code, QString name, int qty, double price, int triggerSize);

private:
    int id;
    DdeComm* ddeComm;
    Ui::StockBox *ui;
    StockBoxTableModel* tableModel;

    bool buying = false;
    bool selling = false;
    bool matching = false;
    bool inverseBuying = false;
    bool inverseSelling = false;
    bool inverseMatching = false;
};

#endif // STOCKBOX_H
