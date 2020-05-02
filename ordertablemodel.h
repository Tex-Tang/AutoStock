#ifndef ORDERTABLEMODEL_H
#define ORDERTABLEMODEL_H

#include <QAbstractTableModel>
#include <QUrl>
#include <QVector>
#include <QDateTime>
#include <QMediaPlayer>
#include "datastruct.h"

class OrderTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit OrderTableModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    void addRow(OrderResult result);

private:
    QVector <OrderResult> results;
    QMediaPlayer* buySound;
    QMediaPlayer* sellSound;
};

#endif // ORDERTABLEMODEL_H
