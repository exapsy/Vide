import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0

import "./src/client/Styles"
import "./src/client/TopBar"
import "./src/client/SideBar"
import "./src/client/Container"

Window {
    id: window
    visible: true
    width: 1080
    height: 600
    visibility: "Maximized"
    title: qsTr("Vide")
    color: ThemeManager.backgroundColor
    minimumWidth: 1024
    minimumHeight: 600

    TopBar {
        id: topBar
        anchors.top: parent.top
    }

    SideBar {
        id: sideBar
        anchors.top: topBar.bottom
        anchors.bottom: parent.bottom
    }

    Container {
        id: container
        anchors.left: sideBar.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: topBar.bottom
    }
}
