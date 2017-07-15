#-------------------------------------------------
#
# Project created by QtCreator 2017-07-04T12:19:41
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Vide
TEMPLATE = app

CONFIG += debug

SOURCES += main.cpp\
        mainwindow.cpp \
    libs/GraphPlot/qcustomplot.cpp \
    libs/SerialCommunication/serialdatamanager.cpp \
    libs/SerialCommunication/serialportrecorder.cpp \
    libs/SerialCommunication/serialsettings.cpp \
    libs/GraphPlot/plotmanager.cpp \
    libs/plotvariable.cpp

HEADERS  += mainwindow.h \
    libs/GraphPlot/qcustomplot.h \
    libs/SerialCommunication/serialdatamanager.hpp \
    libs/SerialCommunication/serialportrecorder.hpp \
    libs/SerialCommunication/serialsettings.hpp \
    libs/GraphPlot/plotmanager.h \
    libs/plotvariable.h

FORMS    += mainwindow.ui
