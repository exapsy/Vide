import QtQuick 2.7
import "../../Styles"
import "../../GraphPlot"

Item {
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.left: parent.left
    anchors.right: parent.right

    Rectangle {
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        color: "transparent"

        Graph {

        }
    }
}
