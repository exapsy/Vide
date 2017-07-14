#include "serialsettings.hpp"
#include <QDebug>
SerialSettings::SerialSettings()
	: portName (QSerialPortInfo::availablePorts()[0].portName()), baudRate(QSerialPort::Baud9600)
	, dataBits(QSerialPort::Data8), parity(QSerialPort::NoParity)
	, stopBits(QSerialPort::OneStop), flowControl(QSerialPort::NoFlowControl)
{
	qDebug( ) << "port Instatiated - ";
	qDebug( ) << "portName:" << portName << endl;
}

SerialSettings::SerialSettings( QString portName )
	: portName ( portName ), baudRate( QSerialPort::Baud9600 )
	, dataBits( QSerialPort::Data8 ), parity( QSerialPort::NoParity )
	, stopBits( QSerialPort::OneStop ), flowControl( QSerialPort::NoFlowControl )
{
}

SerialSettings::SerialSettings( QString portName, quint32 baudRate )
	: portName ( portName ), baudRate( baudRate )
	, dataBits( QSerialPort::Data8 ), parity( QSerialPort::NoParity )
	, stopBits( QSerialPort::OneStop ), flowControl( QSerialPort::NoFlowControl )
{
}

QList<QSerialPortInfo> SerialSettings::availablePorts()
{
	return QSerialPortInfo::availablePorts();
}

QList<QString> SerialSettings::availablePortNames()
{
	QList<QSerialPortInfo> ports = availablePorts();
	QList<QString> portNames;
	qDebug() << "Available ports:" << endl;
	for ( const auto port: ports ) {
		portNames.append( port.portName() );
		qDebug() << "portName : " << port.portName() << endl;
	}

	return portNames;
}
