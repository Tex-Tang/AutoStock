#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<StockData>("StockData");
    qRegisterMetaType<OrderResult>("OrderResult");
    qRegisterMetaType<RakutenInfo>("RakutenInfo");

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
    connect(this, &MainWindow::changeRakutenInfo, orderSystemWorker, &OrderSystemWorker::changeRakutenInfo);
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

    // Logger Thread
    logThread = new QThread;
    loggerWorker = new LoggerWorker;
    connect(this, &MainWindow::initLogger, loggerWorker, &LoggerWorker::init);
    connect(dataSystemWorker, &DataSystemWorker::log, loggerWorker, &LoggerWorker::log);
    connect(orderSystemWorker, &OrderSystemWorker::log, loggerWorker, &LoggerWorker::log);
    loggerWorker->moveToThread(logThread);
    logThread->start();
    emit initLogger();

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
    ui->orderTableView->setColumnWidth(8, 70);
    ui->orderTableView->setColumnWidth(9, 80);
    ui->orderTableView->setColumnWidth(10, 60);
    ui->orderTableView->setColumnWidth(11, 5);
    ui->orderTableView->setColumnWidth(12, 300);
    //ui->orderTableView->horizontalHeader()->setSectionResizeMode(11, QHeaderView::Stretch);

    connect(ui->addStockBoxButton, SIGNAL(clicked()), this, SLOT(addStockBox()));
    connect(ui->autoArrangeButton, SIGNAL(clicked()), this, SLOT(autoArrange()));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadJson()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveJson()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectRakuten()));
    connect(ui->startAllBuyingButton, SIGNAL(clicked()), this, SLOT(startAllBuying()));
    connect(ui->stopAllBuyingButton, SIGNAL(clicked()), this, SLOT(stopAllBuying()));
    connect(ui->stopAllSellingButton, SIGNAL(clicked()), this, SLOT(stopAllSelling()));
    connect(ui->startAllSellingButton, SIGNAL(clicked()), this, SLOT(startAllSelling()));

}

void MainWindow::autoArrange(){
    int x = 0;
    int y = 0;
    for(StockBox* stockBox : stockBoxes){
        stockBox->move(x,y);
        y += 120;
        if(y >= 900){
            y = 0;
            x += 768;
        }
    }
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

void MainWindow::loadJson(){
    for(StockBox* stockbox : stockBoxes){
        stockbox->deleteLater();
    }
    stockBoxes.clear();
    this->stockBoxID = 1;
    QFile file("stocks.json");
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray stockBoxesArray = doc["stocks"].toArray();
    for(int i = 0;i < stockBoxesArray.size();++i){
        this->addStockBox();
        StockBoxJsonObject result = StockBoxJsonObject();
        result.x = stockBoxesArray[i].toObject().value("x").toInt();
        result.y = stockBoxesArray[i].toObject().value("y").toInt();
        QJsonArray stocksArray = stockBoxesArray[i].toObject().value("stocks").toArray();
        for(int i = 0;i < stocksArray.size();i++){
            StockBoxData stock;
            stock.code = stocksArray[i].toObject().value("code").toString();
            QJsonObject conditionObj = stocksArray[i].toObject().value("condition").toObject();
            stock.condition.ask = conditionObj.value("ask").toDouble();
            stock.condition.bid = conditionObj.value("bid").toDouble();
            stock.condition.asksize = conditionObj.value("asksize").toInt();
            stock.condition.bidsize = conditionObj.value("bidsize").toInt();
            stock.condition.askrate = conditionObj.value("askrate").toInt();
            stock.condition.bidrate = conditionObj.value("bidrate").toInt();
            result.stocks.push_back(stock);
        }
        stockBoxes.back()->load(result);
    }
    for(StockBox* stockbox : stockBoxes) stockbox->changeCode();
}

void MainWindow::saveJson(){
    QJsonArray stockBoxesArray;
    for(StockBox* stockBox : stockBoxes){
        QJsonObject result = {
            {"x", stockBox->x()},
            {"y", stockBox->y()},
        };
        QJsonArray stocks = {};
        for(int i = 0;i < stockBox->stocksData.size();i++){
            stocks.append(QJsonObject{
                              {"code", stockBox->stocksData[i]->code},
                              {"condition", QJsonObject{
                                   {"bid", stockBox->stocksData[i]->condition.bid},
                                   {"bidsize", stockBox->stocksData[i]->condition.bidsize},
                                   {"bidrate", stockBox->stocksData[i]->condition.bidrate},
                                   {"ask", stockBox->stocksData[i]->condition.ask},
                                   {"asksize", stockBox->stocksData[i]->condition.asksize},
                                   {"askrate", stockBox->stocksData[i]->condition.askrate},
                               }
                              }
                          });
        }
        result["stocks"] = stocks;
        stockBoxesArray.append(result);
    }
    QJsonObject obj;
    obj["stocks"] = stockBoxesArray;
    QJsonDocument doc(obj);
    QFile file("stocks.json");
    if(file.open(QIODevice::WriteOnly))
        file.write(doc.toJson());
}

void MainWindow::connectRakuten(){
    bool success = false;
    while (!success) {
        bool ok;
        QString text = QInputDialog::getText(this, "QInputDialog::getText()",
                                             "Rakuten Configuration:", QLineEdit::Normal,
                                             RAKUTEN_CONFIGURATION_COMMAND, &ok);
        QJsonDocument doc = QJsonDocument::fromJson(text.toUtf8());
        QMessageBox msgBox;
        if(!doc.isNull()){
            if(doc.isObject() &&
                    doc.object().contains("tpin") &&
                    doc.object().contains("accNo") &&
                    doc.object().contains("appID") &&
                    doc.object().contains("cookie") &&
                    doc.object().contains("session")){
                RakutenInfo info = RakutenInfo();
                QJsonObject obj = doc.object();
                info.tpin = obj.value("tpin").toString();
                info.accNo = obj.value("accNo").toString();
                info.appID = obj.value("appID").toString();
                info.cookie = obj.value("cookie").toString();
                info.session = obj.value("session").toString();
                emit changeRakutenInfo(info);
                msgBox.setText("Rakuten Configuration saved!");
                msgBox.setIcon(QMessageBox::Information);
                success = true;
            }else{
                msgBox.setText("Please retry!");
                msgBox.setIcon(QMessageBox::Warning);
            }
        }else{
            msgBox.setText("Not a valid JSON, Please copy properly.");
            msgBox.setIcon(QMessageBox::Critical);
        }
        msgBox.exec();
    }
}

void MainWindow::startAllBuying(){
    for(StockBox* stockBox : stockBoxes){
        stockBox->startBuying(true);
    }
}

void MainWindow::stopAllBuying(){
    for(StockBox* stockBox : stockBoxes){
        stockBox->startBuying(false);
    }
}

void MainWindow::startAllSelling(){
    for(StockBox* stockBox : stockBoxes){
        stockBox->startSelling(true);
    }
}

void MainWindow::stopAllSelling(){
    for(StockBox* stockBox : stockBoxes){
        stockBox->startSelling(false);
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    dataThread->terminate();
    orderThread->terminate();
    logThread->terminate();
    while(stockBoxes.size() > 0){
        stockBoxes[0]->close();
    }
    event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}
