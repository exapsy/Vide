#ifndef SERIALPORTRECORDER_H
#define SERIALPORTRECORDER_H

#include <QObject>
#include <QException>
#include "libs/SerialCommunication/serialsettings.hpp"

class SerialPortRecorder : public QObject
{
    Q_OBJECT
public:
    SerialPortRecorder( QObject *parent = 0, QWidget *widget = 0 );
    ~SerialPortRecorder( );

    void setSettings ( SerialSettings settings );
    QByteArray getLastBytearray() const;
    bool isSerialOpen();


signals:
    // When a new ByteArray has been read from the SerialPort, signal is sent
    void bytearrayReloaded( );

    void serialOpened( );
    void serialClosed( );

public slots:

    void openSerialPort( );
    void closeSerialPort( );

    void writeData( QByteArray &data );
    void readData( );

private:
    // The last byteArray recorder from the SerialPort reader
    QByteArray lastBytearray;
    bool serialOpenedAction;

    QWidget *widget;
    QSerialPort *serial;
    SerialSettings settings;
};

#endif // SERIALPORTRECORDER_H
