import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

import com.Vide.qml 1.0
import "../../../UI/"
import "../../../Styles"

Flickable {
    id: root
    height: parent.height
    contentHeight: portNameComboBox.height + baudRateComboBox.height + dataBitsComboBox.height + parityComboBox.height + stopBitsComboBox.height + flowControlComboBox.height + startButton.height + 8*11
    signal comboBoxChanged
    ScrollBar.vertical: ScrollBar {
        parent: root.parent
        anchors.top: root.top
        anchors.left: root.right
        anchors.bottom: root.bottom
    }

    VideComboBox {
        id: portNameComboBox
        anchors.top: parent.top
        anchors.topMargin: 11
        anchors.left: parent.left
        anchors.right: parent.right

        header: "PORT NAME"
        currentComboIndex: 0
        model: serialPortManager.availablePorts()
        onCurrentComboIndexChanged: {
            comboBoxChanged()
        }
    }

    VideComboBox {
        id: baudRateComboBox
        anchors.top: portNameComboBox.bottom
        anchors.topMargin: 11
        anchors.left: parent.left
        anchors.right: parent.right

        header: "BAUD RATE"
        currentComboIndex: 12
        model: serialPortManager.availableBaudRates()
        onCurrentComboIndexChanged: {
            comboBoxChanged()
        }
    }

    VideComboBox {
        id: dataBitsComboBox
        anchors.top: baudRateComboBox.bottom
        anchors.topMargin: 11
        anchors.left: parent.left
        anchors.right: parent.right

        header: "DATA BITS"
        currentComboIndex: 3
        model: ["5", "6", "7", "8"]
        onCurrentComboIndexChanged: {
            comboBoxChanged()
        }
    }

    VideComboBox {
        id: parityComboBox
        anchors.top: dataBitsComboBox.bottom
        anchors.topMargin: 11
        anchors.left: parent.left
        anchors.right: parent.right

        header: "PARITY"
        currentComboIndex: 0
        model: ["No Parity", "Even", "Odd", "Space", "Mark"]
        onCurrentComboIndexChanged: {
            comboBoxChanged()
        }
    }

    VideComboBox {
        id: stopBitsComboBox
        anchors.top: parityComboBox.bottom
        anchors.topMargin: 11
        anchors.left: parent.left
        anchors.right: parent.right

        header: "STOP BITS"
        currentComboIndex: 0
        model: ["1",  "2", "1.5"]
        onCurrentComboIndexChanged: {
            comboBoxChanged()
        }
    }

    VideComboBox {
        id: flowControlComboBox
        anchors.top: stopBitsComboBox.bottom
        anchors.topMargin: 11
        anchors.left: parent.left
        anchors.right: parent.right

        header: "FLOW CONTROL"
        model: ["No Flow Control", "Hardware Control", "Software Control"]
        currentComboIndex: 1
        onCurrentComboIndexChanged: {
            comboBoxChanged()
        }
    }

    Button {
        id: startButton
        anchors.top: flowControlComboBox.bottom
        anchors.topMargin: 11
        anchors.horizontalCenter: parent.horizontalCenter

        text: "START"
        property bool connected: false

        onClicked: {
            if (!connected) {
                serialPortManager.openSerialPort();
            } else {
                serialPortManager.closeSerialPort();
            }
            connected = !connected;
        }

        SerialPortManager {
            id: serialPortManager
            onConnected: {
                startButton.text = "STOP"
            }
            onDisconnected: {
                startButton.text = "START"
            }
            onDataRead: {
                terminal.input= getLastBytesRead()
            }
        }

    }
    onComboBoxChanged: {
        serialPortManager.updateSettings(portNameComboBox.model[portNameComboBox.currentComboIndex],
                                         baudRateComboBox.model[baudRateComboBox.currentComboIndex],
                                         dataBitsComboBox.model[dataBitsComboBox.currentComboIndex],
                                         parityComboBox.currentComboIndex+1 == 1 ? 0 : parityComboBox.currentComboIndex+1,
                                         stopBitsComboBox.currentComboIndex + 1,
                                         flowControlComboBox.currentComboIndex)
    }
    Component.onCompleted: {
        serialPortManager.updateSettings(portNameComboBox.model[portNameComboBox.currentComboIndex],
                                         baudRateComboBox.model[baudRateComboBox.currentComboIndex],
                                         dataBitsComboBox.model[dataBitsComboBox.currentComboIndex],
                                         parityComboBox.currentComboIndex+1 == 1 ? 0 : parityComboBox.currentComboIndex+1,
                                         stopBitsComboBox.currentComboIndex + 1,
                                         flowControlComboBox.currentComboIndex)
    }
}
