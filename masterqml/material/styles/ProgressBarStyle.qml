import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import material.core 1.0

ProgressBarStyle {
    id: style

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 6
        color: "transparent"
        border.color: Theme.primaryActive
        radius: 3
    }

    progress: Rectangle {
        color: Theme.primary
        radius: 3
        border.color: Theme.primaryActive
    }
}
