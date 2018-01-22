import QtQuick 2.7

import "../Styles"

Item {
    height: 50
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: parent.top

    property string status: "NO STATUS"

    Rectangle {
        height: 50
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        gradient: Gradient {
            GradientStop { position: 0.0; color: Qt.lighter(ThemeManager.backgroundColor, 1.05) }
            GradientStop { position: 1.0; color: Qt.darker(ThemeManager.backgroundColor, 1.05) }
        }

        Text {
            id: header
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            text: qsTr("Vide")

            font.family: ThemeManager.font.family
            font.pointSize: 24
            font.bold: false
            color: ThemeManager.primaryColor
        }

        Text {
            id: subheader
            anchors.left: header.right
            anchors.bottom: header.bottom
            anchors.bottomMargin: 4
            anchors.leftMargin: 11

            text: qsTr("Serial Plot Application")

            font.family: ThemeManager.font.family
            font.pointSize: ThemeManager.smallSize
            font.bold: false
            color: ThemeManager.secondaryColor
        }

        Text {
            id: statusHeading
            anchors.left: parent.left
            anchors.leftMargin: 11
            anchors.verticalCenter: parent.verticalCenter

            text: qsTr("STATUS ")

            font.family: ThemeManager.font.family
            font.pointSize: ThemeManager.bigSize
            font.bold: false
            color: ThemeManager.secondaryColor
        }

        Text {
            id: statusDescription
            anchors.left: statusHeading.right
            anchors.leftMargin: 11
            anchors.verticalCenter: parent.verticalCenter
            anchors.topMargin: 4

            text: status

            font.family: ThemeManager.font.family
            font.pointSize: ThemeManager.smallSize
            font.bold: true
            color: ThemeManager.primaryColor
        }
    }
}
