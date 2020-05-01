#include "stockbox.h"
#include "ui_stockbox.h"

StockBox::StockBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockBox)
{
    ui->setupUi(this);
    ddeComm = new DdeComm;
    stocksData.append(new StockBoxData);
    stocksData.append(new StockBoxData);
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
}

void StockBox::changeCode(){
    if(ui->stockCodeLineEdit->text() != stocksData[0]->name){
        QString new_code = ui->stockCodeLineEdit->text();
        StockBoxData result = request(new_code);
        if(!result.name.isEmpty()){
            if(!stocksData[0]->code.isNull()) emit unsubscribe(this, stocksData[0]->code);
            stocksData[0]->code = result.code;
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
            stocksData[1]->code = result.code;
            stocksData[1]->name = result.name;
            stocksData[1]->data = result.data;
            emit subscribe(this, new_code);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error" ,"Couldn't fetch stock with code :" + new_code);
            ui->warrantCodeLineEdit->setText(stocksData[1]->code);
        }
    }
    this->tableModel->updateData(0,0,1,9);
}

StockBoxData StockBox::request(QString code){
    StockBoxData result = StockBoxData();
    QString topic = code.contains(".MD") ? "MD" : "MY";
    code = code.replace(".MD", "");
    result.name = ddeComm->request(DDE_APP, topic, code + ";shortname");
    if(!result.name.isEmpty()){
        result.code = code;
        result.data.ask = ddeComm->request(DDE_APP, topic, code + ";ask").toDouble();
        result.data.bid = ddeComm->request(DDE_APP, topic, code + ";bid").toDouble();
        result.data.asksize = ddeComm->request(DDE_APP, topic, code + ";asksize").toInt();
        result.data.bidsize = ddeComm->request(DDE_APP, topic, code + ";bidsize").toInt();
        double total_size = result.data.bidsize +  result.data.asksize;
        if(total_size > 0){
             result.data.askrate =  result.data.asksize / total_size;
             result.data.bidrate =  result.data.bidsize / total_size;
        }else{
             result.data.askrate =  result.data.bidrate = 100;
        }
    }
    return result;
}

void StockBox::update(QString code, StockData data){
    if(stocksData[0]->code == code){
        stocksData[0]->data = data;
    }
    if(stocksData[1]->code == code){
        stocksData[1]->data = data;
    }
    this->tableModel->updateData(0,0,1,9);
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
