#include "ordersystem.h"

OrderSystem::OrderSystem(QObject *parent) : QObject(parent)
{
    aes = new AES;
    info = RakutenInfo();
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(requestDone(QNetworkReply*)));
    networkRequest.setUrl(QUrl("https://www.rakutentrade.my/login/modal/place_order"));
    networkRequest.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    networkRequest.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36");
    networkRequest.setRawHeader("Cookie", "_ga=GA1.2.1257780546.1576500775; _fbp=fb.1.1576500775561.1573510695; rt_member=member; rt_user=returning; _gcl_au=1.1.900520323.1585120182; _gid=GA1.2.803465012.1587741748; signupchannel=web; api_url=https%3A%2F%2Fwww.rakutentrade.my; XSRF-TOKEN=eyJpdiI6InMrT1JWVm5GSUFsRU1zaWhmSnI4aGc9PSIsInZhbHVlIjoiTmxDMVVBZG84XC9CWXdCT2V3QWFQUVk1elRoR09vOXVMMyt0Qk1OTVp2UG43dTFMaHE1b01hcWZuVWphWWZyTVciLCJtYWMiOiI5ODU2OWZkNTUwN2I4YTkwYTQwNDVlYjc4ODllNDdmNTBjYmRlYWMxYWRkY2U5ZTM1YWYxMDA0ODAxOWE4NzhjIn0%3D; rakuten_trade_session=eyJpdiI6ImpWV3J6NGFwVWgyRzRRRWdjVTlGMEE9PSIsInZhbHVlIjoiMGhOb1NWUFpEekJvZGZFSnVsYm12RFFHb09TSFBBVXNpZCtLUnhrc3dnaFRSUEQ3MklyWnBFa0xvNmVRRVBjQSIsIm1hYyI6IjcwMzdjNjYxM2U0YjYwY2YyOWMwNzc2ZDY5MDRiODU3YTVkN2NiNzVlYmI3MzMxZTQ3ZWZmMTE3ZTAwNjI1ZGIifQ%3D%3D");
    networkRequest.setRawHeader("X-Requested-With", "XMLHttpRequest");
    networkRequest.setRawHeader("Accept", "*/*");
    networkRequest.setRawHeader("Origin", "https://www.rakutentrade.my");
    networkRequest.setRawHeader("Sec-Fetch-Site", "same-origin");
    networkRequest.setRawHeader("Sec-Fetch-Mode", "cors");
    networkRequest.setRawHeader("Sec-Fetch-Dest", "empty");
    networkRequest.setRawHeader("Referer", "https://www.rakutentrade.my/login/");
    //networkRequest.setRawHeader("Accept-Encoding", "gzip, deflate, br");
    networkRequest.setRawHeader("Accept-Language", "zh-CN,zh;q=0.9,en;q=0.8");
}

void OrderSystem::receiveOrder(QString action, int id, QString code, QString name, int qty, double price, int triggerSize){
    OrderResult result = OrderResult();
    result.id = id;
    result.startTime = QDateTime::currentDateTime();
    result.action = action;
    result.code = code;
    result.name = name;
    result.price = price;
    result.qty = qty;
    result.triggerSize = triggerSize;
    if(this->info.valid()){
        QNetworkReply* reply = networkManager->post(networkRequest, requestData(action, name, qty, price));
        reply->setProperty("id", result.id);
        reply->setProperty("qty", result.qty);
        reply->setProperty("name", result.name);
        reply->setProperty("code", result.code);
        reply->setProperty("action", result.action);
        reply->setProperty("startTime", result.startTime);
        reply->setProperty("triggerSize", result.triggerSize);
    }else{
        result.status = 0;
        result.endTime = QDateTime::currentDateTime();
        result.response = "Please Filled in rakuten info";
        emit sendOrderResult(result);
    }
    emit log(QDateTime::currentDateTime().toString("hh:mm:ss.zzz") + " START " + action + " " + QString::number(id) + " " + code);
}

void OrderSystem::requestDone(QNetworkReply *reply)
{
    OrderResult result = OrderResult();
    result.id = reply->property("id").toInt();
    result.startTime = reply->property("startTime").toDateTime();
    result.endTime = QDateTime::currentDateTime();
    result.action = reply->property("action").toString();
    result.code = reply->property("code").toString();
    result.name = reply->property("name").toString();
    result.price = reply->property("price").toDouble();
    result.qty = reply->property("qty").toInt();
    result.triggerSize = reply->property("triggerSize").toInt();
    result.status = 0;
    if(reply->error() == QNetworkReply::NoError){
        QJsonObject response_obj = QJsonDocument::fromJson(reply->readAll()).object().value("response").toObject();
        if(!response_obj.isEmpty()){
            if(response_obj.contains("infoMsg")){
                result.status = 2;
                result.response = response_obj.value("infoMsg").toString();
            }else if(response_obj.contains("data")){
                result.status = 1;
                result.response = response_obj.value("data").toObject().value("orderNo").toString();
            }else{
                result.status = 0;
                result.response = reply->readAll();
            }
        }else{
            result.status = 0;
            result.response = reply->readAll();
        }
    }else{
        result.status = 0;
        result.response = reply->errorString();
    }
    emit sendOrderResult(result);
    emit log(QDateTime::currentDateTime().toString("hh:mm:ss.zzz") + " DONE " + result.action + " " + QString::number(result.id) + " " + result.code);
    reply->deleteLater();
}

void OrderSystem::changeRakutenInfo(RakutenInfo info){
    this->info = info;
}

QByteArray OrderSystem::requestData(QString odrSide, QString mrktsym, int qty, double price){

    QJsonObject request_data{
        {"session", QJsonValue::fromVariant(aes->Encrypt(info.session.toStdString(), RAKUTEN_PASSPHRASE))},
        {"offline", "1"},
    };
    QJsonObject request
    {
        {"name"        , "place_order"},
        {"request_name", "place_order"},
        {"json"        , true},
        {"attr"        , QJsonObject{
                {"request", QJsonObject{
                        {"appID", info.appID},
                        {"data", QJsonObject{
                                {"accNo"   , info.accNo},
                                {"odrSide" , odrSide},
                                {"odrType" , "limit"},
                                {"expType" , "DAY"},
                                {"expDate" , ""},
                                {"oddLot"  , false},
                                {"mrktsym" , mrktsym},
                                {"qty"     , QString::number(qty)},
                                {"odrDate" , QDate::currentDate().toString("yyyy-MM-dd")},
                                {"lmtPrice", QString::number(price,'f',3)},
                                {"tpin"    , info.tpin}
                            }
                        }
                    }
                },
                {"echo", QJsonObject{
                        {"requestOwner","place_order"}
                    }
                }
            }
        },
        {"requestAttributes", QJsonObject{
                {"name", "place_order"},
                {"statusMessageDiv", "#widget_order_pad .status"},
                {"hideProgressMessage", false}
            }
        }
    };

    QString result;
    QJsonDocument doc(request);
    request_data.insert("data", QJsonValue::fromVariant(
                                         aes->Encrypt(doc.toJson(QJsonDocument::Compact).toStdString(),
                                         RAKUTEN_PASSPHRASE)));
    return QJsonDocument(request_data).toJson(QJsonDocument::Compact);
}
