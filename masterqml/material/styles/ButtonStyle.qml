import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import material.core 1.0

ButtonStyle {
    id: style

    label: Text {
        text: control.text
        opacity: control.enabled ? 1.0 : 0.3
        color: control.pressed ? Theme.primaryActive : Theme.primary
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 26
        opacity: control.enabled ? 1 : 0.3
        color: "transparent"
        border.color: control.pressed ? Theme.primaryActive : Theme.primary
        border.width: 1
        radius: 2
    }
}
