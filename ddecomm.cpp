#include "ddecomm.h"
#include <QtDebug>

#define Log(X)  this->log(QString("%1: %2").arg(__FUNCTION__).arg((X)))

DWORD dataSystemIdInst;
DdeComm* dataSystemDdeComm;
HDDEDATA CALLBACK DdeCallBack(
        //DdeComm *comm, ulong *pIdInst,
        UINT uType,     // Transaction type.
        UINT uFmt,      // Clipboard data format.
        HCONV hconv,    // Handle to the conversation.
        HSZ hsz1,       // Handle to a string depends on the type of the current transaction.
        HSZ hsz2,       // Handle to a string depends on the type of the current transaction.
        HDDEDATA hdata, // Handle to a global memory object depends on the type of the current transaction.
        DWORD dwData1,  // Transaction-specific data.
        DWORD dwData2)  // Transaction-specific data.
{
    HDDEDATA ret = DDE_FNOTPROCESSED;
    DWORD idInst = dataSystemIdInst;
    // debug
    QString msg = QString("Callback: uType=%1h, uFmt=%2h, hconv=%3h, "
                          "hsz1=%4h, hsz2=%5h, hdata=%6h, dwData1=%7h, dwData2=%8h")
            .arg((ulong)uType, 0, 16)
            .arg((ulong)uFmt, 0, 16)
            .arg((ULONG64)hconv, 0, 16)
            .arg((ULONG64)hsz1, 0, 16)
            .arg((ULONG64)hsz2, 0, 16)
            .arg((ULONG64)hdata, 0, 16)
            .arg((ulong)dwData1, 0, 16)
            .arg((ulong)dwData2, 0, 16);
    //dataSystemDdeComm->log(msg);
    //Log(msg);

    if(idInst && uType == XTYP_ADVDATA && uFmt == CF_TEXT)
    {
        wchar_t strBuff[256];
        char szResult[1000];
        DWORD size;

        // conversation
        //ULONG64 conversation = (ULONG64)hconv;

        // topic
        size = DdeQueryString(idInst, hsz1, strBuff, sizeof(strBuff) / sizeof(wchar_t), CP_WINUNICODE);
        QString topic = QString::fromWCharArray(strBuff, size);
        DdeFreeStringHandle(idInst, hsz1);

        // item
        size = DdeQueryString(idInst, hsz2, strBuff, sizeof(strBuff) / sizeof(wchar_t), CP_WINUNICODE);
        QString item = QString::fromWCharArray(strBuff, size);
        DdeFreeStringHandle(idInst, hsz2);

        // data
        size = DdeGetData(hdata, (unsigned char *)szResult, sizeof(szResult), 0);
        QString text = QString(szResult);
        // fire event
        QStringList str = item.split(";");
        dataSystemDdeComm->advised(str.value(0), str.value(1), text);

        //comm->log(QString("Advised: conv=%1h, topic=%2, item=%3, text=%4")
        //          .arg((ULONG64)hconv, 0, 16).arg(topic).arg(item).arg(text));
        ret = (HDDEDATA)DDE_FACK;
    }
    return ret;
}

DdeComm::DdeComm(QObject *parent)
    : QObject(parent),
      mSync(QMutex::Recursive), mDdeInstance(0)
{
    /*auto lambda = [&] (UINT uType, UINT uFmt, HCONV hconv, HSZ hsz1, HSZ hsz2,
            HDDEDATA hdata, DWORD dwData1,DWORD dwData2 ) -> HDDEDATA {
        return DdeCallbackLocal(this, &mDdeInstance, uType, uFmt, hconv, hsz1, hsz2, hdata, dwData1, dwData2);
    };
    singleton<decltype(lambda)>::set_instance(lambda);
    PFNCALLBACK callback = &lambda_caller<decltype(lambda)>;*/

    DWORD inst = 0;
    UINT result = DdeInitialize(&inst, (PFNCALLBACK)DdeCallBack, APPCLASS_STANDARD | APPCMD_CLIENTONLY ,0);
    // HOWTO
    //    UINT result = DdeInitialize(
    //                (LPDWORD) &inst,  // instance identifier
    //                &DdeCallback,        // pointer to callback function
    //                APPCLASS_MONITOR |  // this is a monitoring application
    //                MF_CALLBACKS     |  // monitor callback functions
    //                MF_CONV          |  // monitor conversation data
    //                MF_ERRORS        |  // monitor DDEML errors
    //                MF_HSZ_INFO      |  // monitor data handle activity
    //                MF_LINKS         |  // monitor advise loops
    //                MF_POSTMSGS      |  // monitor posted DDE messages
    //                MF_SENDMSGS,        // monitor sent DDE messages
    //                0);                 // reserved

    if (result == DMLERR_NO_ERROR) {
        mDdeInstance = inst;
        Log(tr("DDE initialization succeeded: instance=%1h").arg((ulong)inst, 0, 16));
    }
    else {
        Log(tr("DDE initialization failed: result=%1h").arg((ulong)result, 0, 16));
    }
}

DdeComm::~DdeComm()
{
    DdeUninitialize(mDdeInstance);
    mDdeInstance = 0;

    Log(tr("DDE released"));
}

static inline HCONV _openConv(DWORD idInst, QString application, QString topic)
{
    //DDE Connect to Server using given AppName and topic.
    HSZ hszApp = DdeCreateStringHandle(idInst, application.toStdWString().c_str(), 0);
    HSZ hszTopic = DdeCreateStringHandle(idInst, topic.toStdWString().c_str(), 0);
    HCONV hConv = DdeConnect(idInst, hszApp, hszTopic, NULL); // If the function fails, the return value is 0L.
    DdeFreeStringHandle(idInst, hszApp);
    DdeFreeStringHandle(idInst, hszTopic);

    //    If the function succeeds, the return value is the handle to the established conversation.
    //    If the function fails, the return value is 0L.
    return hConv;
}

static inline BOOL _closeConv(HCONV hConv)
{
    //    If the function succeeds, the return value is nonzero.
    //    If the function fails, the return value is zero.
    return DdeDisconnect(hConv);
}

QString DdeComm::request(QString application, QString topic, QString item, ulong timeoutInMs)
{
    QString text = 0;
    DWORD idInst = mDdeInstance;
    HCONV hConv = _openConv(idInst, application, topic);
    ulong conversation = (ULONG64)hConv;
    if (hConv) {
        HSZ hszItem = DdeCreateStringHandle(idInst, item.toStdWString().c_str(), CP_WINUNICODE);
        HDDEDATA hData = DdeClientTransaction(NULL, 0, hConv, hszItem, CF_TEXT, XTYP_REQUEST, timeoutInMs, NULL);
        DdeFreeStringHandle(idInst, hszItem);

        if (hData)
        {
            char szResult[255];
            DWORD size = DdeGetData(hData, (unsigned char *)szResult, sizeof(szResult), 0);
            text = QString(szResult);
            requested(conversation, topic, item, text);
        }
        else {
            UINT errCode = DdeGetLastError(mDdeInstance);
            Log(tr("No request transaction: app=%1, topic=%2, item=%3, errCode=%4h")
                .arg(application).arg(topic).arg(item).arg(errCode, 0, 16));
        }
        _closeConv(hConv);
    }
    else {
        UINT errCode = DdeGetLastError(mDdeInstance);
        Log(tr("No conversation opened: errCode=%1h").arg(errCode, 0, 16));
    }
    return text;
}

bool DdeComm::poke(QString application, QString topic, QString item, QString text, ulong timeoutInMs)
{
    bool ret = false;
    DWORD idInst = mDdeInstance;
    HCONV hConv = _openConv(idInst, application, topic);
    ulong conversation = (ULONG64)hConv;
    if (hConv) {
        HSZ hszItem = DdeCreateStringHandle(idInst, item.toStdWString().c_str(), CP_WINUNICODE);
        QByteArray byteArray = text.toLocal8Bit();
        byteArray.append((char)0);  // zero terminated string
        if (DdeClientTransaction((LPBYTE)byteArray.data(), byteArray.size(),
                                 hConv, hszItem, CF_TEXT, XTYP_POKE, timeoutInMs, NULL)) {
            ret = true;
        }
        DdeFreeStringHandle(idInst, hszItem);
        _closeConv(hConv);
        poked(conversation, topic, item, text);
    }
    else {
        UINT errCode = DdeGetLastError(mDdeInstance);
        Log(tr("No conversation opened: errCode=%1h").arg(errCode, 0, 16));
    }
    return ret;
}

bool DdeComm::execute(QString application, QString topic, QString command, ulong timeoutInMs)
{
    bool ret = false;
    DWORD idInst = mDdeInstance;
    HCONV hConv = _openConv(idInst, application, topic);
    ulong conversation = (ULONG64)hConv;
    if (hConv) {
        QByteArray byteArray = command.toLocal8Bit();
        byteArray.append((char)0);  // zero terminated string
        HDDEDATA hData = DdeCreateDataHandle(idInst, (LPBYTE)byteArray.data(), byteArray.size(), 0, NULL, CF_TEXT, 0);
        if (hData)   {
            DdeClientTransaction((LPBYTE)hData, 0xFFFFFFFF, hConv, 0L, 0, XTYP_EXECUTE, timeoutInMs, NULL);
            DdeFreeDataHandle(hData);
            executed(conversation, topic, command);
            ret = true;
        }
        else {
            UINT errCode = DdeGetLastError(mDdeInstance);
            Log(tr("Command failed: app=%1, topic=%2, cmd=%3, errCode=%4h")
                .arg(application).arg(topic).arg(command).arg(errCode, 0, 16));
        }
        _closeConv(hConv);
    }
    else {
        UINT errCode = DdeGetLastError(mDdeInstance);
        Log(tr("No conversation opened: errCode=%1h").arg(errCode, 0, 16));
    }
    return ret;
}

ulong DdeComm::open(QString application, QString topic)
{
    QMutexLocker lock(&mSync);
    DWORD idInst = mDdeInstance;
    HCONV hConv = _openConv(idInst, application, topic);
    ulong conversation = (ULONG64)hConv;
    if (hConv) {
        Log(tr("New conversation opened: application=%1, topic=%2, conv=%3h")
            .arg(application).arg(topic).arg(conversation, 0, 16));
        opened(conversation, application, topic);
    }
    else {
        UINT errCode = DdeGetLastError(mDdeInstance);
        Log(tr("No conversation opened: application=%1, topic=%2, errCode=%3h")
            .arg(application).arg(topic).arg(errCode, 0, 16));
    }
    return conversation;
}

bool DdeComm::close(ULONG64 conversation)
{
    bool ret = false;
    QMutexLocker lock(&mSync);
    HCONV hConv = (HCONV)conversation;
    BOOL retConv = _closeConv(hConv);
    if (retConv) {
        Log(tr("Conversation closed: conv=%1h").arg(conversation, 0, 16));
        closed(conversation);
        ret = true;
    }
    else {
        UINT errCode = DdeGetLastError(mDdeInstance);
        Log(tr("No conversation closed: conv=%1h, errCode=%2h")
            .arg(conversation, 0, 16).arg(errCode, 0, 16));
    }
    return ret;
}

bool DdeComm::advise(unsigned long long conversation, QString item, ulong timeoutInMs)
{
    bool ret = false;
    QMutexLocker lock(&mSync);
    DWORD idInst = mDdeInstance;
    HCONV hConv = (HCONV) conversation;
    if (hConv) {
        HSZ hszItem = DdeCreateStringHandle(idInst, item.toStdWString().c_str(), CP_WINUNICODE);
        HDDEDATA hData = DdeClientTransaction(NULL, 0, hConv, hszItem, CF_TEXT, XTYP_ADVSTART, timeoutInMs, NULL);
        DdeFreeStringHandle(idInst, hszItem);
        if (hData) {
            Log(tr("New advice started: conv=%1h, item=%2")
                .arg(conversation, 0, 16).arg(item));
            adviceUpdated(conversation, item, true);
            ret = true;
        }
        else {
            UINT errCode = DdeGetLastError(mDdeInstance);
            Log(tr("No advice transaction: conv=%1h, item=%2, errCode=%3h")
                .arg(conversation, 0, 16).arg(item).arg(errCode, 0, 16));
        }
    }
    else
        Log(tr("No conversation opened"));
    return ret;
}

bool DdeComm::unadvise(unsigned long long conversation, QString item, ulong timeoutInMs)
{
    bool ret = false;
    QMutexLocker lock(&mSync);
    DWORD idInst = mDdeInstance;
    HCONV hConv = (HCONV)conversation;
    if (hConv) {
        HSZ hszItem = DdeCreateStringHandle(idInst, item.toStdWString().c_str(), CP_WINUNICODE);
        HDDEDATA hData = DdeClientTransaction(NULL, 0, hConv, hszItem, CF_TEXT, XTYP_ADVSTOP, timeoutInMs, NULL);
        DdeFreeStringHandle(idInst, hszItem);
        if (hData) {
            Log(tr("Advice canceled: conv=%1h, item=%2").arg(conversation, 0, 16).arg(item));
            adviceUpdated(conversation, item, false);
            ret = true;
        }
        else {
            UINT errCode = DdeGetLastError(mDdeInstance);
            Log(tr("No advice transaction: conv=%1h, item=%2, errCode=%3h")
                .arg(conversation, 0, 16).arg(item).arg(errCode, 0, 16));
        }
        _closeConv(hConv);
    }
    else
        Log(tr("No conversation opened"));
    return ret;
}
