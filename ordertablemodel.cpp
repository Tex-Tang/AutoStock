#include "ordertablemodel.h"

OrderTableModel::OrderTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    results.clear();
    buySound = new QMediaPlayer;
    buySound->setMedia(QUrl("qrc:/resources/sound/buy.mp3"));
    sellSound = new QMediaPlayer;
    sellSound->setMedia(QUrl("qrc:/resources/sound/sell.mp3"));
}

QVariant OrderTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
        case 0:
            return QString("#");
        case 1:
            return QString("ID");
        case 2:
            return QString("Start Time");
        case 3:
            return QString("End Time");
        case 4:
            return QString("Elapsed(ms)");
        case 5:
            return QString("Action");
        case 6:
            return QString("Status");
        case 7:
            return QString("Trigger Size");
        case 8:
            return QString("Code");
        case 9:
            return QString("Name");
        case 10:
            return QString("Price");
        case 11:
            return QString("Qty");
        case 12:
            return QString("Message");
        }
    }
    return QVariant();
}

int OrderTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return results.size();
}

int OrderTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 13;
}

QVariant OrderTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole){
        OrderResult result = results[index.row()];
        switch (index.column()) {
        case 0:
            return index.row();
        case 1:
            return result.id;
        case 2:
            return result.startTime.toString("hh:mm:ss.zzz");
        case 3:
            return result.endTime.toString("hh:mm:ss.zzz");
        case 4:
            return result.startTime.msecsTo(result.endTime);
        case 5:
            return result.action;
        case 6:
            if(result.status == 1) return "SUCCESS";
            else if(result.status == 2) return "FAILED";
            return "ERROR";
        case 7:
            return QLocale(QLocale::English).toString(result.triggerSize);
        case 8:
            return result.code;
        case 9:
            return result.name;
        case 10:
            return result.price;
        case 11:
            return result.qty;
        case 12:
            return result.response;
        }
    }
    return QVariant();
}


void OrderTableModel::addRow(OrderResult result){
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    results.push_back(result);
    endInsertRows();
    if(result.action == "buy") buySound->play();
    else sellSound->play();
}
