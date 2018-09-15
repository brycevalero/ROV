import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.TextArea {
    id: control

    color: Theme.primary
    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 40
        color: "transparent"
        border.color: control.enabled ? Theme.primary : "transparent"
        border.width: 1
        radius: 2
    }
}
