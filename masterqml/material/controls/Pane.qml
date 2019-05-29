import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.Pane {
    id: control

    background: Rectangle {
        gradient: Gradient {
            GradientStop { position: 0; color: "#ffffff" }
            GradientStop { position: 1; color: "#c1bbf9" }
        }
    }
}
