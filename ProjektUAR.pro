QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UAR.cpp \
    arx.cpp \
    main.cpp \
    mainwindow.cpp \
    network.cpp \
    oknoarx.cpp \
    oknosiec.cpp \
    qcustomplot.cpp \
    regulator.cpp \
    symulacja.cpp \
    zadajnik.cpp

HEADERS += \
    UAR.h \
    arx.h \
    arxStan.h \
    mainwindow.h \
    network.h \
    oknoarx.h \
    oknosiec.h \
    qcustomplot.h \
    regulator.h \
    symulacja.h \
    symulacjaStan.h \
    trybSieciowy.h \
    zadajnik.h

FORMS += \
    mainwindow.ui \
    oknoarx.ui \
    oknosiec.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
