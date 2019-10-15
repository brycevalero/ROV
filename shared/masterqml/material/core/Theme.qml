import QtQuick 2.4
pragma Singleton

Item {
    id: theme

    readonly property color primary: "#21be2b"
    readonly property color primaryActive: "#17a81a"
    readonly property color secondary: "red"
    readonly property color secondaryActive: "blue"
    readonly property color background: "#000000"
    readonly property color foreground: "red"
}
