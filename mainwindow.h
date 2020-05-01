#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QSet>
#include "stockbox.h"
#include "datasystemworker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addStockBox();
    void removeStockBox(StockBox* stockBox);

signals:
    void initDataSystem();

private:
    Ui::MainWindow *ui;
    QThread* dataThread;
    DataSystemWorker* dataSystemWorker;
    QSet <StockBox*> stockBoxes;
};
#endif // MAINWINDOW_H
