#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<StockData>("StockData");
    qRegisterMetaType<OrderResult>("OrderResult");

    // Data Thread
    dataThread = new QThread;
    dataSystemWorker = new DataSystemWorker;
    connect(this, SIGNAL(initDataSystem()), dataSystemWorker, SLOT(init()));
    dataSystemWorker->moveToThread(dataThread);
    dataThread->start();
    emit initDataSystem();

    // Order Thread
    orderThread = new QThread;
    orderSystemWorker = new OrderSystemWorker;
    connect(this, SIGNAL(initOrderSystem()), orderSystemWorker, SLOT(init()));
    orderSystemWorker->moveToThread(orderThread);
    orderThread->start();
    emit initOrderSystem();

    // Order Table Model
    orderTableModel = new OrderTableModel;
    connect(orderSystemWorker, &OrderSystemWorker::sendOrderResult, orderTableModel, &OrderTableModel::addRow);
    QSortFilterProxyModel* sortModel = new QSortFilterProxyModel;
    sortModel->setSourceModel(this->orderTableModel);
    sortModel->setDynamicSortFilter(true);
    ui->orderTableView->setModel(sortModel);
    ui->orderTableView->setModel(sortModel);

    // Order Table Column Width
    ui->orderTableView->setSortingEnabled(true);
    ui->orderTableView->setColumnWidth(0, 5);
    ui->orderTableView->setColumnWidth(1, 5);
    ui->orderTableView->setColumnWidth(2, 80);
    ui->orderTableView->setColumnWidth(3, 80);
    ui->orderTableView->setColumnWidth(4, 80);
    ui->orderTableView->setColumnWidth(5, 50);
    ui->orderTableView->setColumnWidth(6, 70);
    ui->orderTableView->setColumnWidth(7, 70);
    ui->orderTableView->setColumnWidth(8, 80);
    ui->orderTableView->setColumnWidth(9, 60);
    ui->orderTableView->setColumnWidth(10, 5);
    ui->orderTableView->horizontalHeader()->setSectionResizeMode(11, QHeaderView::Stretch);

    connect(ui->addStockBoxButton, SIGNAL(clicked()), this, SLOT(addStockBox()));
}

void MainWindow::addStockBox(){
    StockBox* stockBox = new StockBox(stockBoxID);
    connect(stockBox, &StockBox::removeStockBox, this, &MainWindow::removeStockBox);

    // Data System
    connect(stockBox, &StockBox::subscribe, dataSystemWorker, &DataSystemWorker::subscribe);
    connect(stockBox, &StockBox::unsubscribe, dataSystemWorker, &DataSystemWorker::unsubscribe);
    connect(dataSystemWorker, &DataSystemWorker::update, stockBox, &StockBox::update);

    // Order System
    connect(stockBox, &StockBox::sendOrder, orderSystemWorker, &OrderSystemWorker::receiveOrder);

    stockBoxes.push_back(stockBox);
    stockBoxID++;
    stockBox->show();
}

void MainWindow::removeStockBox(StockBox* stockBox){
    stockBoxes.erase(stockBoxes.begin() + stockBoxes.indexOf(stockBox));
}

void MainWindow::closeEvent(QCloseEvent *event){
    dataThread->terminate();
    orderThread->terminate();
    while(stockBoxes.size() > 0){
        stockBoxes[0]->close();
    }
    event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}



