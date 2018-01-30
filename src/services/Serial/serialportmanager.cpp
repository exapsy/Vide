#include "serialportmanager.hpp"


SerialPortManager::SerialPortManager(QObject *parent) : QObject(parent) {
    m_serial = new QSerialPort(this);
    m_lastBytesRead = new QByteArray();

    connect(m_serial, &QSerialPort::readyRead, this, &SerialPortManager::logData);
}

SerialPortManager::~SerialPortManager() {

}

void SerialPortManager::openSerialPort() {

    try {
        m_serial->setPortName(m_currentSettings.name);
        m_serial->setBaudRate(m_currentSettings.baudRate);
        m_serial->setDataBits(m_currentSettings.dataBits);
        m_serial->setParity(m_currentSettings.parity);
        m_serial->setStopBits(m_currentSettings.stopBits);
        m_serial->setFlowControl(m_currentSettings.flowControl);


    } catch(...) {
        qFatal("Error while trying to open a serial port.");
    }

    if (!m_serial->open(QIODevice::ReadOnly)) {
//        qFatal("Couldn't open serial port.");
        qDebug("Couldn't open serial port.");
        qDebug() << m_serial->errorString();
        return;
    }
    qDebug() << "\n\nOpened Serial Port!\n\n";
    emit connected();
}

void SerialPortManager::closeSerialPort() {
    if (m_serial->isOpen()) {
        m_serial->close();
        qDebug() << "\n\nClosed Serial Port!\n\n";
        emit disconnected();
    }
}
QVariant SerialPortManager::availablePorts() {
        QList<QSerialPortInfo> portsAvailable = QSerialPortInfo::availablePorts();
        QStringList names_PortsAvailable;
        for(const QSerialPortInfo& portInfo : portsAvailable) {
            names_PortsAvailable<<portInfo.portName();
        }
        return QVariant::fromValue(names_PortsAvailable);
}

QVariant SerialPortManager::availableBaudRates() {
    QStringList string_baudRates;
    for(const qint32 baudrate : QSerialPortInfo::standardBaudRates()) {
        string_baudRates.append(QString::number(baudrate));
    }

    return QVariant::fromValue(string_baudRates);
}

//void SerialPortManager::setSettings(QString portName)
//{
//    m_currentSettings.name = portName;
//    m_currentSettings.stringBaudRate = baudRate;
//    m_currentSettings.stringDataBits = dataBits;
//    m_currentSettings.stringParity = parity;
//    m_currentSettings.stringStopBits = stopBits;
//    m_currentSettings.stringFlowControl = flowControl;

//    m_currentSettings.baudRate = baudRate;
//    m_currentSettings.dataBits =  dataBits;
//    m_currentSettings.parity = parity;
//    m_currentSettings.stopBits = stopBits;
//    m_currentSettings.flowControl = flowControl;

//    emit settingsChanged();
//}

void SerialPortManager::readData() {
    *m_lastBytesRead = m_serial->readAll();
    emit dataRead();
//    QByteArray::iterator iter = m_lastBytesRead->begin();
//    while (iter != m_lastBytesRead->end() ) {
//        qDebug() << QChar(*iter);
//        iter++;
//    }
    //    qDebug() << "\n";
}


void SerialPortManager::updateSettings(QString portName, QString baudRate, QString dataBits, qint32 parity, qint32 stopBits, qint32 flowControl) {
    qDebug() << "\n\t\tSettings Changed !\n";
    qDebug() << "Current Settings: "
             << "\n\tportName "    << portName
             << "\n\tbaudRate "    << static_cast<QSerialPort::BaudRate>(baudRate.toInt())
             << "\n\tdataBits "    << static_cast<QSerialPort::DataBits>(dataBits.toInt())
             << "\n\tparity "      << static_cast<QSerialPort::Parity>(parity)
             << "\n\tstopBits "    << static_cast<QSerialPort::StopBits>(stopBits)
             << "\n\tflowControl " << static_cast<QSerialPort::FlowControl>(flowControl);

    m_currentSettings.name        = portName;
    m_currentSettings.baudRate    = static_cast<QSerialPort::BaudRate>(baudRate.toInt());
    m_currentSettings.dataBits    = static_cast<QSerialPort::DataBits>(dataBits.toInt());
    m_currentSettings.parity      = static_cast<QSerialPort::Parity>(parity);
    m_currentSettings.stopBits    = static_cast<QSerialPort::StopBits>(stopBits);
    m_currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(flowControl);
}

void SerialPortManager::logData() {
    *m_lastBytesRead = m_serial->readAll();
    qDebug() << *m_lastBytesRead;
}

SerialPortManager::SerialSettings SerialPortManager::currentSettings() const {
    return m_currentSettings;
}

QByteArray SerialPortManager::lastBytesRead() const {
    return *m_lastBytesRead;
}
