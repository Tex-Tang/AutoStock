#include "stockbox.h"
#include "ui_stockbox.h"

StockBox::StockBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockBox)
{
    ui->setupUi(this);
}

StockBox::~StockBox()
{
    delete ui;
}
