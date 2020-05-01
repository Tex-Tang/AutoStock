#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QVector>
#include <QSortFilterProxyModel>
#include "stockbox.h"
#include "datasystemworker.h"
#include "ordersystemworker.h"
#include "ordertablemodel.h"

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
    void addStockBox();
    void removeStockBox(StockBox* stockBox);

signals:
    void initDataSystem();
    void initOrderSystem();

private:
    Ui::MainWindow *ui;
    QThread* dataThread;
    QThread* orderThread;
    int stockBoxID = 1;
    QVector <StockBox*> stockBoxes;
    DataSystemWorker* dataSystemWorker;
    OrderSystemWorker* orderSystemWorker;
    OrderTableModel* orderTableModel;

};
#endif // MAINWINDOW_H
