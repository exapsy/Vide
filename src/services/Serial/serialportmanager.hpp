#ifndef SERIALPORTMANAGER_HPP
#define SERIALPORTMANAGER_HPP

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QtGlobal>
#include <QDebug>
#include <QQmlListProperty>
#include <QVariant>

QT_BEGIN_NAMESPACE

namespace Serial {
    class SerialPortManager;
}

QT_END_NAMESPACE

class SerialPortManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QByteArray lastBytesRead READ lastBytesRead NOTIFY dataRead)

public:
    struct SerialSettings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
    };

    explicit SerialPortManager(QObject *parent = 0);
    ~SerialPortManager();

    struct SerialSettings currentSettings() const;
    QByteArray lastBytesRead() const;
    Q_INVOKABLE QVariant availablePorts();
    Q_INVOKABLE QVariant availableBaudRates();


signals:

public slots:
    Q_INVOKABLE void openSerialPort();
    Q_INVOKABLE void closeSerialPort();
//    void setSettings(QString portName);
    Q_INVOKABLE void readData();
    Q_INVOKABLE void updateSettings(QString portName, QString baudRate, QString dataBits, qint32  parity, qint32 stopBits, qint32 flowControl);
    void logData();

signals:
    void connected();
    void disconnected();
    void dataRead();
    void settingsChanged();
private:
    QSerialPort *m_serial;
    struct SerialSettings m_currentSettings;
    QByteArray *m_lastBytesRead;
};

#endif // SERIALPORTMANAGER_HPP
