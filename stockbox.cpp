#include "stockbox.h"
#include "ui_stockbox.h"

StockBox::StockBox(int id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockBox)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->id = id;
    ddeComm = new DdeComm;
    stocksData.append(new StockBoxData);
    stocksData.append(new StockBoxData);
    stocksData[0]->data.reset();
    stocksData[1]->data.reset();
    tableModel = new StockBoxTableModel(stocksData, this);
    ui->stockBoxDataTableView->setModel(tableModel);
    ui->stockBoxDataTableView->setItemDelegate(new StockBoxTableSpinBoxDelegate);
    ui->stockBoxDataTableView->verticalHeader()->setDefaultSectionSize(20);
    ui->stockBoxDataTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->stockBoxDataTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stockBoxDataTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->stockBoxDataTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(ui->stockCodeLineEdit, SIGNAL(returnPressed()), this, SLOT(changeCode()));
    connect(ui->warrantCodeLineEdit, SIGNAL(returnPressed()), this, SLOT(changeCode()));
    connect(ui->copyAskButton, SIGNAL(clicked()), this, SLOT(copyAsk()));
    connect(ui->copyBidButton, SIGNAL(clicked()), this, SLOT(copyBid()));
    connect(ui->startBuyingButton, SIGNAL(clicked()), this, SLOT(startBuyingButtonPressed()));
    connect(ui->startSellingButton, SIGNAL(clicked()), this, SLOT(startSellingButtonPressed()));
    connect(ui->startMatchingButton, SIGNAL(clicked()), this, SLOT(startMatchingButtonPressed()));
    connect(ui->startInverseBuyingButton, SIGNAL(clicked()), this, SLOT(startInverseBuyingButtonPressed()));
    connect(ui->startInverseSellingButton, SIGNAL(clicked()), this, SLOT(startInverseSellingButtonPressed()));
    connect(ui->startInverseMatchingButton, SIGNAL(clicked()), this, SLOT(startInverseMatchingButtonPressed()));
    this->startBuying(false);
    this->startSelling(false);
    this->startMatching(false);
    this->startBuying(false, true);
    this->startSelling(false, true);
    this->startMatching(false, true);
}

void StockBox::load(StockBoxJsonObject obj){
    this->move(obj.x, obj.y);
    ui->stockCodeLineEdit->setText(obj.stocks[0].code);
    this->stocksData[0]->condition = obj.stocks[0].condition;
    ui->warrantCodeLineEdit->setText(obj.stocks[1].code);
    this->stocksData[1]->condition = obj.stocks[1].condition;
}

void StockBox::changeCode(){
    if(ui->stockCodeLineEdit->text() != stocksData[0]->name){
        QString new_code = ui->stockCodeLineEdit->text();
        StockBoxData result = request(new_code);
        if(!result.name.isEmpty()){
            if(!stocksData[0]->code.isNull()) emit unsubscribe(this, stocksData[0]->code);
            stocksData[0]->code = new_code; // result.code has replaced "MD"
            stocksData[0]->name = result.name;
            stocksData[0]->data = result.data;
            emit subscribe(this, new_code);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error" ,"Couldn't fetch stock with code :" + new_code);
            ui->stockCodeLineEdit->setText(stocksData[0]->code);
        }
    }

    if(ui->warrantCodeLineEdit->text() != stocksData[1]->name){
        QString new_code = ui->warrantCodeLineEdit->text();
        StockBoxData result = request(new_code);
        if(!result.name.isEmpty()){
            if(!stocksData[1]->code.isNull()) emit unsubscribe(this, stocksData[1]->code);
            stocksData[1]->code = new_code; // result.code has replaced "MD"
            stocksData[1]->name = result.name;
            stocksData[1]->data = result.data;
            emit subscribe(this, new_code);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error" ,"Couldn't fetch stock with code :" + new_code);
            ui->warrantCodeLineEdit->setText(stocksData[1]->code);
        }
    }
    this->tableModel->updateData();
    this->setWindowTitle(QString::number(id) + " " + this->stocksData[0]->code + " " + this->stocksData[0]->name + " " + this->stocksData[1]->code + " " + this->stocksData[1]->name);
}

StockBoxData StockBox::request(QString code){
    StockBoxData result = StockBoxData();
    QString topic = code.contains(".MD") ? "MD" : "MY";
    code = code.replace(".MD", "");
    result.name = ddeComm->request(DDE_APP, topic, code + ";shortname").replace(" [S]","");
    if(!result.name.isEmpty()){
        result.code = code;
        result.data.ask = ddeComm->request(DDE_APP, topic, code + ";ask").toDouble();
        result.data.bid = ddeComm->request(DDE_APP, topic, code + ";bid").toDouble();
        result.data.asksize = ddeComm->request(DDE_APP, topic, code + ";asksize").toDouble();
        result.data.bidsize = ddeComm->request(DDE_APP, topic, code + ";bidsize").toDouble();
        double total_size = result.data.bidsize +  result.data.asksize;
        if(total_size > 0){
             result.data.askrate =  qRound((result.data.asksize / total_size)*100);
             result.data.bidrate =  qRound((result.data.bidsize / total_size)*100);
        }else{
             result.data.askrate =  result.data.bidrate = 100;
        }
    }
    return result;
}

void StockBox::update(QString code, StockData data){
    if(stocksData[0]->code.replace(".MD","") == code){
        stocksData[0]->data = data;
        this->test(data);
    }
    if(stocksData[1]->code.replace(".MD","") == code){
        stocksData[1]->data = data;
    }
    this->tableModel->updateData();
}

void StockBox::test(StockData data){
    StockCondition condition = this->stocksData[0]->condition;
    bool general = data.bid > 0 && data.ask > 0 && data.bid != data.ask;
    bool buy = general &&
               ((data.ask >= condition.ask && data.askrate <= condition.askrate) ||
               (data.ask > condition.ask) ||
               (data.ask >= condition.ask && data.asksize <= condition.asksize));
    bool sell = general &&
                ((data.bid <= condition.bid && data.bidrate <= condition.bidrate) ||
                (data.bid < condition.bid) ||
                (data.bid <= condition.bid && data.bidsize <= condition.bidsize));
    if(this->buying && buy){
        this->startBuying(false);
        emit sendOrder("buy",
                       this->id,
                       this->stocksData[1]->code,
                       this->stocksData[1]->name,
                       this->stocksData[1]->condition.asksize / 100,
                       this->stocksData[1]->condition.ask,
                       data.asksize);
        if(this->matching){
            this->startSelling(true);
            this->startMatching(false);
        }
    }

    if(this->selling && sell){
        this->startSelling(false);
        emit sendOrder("sell",
                       this->id,
                       this->stocksData[1]->code,
                       this->stocksData[1]->name,
                       this->stocksData[1]->condition.bidsize / 100,
                       this->stocksData[1]->condition.bid,
                       data.bidsize);
    }

    if(this->inverseBuying && sell){
        this->startBuying(false, true);
        emit sendOrder("buy",
                       this->id,
                       this->stocksData[1]->code,
                       this->stocksData[1]->name,
                       this->stocksData[1]->condition.bidsize / 100,
                       this->stocksData[1]->condition.bid,
                       data.bidsize);
        if(this->inverseMatching){
            this->startSelling(true, true);
            this->startMatching(false, true);
        }
    }

    if(this->inverseSelling && buy){
        this->startSelling(false, true);
        emit sendOrder("sell",
                       this->id,
                       this->stocksData[1]->code,
                       this->stocksData[1]->name,
                       this->stocksData[1]->condition.asksize / 100,
                       this->stocksData[1]->condition.ask,
                       data.asksize);
    }
}

void StockBox::startBuying(bool start, bool inverse){
    QString redButton = "font-size: 10px; font-family: \"Segoe UI\"; border: 0; color: " + WHITE_COLOR.name() + "; background-color:" + RED_COLOR.name();
    QString greenButton = "font-size: 10px; font-family: \"Segoe UI\"; border: 0; color: " + WHITE_COLOR.name() + "; background-color:" + GREEN_COLOR.name();

    if(!inverse){
        if(start){
            ui->startBuyingButton->setStyleSheet(redButton);
            ui->startBuyingButton->setText("Stop Buying");
            this->buying = true;
            this->test(stocksData[0]->data);
        }else{
            ui->startBuyingButton->setStyleSheet(greenButton);
            ui->startBuyingButton->setText("Start Buying");
            this->buying = false;
        }
    } else {
        if(start){
            ui->startInverseBuyingButton->setStyleSheet(redButton);
            ui->startInverseBuyingButton->setText("Stop Buying");
            this->inverseBuying = true;
            this->test(stocksData[0]->data);
        }else{
            ui->startInverseBuyingButton->setStyleSheet(greenButton);
            ui->startInverseBuyingButton->setText("Start Buying");
            this->inverseBuying = false;
        }
    }
}

void StockBox::startSelling(bool start, bool inverse){
    QString redButton = "font-size: 10px; font-family: \"Segoe UI\"; border: 0; color: " + WHITE_COLOR.name() + "; background-color:" + RED_COLOR.name();
    QString greenButton = "font-size: 10px; font-family: \"Segoe UI\"; border: 0; color: " + WHITE_COLOR.name() + "; background-color:" + GREEN_COLOR.name();
    if(!inverse){
        if(start){
            ui->startSellingButton->setStyleSheet(redButton);
            ui->startSellingButton->setText("Stop Selling");
            this->selling = true;
            this->test(stocksData[0]->data);
        }else{
            ui->startSellingButton->setStyleSheet(greenButton);
            ui->startSellingButton->setText("Start Selling");
            this->selling = false;
        }
    }else{
        if(start){
            ui->startInverseSellingButton->setStyleSheet(redButton);
            ui->startInverseSellingButton->setText("Stop Selling");
            this->inverseSelling = true;
            this->test(stocksData[0]->data);
        }else{
            ui->startInverseSellingButton->setStyleSheet(greenButton);
            ui->startInverseSellingButton->setText("Start Selling");
            this->inverseSelling = false;
        }
    }
}

void StockBox::startMatching(bool start, bool inverse){
    QString redButton = "font-size: 10px; font-family: \"Segoe UI\"; border: 0; color: " + WHITE_COLOR.name() + "; background-color:" + RED_COLOR.name();
    QString greenButton = "font-size: 10px; font-family: \"Segoe UI\"; border: 0; color: " + WHITE_COLOR.name() + "; background-color:" + GREEN_COLOR.name();
    if(!inverse){
        if(start){
            ui->startMatchingButton->setStyleSheet(redButton);
            ui->startMatchingButton->setText("Stop Matching");
            this->matching = true;
        }else{
            ui->startMatchingButton->setStyleSheet(greenButton);
            ui->startMatchingButton->setText("Start Matching");
            this->matching = false;
        }
    }else{
        if(start){
            ui->startInverseMatchingButton->setStyleSheet(redButton);
            ui->startInverseMatchingButton->setText("Stop Matching");
            this->inverseMatching = true;
        }else{
            ui->startInverseMatchingButton->setStyleSheet(greenButton);
            ui->startInverseMatchingButton->setText("Start Matching");
            this->inverseMatching = false;
        }
    }
}

void StockBox::copyAsk(){
    stocksData[0]->condition.ask = stocksData[0]->data.ask;
    stocksData[1]->condition.ask = stocksData[1]->data.ask;
    this->tableModel->updateData();
}

void StockBox::copyBid(){
    stocksData[0]->condition.bid = stocksData[0]->data.bid;
    stocksData[1]->condition.bid = stocksData[1]->data.bid;
    this->tableModel->updateData();
}

void StockBox::startBuyingButtonPressed(){
    this->startBuying(!this->buying);
}

void StockBox::startSellingButtonPressed(){
    this->startSelling(!this->selling);
}

void StockBox::startMatchingButtonPressed(){
    this->startMatching(!this->matching);
}

void StockBox::startInverseBuyingButtonPressed(){
    this->startBuying(!this->inverseBuying, true);
}

void StockBox::startInverseSellingButtonPressed(){
    this->startSelling(!this->inverseSelling, true);
}

void StockBox::startInverseMatchingButtonPressed(){
    this->startMatching(!this->inverseMatching, true);
}

void StockBox::closeEvent(QCloseEvent *event){
    if(!stocksData[0]->code.isNull()) emit unsubscribe(this, stocksData[0]->code);
    if(!stocksData[1]->code.isNull()) emit unsubscribe(this, stocksData[1]->code);
    emit removeStockBox(this);
    event->accept();
}

StockBox::~StockBox()
{
    delete ui;
}
