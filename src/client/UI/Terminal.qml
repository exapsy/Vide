import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: root

    property string input: ""
    property int lastLength: 0

    onInputChanged: {
        if (textArea.length > 1000)
            textArea.remove(0, lastLength)
        textArea.insert(textArea.length, input.replace("\n", "").replace("\r", "\n"))
        lastLength = input.length
    }

    Rectangle {
        id: terminalBox
        anchors.top: root.top
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.right: root.right
        color: "transparent"
        radius: 10

        TextArea {
            id: textArea
            anchors.fill: parent

            text: ""


            style: TextAreaStyle {
                incrementControl: null
                decrementControl: null
                transientScrollBars: true

                textColor: "#39FF14"
                backgroundColor: "#101010"

                handle: Rectangle {
                    implicitWidth: 15
                    implicitHeight: 20
                    radius: 5
                    color: "#39FF14"
                }
                scrollBarBackground: Rectangle {
                    implicitWidth: 20
                    implicitHeight: 20
                    color: "#101010"
                }
            }
        }
    }
}
