import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import material.components 1.0
import material.views 1.0

Window {
    visible: true
    width: 1080
    height: 800
    title: qsTr("ROV CTRL")

    StackView {
        id: stack
        initialItem: settingsView
        anchors.fill:parent

        CameraView {
            id:cameraView
        }

        DiagnosticView {
            id:diagnosticView
        }

        SettingsView {
            id:settingsView
        }
    }
}
