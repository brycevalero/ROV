import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import material.core 1.0

RadioButtonStyle {
    id: style

    indicator: Rectangle {
        implicitWidth: 26
        implicitHeight: 26
        //x: control.leftPadding
        y: parent.height / 2 - height / 2
        radius: 13
        color: "transparent"
        border.color: control.pressed ? Theme.primaryActive : Theme.primary

        Rectangle {
            width: 14
            height: 14
            x: 6
            y: 6
            radius: 7
            color: control.pressed ? Theme.primaryActive : Theme.primary
            visible: control.checked
        }
    }

    label: Text {
        text: control.text
        //font: control.font
        opacity: control.enabled ? 1.0 : 0.3
        color: control.pressed ? Theme.primaryActive : Theme.primary
        verticalAlignment: Text.AlignVCenter
        //leftPadding: control.indicator.width + control.spacing
    }
}
