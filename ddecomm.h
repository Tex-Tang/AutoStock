#ifndef DDECOMM_H
#define DDECOMM_H
#pragma comment(lib,"User32.lib")
#include <QObject>
#include <QMutex>
#include "Windows.h"
#include "dde.h"
#include "ddeml.h"

#define DDECOMM_TIMEOUT_MS       5000
class DdeComm : public QObject
{
    Q_OBJECT
private:
    QMutex mSync;

public:
    DWORD mDdeInstance;
    explicit DdeComm(QObject *parent = 0);
    ~DdeComm();

public:
    /// @return     message if succeed, otherwise null string (.isNull() == true)
    QString request(QString application, QString topic, QString item, ulong timeoutInMs = DDECOMM_TIMEOUT_MS);
    bool poke(QString application, QString topic, QString item, QString text, ulong timeoutInMs = DDECOMM_TIMEOUT_MS);
    bool execute(QString application, QString topic, QString command, ulong timeoutInMs = DDECOMM_TIMEOUT_MS);

    // functions based on conversation
    /// @return     conversation to advise, number as conversation Id
    ///             if the function fails, the return value is 0L.
    ulong open(QString application, QString topic);
    /// @param      conversation    number as conversation Id
    bool close(unsigned long long conversation);

    bool advise(unsigned long long  conversation, QString item, ulong timeoutInMs = DDECOMM_TIMEOUT_MS);
    bool unadvise(unsigned long long  conversation, QString item, ulong timeoutInMs = DDECOMM_TIMEOUT_MS);
signals:
    void requested(unsigned long long  conversation, QString topic, QString item, QString text);
    void poked(unsigned long long  conversation, QString topic, QString item, QString text);
    void executed(unsigned long long  conversation, QString topic, QString command);

    void opened(unsigned long long  conversation, QString application, QString topic);
    void closed(unsigned long long  conversation);
    void advised(QString code, QString item, QString value);
    void adviceUpdated(unsigned long long  conversation, QString item, bool started);

    void log(QString msg);

};

extern DWORD dataSystemIdInst;
extern DdeComm* dataSystemDdeComm;

#endif // DDECOMM_H
