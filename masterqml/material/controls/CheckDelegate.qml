import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.CheckDelegate {
    id: control

    contentItem: Text {
        rightPadding: control.indicator.width + control.spacing
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#17a81a" : "#21be2b"
        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter
    }

    indicator: Rectangle {
        implicitWidth: 26
        implicitHeight: 26
        x: control.width - width - control.rightPadding
        y: control.topPadding + control.availableHeight / 2 - height / 2
        radius: 3
        color: "transparent"
        border.color: control.down ? "#17a81a" : "#21be2b"

        Rectangle {
            width: 14
            height: 14
            x: 6
            y: 6
            radius: 2
            color: control.down ? "#17a81a" : "#21be2b"
            visible: control.checked
        }
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        visible: control.down || control.highlighted
        color: control.down ? "#bdbebf" : "#eeeeee"
    }
}
