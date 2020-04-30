#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <QString>

struct StockData{
    double  ask, bid;
    int asksize, bidsize;
    int askrate, bidrate;
    void reset() { ask = bid = asksize = bidsize = askrate = bidrate = -1; }
};

struct StockCondition{
    double  ask, bid;
    int asksize, bidsize;
    int askrate, bidrate;
};

struct StockBoxData{
    QString shortname;
    StockData data;
    StockCondition condition;
};

#endif // DATASTRUCT_H
