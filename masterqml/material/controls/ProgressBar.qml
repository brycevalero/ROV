import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.ProgressBar {
    id: control

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 6
        color: "transparent"
        border.color: Theme.primaryActive
        radius: 3
    }

    contentItem: Item {
        implicitWidth: 200
        implicitHeight: 4

        Rectangle {
            width: control.visualPosition * parent.width
            height: parent.height
            radius: 3
            color: Theme.primary
            border.color: Theme.primaryActive
        }
    }
}
