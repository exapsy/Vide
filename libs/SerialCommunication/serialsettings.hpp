#ifndef SERIALSETTINGS_H
#define SERIALSETTINGS_H

#include <QObject>
#include <QException>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

class SerialSettings
{
public:
    SerialSettings( );
    SerialSettings( QString portName );
    SerialSettings( QString portName, quint32 baudRate );

    // Uses directly the QSerialPortInfo::availablePorts( ) function
    static QList<QSerialPortInfo> availablePorts( );
    // Returns all the portNames of the currently available ports
    static QList<QString> availablePortNames( );

    QString portName;
	qint32 baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBits;
    QSerialPort::FlowControl flowControl;
    QSerialPort::SerialPortError error;


};

#endif // SERIALSETTINGS_H
