#include "stockboxtablespinboxdelegate.h"

StockBoxTableSpinBoxDelegate::StockBoxTableSpinBoxDelegate(QObject *parent)
    : QItemDelegate(parent)
{

}

QWidget *StockBoxTableSpinBoxDelegate::createEditor(
        QWidget *parent,
        const QStyleOptionViewItem &option,
        const QModelIndex &index) const
{
    if(index.column() == 6 || index.column() == 9){
        QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
        editor->setDecimals(3);
        editor->setFrame(false);
        editor->setRange(0, 2000000000);
        editor->setSingleStep(0.005);
        return editor;
    }
    if(index.column() == 8 || index.column() == 11){
        QSpinBox *editor = new QSpinBox(parent);
        editor->setFrame(false);
        editor->setRange(0, 2000000000);
        editor->setSingleStep(100);
        return editor;
    }
    if(index.column() == 7 || index.column() == 10){
        QSpinBox *editor = new QSpinBox(parent);
        editor->setFrame(false);
        editor->setRange(0, 100);
        editor->setSingleStep(1);
        return editor;
    }

    return QItemDelegate::createEditor(parent, option, index);
}

void StockBoxTableSpinBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    if(index.column() == 6 || index.column() == 9){
        double value = index.model()->data(index, Qt::EditRole).toDouble();
        QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
        spinBox->setValue(value);
    }
    else if(index.column() >= 6 && index.column() <= 11){
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
    }
}

void StockBoxTableSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    if(index.column() == 6 || index.column() == 9){
        QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
        spinBox->interpretText();
        double value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
    }
    else if(index.column() >= 6 && index.column() <= 11){
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
    }
}

void StockBoxTableSpinBoxDelegate::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
