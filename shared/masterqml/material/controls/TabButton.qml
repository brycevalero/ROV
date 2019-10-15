import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.TabButton {
    id: control

    contentItem: Text {
        id: controlCI
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? Theme.primaryActive : Theme.primary
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        id: controlBG

        implicitWidth: 100
        implicitHeight: 26
        opacity: enabled ? 1 : 0.3
        color: "transparent"
        //border.color: control.down ? Theme.primaryActive : Theme.primary
        //border.width: 1
        //radius: 2
    }

    states: [
        State {
            name: "hovered"; when: control.hovered;
            PropertyChanges { target: controlCI; color: "white" }
            PropertyChanges { target: controlBG; color: Theme.primaryActive }
        },
        State {
            name: "checked"; when: control.checked;
            PropertyChanges { target: controlCI; color: "white" }
            PropertyChanges { target: controlBG; color: Theme.primary }
        }
    ]
}
