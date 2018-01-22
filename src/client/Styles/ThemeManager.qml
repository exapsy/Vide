import QtQuick 2.7

/**
  * The ThemeProvider manages and provides the Theme of the Application.
  * It provides basic management and theme switching utilities.
  */

pragma Singleton

QtObject {
    /* Color Theme set to default - The more down you get, the less 'important' the color is */
    readonly property color primaryColor: "#001D29"
    readonly property color secondaryColor: "#013340"
    readonly property color accentColor: "#236475"
    readonly property color quoteColor: "#93B8C2"
    readonly property color backgroundColor: "#DCEFF5"

    /* Sizes */
    property int baseSize: 10

    readonly property int smallSize: 10
    readonly property int bigSize: 16

    property font font
    font.bold: true
    font.underline: false
    font.pixelSize: 14
    font.family: "arial"
}
