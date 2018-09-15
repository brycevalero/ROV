import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.GroupBox {
    id: control

    background: Rectangle {
        y: control.topPadding - control.bottomPadding
        width: parent.width
        height: parent.height - control.topPadding + control.bottomPadding
        color: "transparent"
        border.color: Theme.primary
        radius: 2
    }

    label: Label {
        x: control.leftPadding
        width: control.availableWidth
        text: control.title
        color: Theme.primary
        elide: Text.ElideRight
    }

}
