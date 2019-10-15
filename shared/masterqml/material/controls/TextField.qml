import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.TextField {
    id: control

    color: Theme.primary
    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 26
        opacity: enabled ? 1.0 : 0.3
        color: "transparent"
        //color: control.enabled ? "transparent" : "#353637"
        border.color: Theme.primary
        border.width: 1
        radius: 2
    }
}
