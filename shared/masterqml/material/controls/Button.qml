import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.Button {
    id: control

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? Theme.primaryActive : Theme.primary
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 26
        opacity: enabled ? 1 : 0.3
        color: "transparent"
        border.color: control.down ? Theme.primaryActive : Theme.primary
        border.width: 1
        radius: 2
    }
}
