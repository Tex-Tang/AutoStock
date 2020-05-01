#include "logger.h"
#include <QtDebug>
Logger::Logger(QObject *parent) : QObject(parent)
{
    if(!QDir("Log").exists()){
        QDir().mkdir("Log");
    }
    QString filename = QDateTime::currentDateTime().toString("yyyy-mm-dd-hh.mm.ss");
    file = new QFile("Log/" + filename + ".txt");
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    text = new QTextStream(file);
}

void Logger::log(QString msg){
    QTextStream  out(file);
    out << msg << "\n";
}
