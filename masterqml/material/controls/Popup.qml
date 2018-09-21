import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.Popup {
    id: control

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 200
        border.color: "#444"
    }

    contentItem: Column {}
}
