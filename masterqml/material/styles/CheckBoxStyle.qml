import QtQuick 2.0
import QtQuick.Controls.Styles 1.4

CheckBoxStyle {
    indicator: Rectangle {
        implicitWidth: 26
        implicitHeight: 26
        //x: control.leftPadding
        y: parent.height / 2 - height / 2
        radius: 3
        color: "transparent"
        border.color: control.pressed ? "#17a81a" : "#21be2b"

        Rectangle {
            width: 14
            height: 14
            x: 6
            y: 6
            radius: 2
            color: control.pressed ? "#17a81a" : "#21be2b"
            visible: control.checked
        }
    }

    label: Text {
        text: control.text
        //font: control.font
        opacity: control.enabled ? 1.0 : 0.3
        color: control.down ? "#17a81a" : "#21be2b"
        verticalAlignment: Text.AlignVCenter
        //leftPadding: control.indicator.width + control.spacing
    }
}
