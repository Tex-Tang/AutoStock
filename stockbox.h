#ifndef STOCKBOX_H
#define STOCKBOX_H

#include <QWidget>

namespace Ui {
class StockBox;
}

class StockBox : public QWidget
{
    Q_OBJECT

public:
    explicit StockBox(QWidget *parent = nullptr);
    ~StockBox();

signals:
    void subscribe(StockBox* self, QString code);
    void startBuyingSignal(StockBox* self, bool start, bool inverse);
    void startSellingSignal(StockBox* self, bool start, bool inverse);

private:
    Ui::StockBox *ui;
};

#endif // STOCKBOX_H
