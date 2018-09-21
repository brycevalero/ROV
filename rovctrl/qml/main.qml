import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import material.components 1.0
import material.controls 1.0
import material.views 1.0

ApplicationWindow {
    visible: true
    width: 1080
    height: 800
    title: qsTr("ROV CTRL")

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { text: "Open..."; checkable: true }
            MenuItem { text: "Close" }
            Action { text: qsTr("Tool Bar"); checkable: true }
                Action { text: qsTr("Side Bar"); checkable: true; checked: true }
                Action { text: qsTr("Status Bar"); checkable: true; checked: true }

            Menu {
               title: qsTr("Advanced")
               Action { text: qsTr("Tool Bar"); checkable: true }
                   Action { text: qsTr("Side Bar"); checkable: true; checked: true }
                   Action { text: qsTr("Status Bar"); checkable: true; checked: true }
            }
        }

        Menu {
            title: "Edit"
            MenuItem { text: "Cut" }
            MenuItem { text: "Copy" }
            MenuItem { text: "Paste" }
        }
    }

    StackView {
        id: stack
        initialItem: settingsView
        anchors.fill:parent
        anchors.margins: 10

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
