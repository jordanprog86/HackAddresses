#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T14:17:55
#
#-------------------------------------------------

QT       += core gui  network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HackAdresses
TEMPLATE = app


SOURCES += main.cpp \
    hackaddress.cpp

HEADERS  += \
    hackaddress.h

FORMS    += \
    hackaddress.ui
RC_ICONS  =icon.ico

RESOURCES += \
    data.qrc
