#include "datasystem.h"

DataSystem::DataSystem(QObject *parent) : QObject(parent)
{
    dde = new DdeComm;
    dataSystemDdeComm = dde;
    dataSystemIdInst = dde->mDdeInstance;
    conversationMY = dde->open("SIDE","MY");
    conversationMD = dde->open("SIDE","MD");
    connect(dde, &DdeComm::log, this, &DataSystem::log);
    connect(dde, &DdeComm::advised, this, &DataSystem::receiveData);
}

void DataSystem::subscribe(StockBox* stockBox, QString code){
    if(!codeToStockData.contains(code)){
        StockData data;
        data.reset();
        codeToStockData[code] = data;
        codeToStockBoxes[code][stockBox] = 0;
        if(!startAdvise(code)){
            emit log("Advised failed : " + code);
        }
    }
    codeToStockBoxes[code][stockBox]++;
}

void DataSystem::unsubscribe(StockBox* stockBox, QString code){
    codeToStockBoxes[code][stockBox]--;
    if(codeToStockBoxes[code][stockBox] == 0){
        codeToStockBoxes[code].remove(stockBox);
    }
    if(codeToStockBoxes[code].size() == 0){
        codeToStockBoxes.remove(code);
        // stopAdvise(code);
    }
}

bool DataSystem::startAdvise(QString code){
    unsigned long long conv = code.contains("MD") ? conversationMD : conversationMY;
    return dde->advise(conv, code.replace(".MD","") + ";ask") &&
           dde->advise(conv, code.replace(".MD","") + ";bid") &&
           dde->advise(conv, code.replace(".MD","") + ";asksize") &&
           dde->advise(conv, code.replace(".MD","") + ";bidsize");
}

bool DataSystem::stopAdvise(QString code){
    unsigned long long conv = code.contains("MD") ? conversationMD : conversationMY;
    return dde->unadvise(conv, code.replace(".MD","") + ";ask") &&
           dde->unadvise(conv, code.replace(".MD","") + ";bid") &&
           dde->unadvise(conv, code.replace(".MD","") + ";asksize") &&
           dde->unadvise(conv, code.replace(".MD","") + ";bidsize");
}

void DataSystem::receiveData(QString code, QString item, QString value){

    StockData* data = &codeToStockData[code];
    switch(itemsIndex.indexOf(item)){
    case 0:
        if(data->ask < 0 && data->bid < 0 && data->asksize < 0 && data->bidsize < 0){
            data->ask = value.toDouble();
        }else{
            data->reset();
        }
        break;
    case 1:
        if(data->ask > 0 && data->bid < 0 && data->asksize < 0 && data->bidsize < 0){
            data->bid = value.toDouble();
        }else{
            data->reset();
        }
        break;
    case 2:
        if(data->ask > 0 && data->bid > 0 && data->asksize < 0 && data->bidsize < 0){
            data->asksize = value.toDouble();
        }else{
            data->reset();
        }
        break;
    case 3:
        if(data->ask > 0 && data->bid > 0 && data->asksize > 0 && data->bidsize < 0){
            data->bidsize = value.toDouble();
        }else{
            data->reset();
        }
        break;
    }
    bool updated = data->ask > 0 && data->bid > 0 && data->asksize > 0 && data->bidsize > 0;
    if(updated){
        double total_size = data->bidsize + data->asksize;
        if(total_size > 0){
            data->askrate = qRound((data->asksize / total_size)*100);
            data->bidrate = qRound((data->bidsize / total_size)*100);
        }else{
            data->askrate = data->bidrate = 100;
        }
        //emit update(code, codeToStockData[code]);
        for(StockBox* stockBox : codeToStockBoxes[code].keys()){
            QMetaObject::invokeMethod(stockBox, "update", Q_ARG(QString, code), Q_ARG(StockData, codeToStockData[code]));
        }
        data->reset();
    }
    emit log(QDateTime::currentDateTime().toString("hh:mm:ss.zzz") + " " + code + " " + item + "->" + value);
}
