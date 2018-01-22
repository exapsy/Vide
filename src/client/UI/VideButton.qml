import QtQuick 2.7
import QtQuick.Controls 2.0

Button {
    id: videButton
    property string defaultOption: "Default"
    property string secondOption: "Second"
    property bool defaultSelected: true

    text: defaultSelected ? defaultOption : secondOption

    onClicked: {
        defaultSelected = !defaultSelected
    }
}
