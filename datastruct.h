#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <QString>
#include <QVector>
#include <QMetaType>
#include <QDateTime>

#define DDE_APP "SIDE"

#define RAKUTEN_CONFIGURATION_COMMAND "window.prompt('Copy to clipboard: Ctrl+C, Enter', JSON.stringify({" \
                                      "session: session," \
                                      "appID: get_appID()," \
                                      "cookie: document.cookie, " \
                                      "accNo: '30035598'," \
                                      "tpin: '132339'" \
                                      "}));"

#define RED_COLOR QColor(231, 76, 60)
#define GREEN_COLOR QColor(46, 213, 115)
#define WHITE_COLOR QColor(255, 255, 255)

struct StockData{
    double  ask, bid;
    int asksize, bidsize;
    int askrate, bidrate;
    void reset() { ask = bid = asksize = bidsize = askrate = bidrate = -1; }
};

struct StockCondition{
    double  ask = 0, bid = 0;
    int asksize = 0, bidsize = 0;
    int askrate = 0, bidrate = 0;
};

struct StockBoxData{
    QString code;
    QString name;
    StockData data;
    StockCondition condition;
};

struct RakutenInfo{
    QString accNo;
    QString appID;
    QString tpin;
    QString session;
    QString cookie;
    bool valid(){
        return !(accNo.isEmpty() &&
                 appID.isEmpty() &&
                 tpin.isEmpty() &&
                 session.isEmpty() &&
                 cookie.isEmpty());
    }
};

struct OrderStatus{
    int id;
    QString name;
    QString code;
    bool buying = false;
    bool matching = false;
    bool selling = false;
    bool buyingInverse = false;
    bool matchingInverse = false;
    bool sellingInverse = false;
};

struct OrderResult{
    int id;
    QDateTime startTime;
    QDateTime endTime;
    QString action;
    int status;
    QString code;
    QString name;
    double price;
    int qty;
    QString response;
};

struct StockBoxJsonObject{
    int x;
    int y;
    QVector<StockBoxData> stocks;
};

#endif // DATASTRUCT_H
