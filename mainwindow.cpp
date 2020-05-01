#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Data Thread
    dataThread = new QThread();
    dataSystemWorker = new DataSystemWorker();
    connect(this, SIGNAL(initDataSystem()), dataSystemWorker, SLOT(init()));
    dataSystemWorker->moveToThread(dataThread);
    dataThread->start();
    emit initDataSystem();

    connect(ui->addStockBoxButton, SIGNAL(pressed()), this, SLOT(addStockBox()));
}

void MainWindow::addStockBox(){
    StockBox* stockBox = new StockBox;
    connect(stockBox, &StockBox::removeStockBox, this, &MainWindow::removeStockBox);
    connect(stockBox, &StockBox::subscribe, dataSystemWorker, &DataSystemWorker::subscribe);
    connect(stockBox, &StockBox::unsubscribe, dataSystemWorker, &DataSystemWorker::unsubscribe);
    connect(dataSystemWorker, &DataSystemWorker::update, stockBox, &StockBox::update);
    stockBoxes.insert(stockBox);
    stockBox->show();
}

void MainWindow::removeStockBox(StockBox* stockBox){
    stockBoxes.erase(stockBoxes.find(stockBox));
}

MainWindow::~MainWindow()
{
    dataThread->wait();
    dataThread->exit();
    delete ui;
}



