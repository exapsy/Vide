QT += qml quick serialport charts

CONFIG += c++11

SOURCES += main.cpp \
    src/services/Serial/serialportmanager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/services/Serial/serialportmanager.hpp
