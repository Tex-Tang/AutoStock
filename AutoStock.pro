QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network multimedia

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = icon.ico

SOURCES += \
    datasystem.cpp \
    datasystemworker.cpp \
    ddecomm.cpp \
    logger.cpp \
    loggerworker.cpp \
    main.cpp \
    mainwindow.cpp \
    ordersystem.cpp \
    ordersystemworker.cpp \
    ordertablemodel.cpp \
    stockbox.cpp \
    aes.cpp \
    stockboxtablemodel.cpp \
    stockboxtablespinboxdelegate.cpp

HEADERS += \
    datastruct.h \
    datasystem.h \
    datasystemworker.h \
    ddecomm.h \
    logger.h \
    loggerworker.h \
    mainwindow.h \
    ordersystem.h \
    ordersystemworker.h \
    ordertablemodel.h \
    stockbox.h \
    aes.h \
    stockboxtablemodel.h \
    stockboxtablespinboxdelegate.h

FORMS += \
    mainwindow.ui \
    stockbox.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/'../../../../Program Files/OpenSSL-Win64/lib/' -llibcrypto

INCLUDEPATH += $$PWD/'../../../../Program Files/OpenSSL-Win64/include'
DEPENDPATH += $$PWD/'../../../../Program Files/OpenSSL-Win64/include'

unix|win32: LIBS += -L$$PWD/'../../../../Program Files/OpenSSL-Win64/lib/' -lopenssl

INCLUDEPATH += $$PWD/'../../../../Program Files/OpenSSL-Win64/include'
DEPENDPATH += $$PWD/'../../../../Program Files/OpenSSL-Win64/include'

RESOURCES += \
    resources.qrc
