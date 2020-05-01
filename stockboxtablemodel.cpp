#include "stockboxtablemodel.h"

StockBoxTableModel::StockBoxTableModel(QVector<StockBoxData*> stocks, QObject *parent)
    : QAbstractTableModel(parent)
{
    this->stocks = stocks;
}

QVariant StockBoxTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Bidrate");
        case 1:
            return QString("Bidsize");
        case 2:
            return QString("Bid");
        case 3:
            return QString("Ask");
        case 4:
            return QString("Asksize");
        case 5:
            return QString("Askrate");
        case 6:
            return QString("C Ask");
        case 7:
            return QString("C Askrate");
        case 8:
            return QString("C Asksize");
        case 9:
            return QString("C Bid");
        case 10:
            return QString("C Bidrate");
        case 11:
            return QString("C Bidsize");
        }
    }
    return QVariant();
}

bool StockBoxTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    /*if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }*/
    return false;
}


int StockBoxTableModel::rowCount(const QModelIndex &parent) const
{
    return stocks.size();
}

int StockBoxTableModel::columnCount(const QModelIndex &parent) const
{
    return 12;
}

QVariant StockBoxTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        StockBoxData* current_stock = stocks[index.row()];
        switch(index.column()){
        case 0:
            return current_stock->data.bidrate;
        case 1:
            return QLocale(QLocale::English).toString(current_stock->data.bidsize);
        case 2:
            return current_stock->data.bid;
        case 3:
            return current_stock->data.ask;
        case 4:
            return QLocale(QLocale::English).toString(current_stock->data.asksize);
        case 5:
            return current_stock->data.askrate;
        case 6:
            return current_stock->condition.ask;
        case 7:
            return current_stock->condition.askrate;
        case 8:
            return QLocale(QLocale::English).toString(current_stock->condition.asksize);
        case 9:
            return current_stock->condition.bid;
        case 10:
            return current_stock->condition.bidrate;
        case 11:
            return QLocale(QLocale::English).toString(current_stock->condition.bidsize);
        default:
            return false;
        }
    }else if(role == Qt::EditRole){
        StockBoxData* current_stock = stocks[index.row()];
        switch(index.column()){
        case 0:
            return current_stock->data.bidrate;
        case 1:
            return current_stock->data.bidsize;
        case 2:
            return current_stock->data.bid;
        case 3:
            return current_stock->data.ask;
        case 4:
            return current_stock->data.asksize;
        case 5:
            return current_stock->data.askrate;
        case 6:
            return current_stock->condition.ask;
        case 7:
            return current_stock->condition.askrate;
        case 8:
            return current_stock->condition.asksize;
        case 9:
            return current_stock->condition.bid;
        case 10:
            return current_stock->condition.bidrate;
        case 11:
            return current_stock->condition.bidsize;
        default:
            return false;
        }
    }else if(role == Qt::BackgroundColorRole && index.row() == 1){
        StockBoxData* current_stock = stocks[index.row()];
        switch(index.column()){
        case 6:
            if(current_stock->data.ask > current_stock->condition.ask) return GREEN_COLOR;
            else if(current_stock->data.ask < current_stock->condition.ask) return RED_COLOR;
            return WHITE_COLOR;
        case 9:
            if(current_stock->data.bid > current_stock->condition.bid) return GREEN_COLOR;
            else if(current_stock->data.bid < current_stock->condition.bid) return RED_COLOR;
            return WHITE_COLOR;
        }
    }
    return QVariant();
}

bool StockBoxTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        StockBoxData* current_stock = stocks[index.row()];
        switch(index.column()){
        case 6:
            current_stock->condition.ask = value.toDouble();
            break;
        case 7:
            current_stock->condition.askrate = value.toInt();
            break;
        case 8:
            current_stock->condition.asksize = value.toInt();
            break;
        case 9:
            current_stock->condition.bid = value.toDouble();
            break;
        case 10:
            current_stock->condition.bidrate = value.toInt();
            break;
        case 11:
            current_stock->condition.bidsize = value.toInt();
            break;
        default:
            return false;
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags StockBoxTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid() || index.column() <= 5)
        return Qt::ItemIsEnabled;

    return Qt::ItemIsSelectable |  Qt::ItemIsEditable |  Qt::ItemIsEnabled;
}

void StockBoxTableModel::updateData(int top, int left, int bottom, int right){
    emit dataChanged(createIndex(top, left), createIndex(bottom, right), QVector<int>() << Qt::DisplayRole);
}

