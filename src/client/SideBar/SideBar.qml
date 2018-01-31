import QtQuick 2.7

import "../Styles"
import "../UI"

Item {
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.left: parent.left
    width: 256
    Rectangle {
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 256

        color: ThemeManager.primaryColor

        Rectangle {
            id: tabs
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.topMargin: 11
            anchors.leftMargin: 11
            anchors.rightMargin: 11
            height: 200

            color: ThemeManager.primaryColor

            Terminal {
                id: terminal
                anchors.top: tabs.top
                anchors.bottom: tabs.bottom
                anchors.left: tabs.left
                anchors.right: tabs.right

                anchors.bottomMargin: 11
            }
        }

        Rectangle {
            id: horizontalSeperator
            anchors.top: tabs.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            height: 1
            width: 232

            color: ThemeManager.backgroundColor
        }

        Rectangle {
            id: tools
            anchors.top: tabs.bottom
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.topMargin: 11
            anchors.leftMargin: 11
            anchors.rightMargin: 11
            height: 100

            color: ThemeManager.primaryColor

            Loader {
                id: toolLoader
                height: parent.height
                anchors.left: parent.left
                anchors.right: parent.right
                source: "./Tools/SerialPortManager/SerialPortManager.qml"
            }
        }
    }
}
