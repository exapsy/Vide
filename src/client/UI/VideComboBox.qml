import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

import "../Styles"

Item {
    id: root
    property string header: "Header"
    property variant model: ListModel {
        ListElement { text: "Choice 1" }
        ListElement { text: "Choice 2" }
    }

    height: text.height + comboBox.height
    property int count: comboBox.count
    property int currentIndex: comboBox.currentIndex
    property string currentText: comboBox.currentText
    property bool hovered: comboBox.hovered
    property bool pressed: comboBox.pressed

    Text {
        id: text

        anchors.left: parent.left
        anchors.top: parent.top

        text: header
        color: ThemeManager.backgroundColor

        font.pointSize: ThemeManager.baseSize
        font.bold: true
    }

    ComboBox {
        id: comboBox

        anchors.top: text.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        currentIndex: root.currentIndex

        model: root.model
    }
}
