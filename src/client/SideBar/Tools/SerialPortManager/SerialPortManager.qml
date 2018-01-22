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
        currentIndex: 0
        model: serialPortManager.availablePorts()
        onCurrentIndexChanged: {
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
        currentIndex: 12
        model: serialPortManager.availableBaudRates()
        onCurrentIndexChanged: {
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
        currentIndex: 3
        model: ["5", "6", "7", "8"]
        onCurrentIndexChanged: {
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
        currentIndex: 0
        model: ["No Parity", "Even", "Odd", "Space", "Mark"]
        onCurrentIndexChanged: {
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
        currentIndex: 0
        model: ["One Stop", "Two Stop", "One and a Half Stop"]
        onCurrentIndexChanged: {
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
        model: ["Hardware Control", "Software Control", "No Flow Control"]
        currentIndex: 2
        onCurrentIndexChanged: {
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
        }

        SerialPortManager {
            id: serialPortManager
            onConnected: {
                startButton.text = "STOP"
                readData();
            }
            onDisconnected: {
                startButton.text = "START"
            }
            onDataRead: {
                console.log(lastBytesRead)
            }
        }

    }
    onComboBoxChanged: {
        serialPortManager.updateSettings(portNameComboBox.model[portNameComboBox.currentIndex],
                                         baudRateComboBox.currentIndex+1,
                                         dataBitsComboBox.currentIndex+1,
                                         parityComboBox.currentIndex+1,
                                         stopBitsComboBox.currentIndex+1,
                                         flowControlComboBox.currentIndex+1)
    }
}
