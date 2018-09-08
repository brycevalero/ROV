import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import material.components 1.0
import material.views 1.0

ApplicationWindow {
    visible: true
    width: 1080
    height: 800
    title: qsTr("ROV CTRL")

    style: ApplicationWindowStyle {
        background: Rectangle {
            color: "#000000"
        }
    }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { text: "Open..." }
            MenuItem { text: "Close" }
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
