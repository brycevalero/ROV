import QtQuick 2.0
import QtQuick.Controls.Styles 1.4

ButtonStyle {
    label: Text {
        text: control.text
        opacity: control.enabled ? 1.0 : 0.3
        color: control.pressed ? "#17a81a" : "#21be2b"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 26
        opacity: enabled ? 1 : 0.3
        color: "transparent"
        border.color: control.pressed ? "#17a81a" : "#21be2b"
        border.width: 1
        radius: 2
    }
}
