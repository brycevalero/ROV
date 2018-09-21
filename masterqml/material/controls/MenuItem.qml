import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.MenuItem {
    id: control

    implicitWidth: 200
    implicitHeight: 40

    arrow: Canvas {
        x: parent.width - width
        implicitWidth: 40
        implicitHeight: 40
        visible: control.subMenu
        onPaint: {
            var ctx = getContext("2d")
            ctx.fillStyle = control.highlighted ? "#ffffff" : "#21be2b"
            ctx.moveTo(15, 15)
            ctx.lineTo(width - 15, height / 2)
            ctx.lineTo(15, height - 15)
            ctx.closePath()
            ctx.fill()
        }
    }

    indicator: Item {
        implicitWidth: 40
        implicitHeight: 40
        Rectangle {
            width: 26
            height: 26
            anchors.centerIn: parent
            visible: control.checkable
            border.color: "#21be2b"
            radius: 3
            Rectangle {
                width: 14
                height: 14
                anchors.centerIn: parent
                visible: control.checked
                color: "#21be2b"
                radius: 2
            }
        }
    }

    contentItem: Text {
        leftPadding: control.indicator.width
        rightPadding: control.arrow.width
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.highlighted ? "#ffffff" : "#21be2b"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        color: control.highlighted ? "#21be2b" : "transparent"
    }
}
