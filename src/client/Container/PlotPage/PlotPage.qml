import QtQuick 2.9
import QtQml 2.2
import QtCharts 2.0

import "../../Styles"
import "../../ChartContent"



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

        ChartContent {
            id: chart
        }

        Component.onCompleted: {

        }
    }
}
