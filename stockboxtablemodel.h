#ifndef STOCKBOXTABLEMODEL_H
#define STOCKBOXTABLEMODEL_H

#include <QColor>
#include <QtDebug>
#include <QLocale>
#include <QColor>
#include <QAbstractTableModel>
#include "datastruct.h"

class StockBoxTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit StockBoxTableModel(QVector<StockBoxData*> stocks, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void updateData(int top = 0, int left = 0, int bottom = 1, int right = 11);

private:
    QVector<StockBoxData*> stocks;
};

#endif // STOCKBOXTABLEMODEL_H
