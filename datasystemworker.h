#ifndef DATASYSTEMWORKER_H
#define DATASYSTEMWORKER_H

#include <QObject>

class DataSystemWorker : public QObject
{
    Q_OBJECT
public:
    explicit DataSystemWorker(QObject *parent = nullptr);

signals:

};

#endif // DATASYSTEMWORKER_H
