import QtQuick 2.7
import "../Styles"

Item {
    anchors.top: parent.top
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    anchors.left: parent.left

    Rectangle {
      anchors.top: parent.top
      anchors.right: parent.right
      anchors.bottom: parent.bottom
      anchors.left: parent.left

      color: ThemeManager.backgroundColor

      Loader {
          anchors.top: parent.top
          anchors.right: parent.right
          anchors.bottom: parent.bottom
          anchors.left: parent.left

          source: "./PlotPage/PlotPage.qml"
      }
    }
}
