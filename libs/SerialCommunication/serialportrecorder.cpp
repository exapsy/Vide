#include "serialportrecorder.hpp"
#include <QThread>

SerialPortRecorder::SerialPortRecorder( QObject *parent, QWidget *widget )
	: QObject( parent ), widget( widget )
{
    serialOpenedAction = false;

	serial = new QSerialPort( this );
	connect ( serial, SIGNAL( readyRead( ) ),
			  this, SLOT( readData( ) ) );
}

SerialPortRecorder::~SerialPortRecorder()
{
	delete[] serial;
}

void SerialPortRecorder::setSettings(SerialSettings settings)
{
	this->settings = settings;
}

QByteArray SerialPortRecorder::getLastBytearray() const
{
	return lastBytearray;
}

bool SerialPortRecorder::isSerialOpen()
{
	return serial->isOpen();
}

void SerialPortRecorder::openSerialPort()
{
	serial->setPortName( settings.portName );
	serial->setBaudRate( settings.baudRate );
	serial->setDataBits( settings.dataBits );
	serial->setStopBits( settings.stopBits );
	serial->setFlowControl( settings.flowControl );
	serial->setParity( settings.parity );
	if ( serial->open(QIODevice::ReadWrite ) ) {
		emit serialOpened();
	} else {
		if ( widget ){
			QMessageBox::critical( widget, tr( "Could not connect to the port!" ),
								   tr( "Assure that your settings are correct.\nTry running the application with Root/Administrator privilleges." ) );
		} else {
			throw new QException();
		}
	}
    serialOpenedAction = true;

}

void SerialPortRecorder::closeSerialPort()
{
	serial->close();
	emit serialClosed();
}

void SerialPortRecorder::writeData( QByteArray &data )
{
	serial->write(data);
}

void SerialPortRecorder::readData()
{
	lastBytearray = serial->readAll();
    if ( serialOpenedAction ) {
        serialOpenedAction = false;
        // Remove the first 3 serial inputs ( ending with \r or \n ) to avoid False Data.
        for (int i = 0; i < 3 && lastBytearray.size() > 0; i++) {
            while ( !(lastBytearray.startsWith( '\n' ) ) && !(lastBytearray.startsWith( '\r' ) ) && lastBytearray.size( ) > 0 ) {
                lastBytearray.remove( 0, 1 );
            }
            while ( ( lastBytearray.startsWith( '\n' ) || lastBytearray.startsWith( '\r' ) ) && lastBytearray.size( ) > 0 ) {
                lastBytearray.remove( 0, 1 );
            }
        }


    }

    qDebug() << "--------------------------------" << endl;
    qDebug() << "\t🢂 Pre-Byte: \n" << lastBytearray << endl;
	emit bytearrayReloaded();
	QThread::msleep(50);
}
