#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QVector>
#include <QSortFilterProxyModel>
#include <QInputDialog>
#include "stockbox.h"
#include "datasystemworker.h"
#include "ordersystemworker.h"
#include "ordertablemodel.h"
#include "loggerworker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

public slots:
    void autoArrange();
    void addStockBox();
    void removeStockBox(StockBox* stockBox);
    void loadJson();
    void saveJson();
    void connectRakuten();
    void startAllBuying();
    void stopAllBuying();
    void startAllSelling();
    void stopAllSelling();

signals:
    void initDataSystem();
    void initOrderSystem();
    void initLogger();
    void changeRakutenInfo(RakutenInfo info);

private:
    Ui::MainWindow *ui;
    int stockBoxID = 1;
    QVector <StockBox*> stockBoxes;

    QThread* dataThread;
    DataSystemWorker* dataSystemWorker;

    QThread* orderThread;
    OrderSystemWorker* orderSystemWorker;
    OrderTableModel* orderTableModel;

    QThread* logThread;
    LoggerWorker* loggerWorker;

};
#endif // MAINWINDOW_H
