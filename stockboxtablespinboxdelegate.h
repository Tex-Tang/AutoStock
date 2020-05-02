#ifndef STOCKBOXTABLESPINBOXDELEGATE_H
#define STOCKBOXTABLESPINBOXDELEGATE_H

#include <QItemDelegate>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QtDebug>
class StockBoxTableSpinBoxDelegate: public QItemDelegate
{
    Q_OBJECT

public:
    StockBoxTableSpinBoxDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
};

#endif // STOCKBOXTABLESPINBOXDELEGATE_H
