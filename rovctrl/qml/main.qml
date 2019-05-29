import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import material.components 1.0
import material.controls 1.0
import material.views 1.0

ApplicationWindow {
    id: window
    visible: true
    visibility: "Windowed"
    width: 1080
    height: 800
    title: qsTr("ROV CTRL")

    Action { id: open; text: qsTr("Open..."); checkable: true }
    Action { id: close; text: qsTr("Close") }
    Action { id: fullScreen; text: qsTr("FullScreen"); onTriggered: window.visibility = "FullScreen"}
    Action { id: windowed; text: qsTr("Windowed"); onTriggered: window.visibility = "Windowed"}
    Action { id: cameraAction; text: qsTr("Camera"); onTriggered: {stack.replace(cameraView);cameraTB.checked=true}}
    Action { id: diagnosticsAction; text: qsTr("Diagnostics"); onTriggered: {stack.replace(diagnosticView);diagnosticTB.checked=true} }
    Action { id: settingsAction; text: qsTr("Settings"); onTriggered: {stack.replace(settingsView);settingsTB.checked=true} }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { action: open }
            MenuItem { action: close }

            Menu {
               title: qsTr("Advanced")
            }
        }

        Menu {
            title: "Edit"
            MenuItem { action: cameraAction }
            MenuItem { action: diagnosticsAction }
            MenuItem { action: settingsAction }
        }

        Menu {
            title: "View"
            MenuItem { action: fullScreen }
            MenuItem { action: windowed }
        }
    }

    header: ToolBar {
            // ...
    }

    footer: TabBar {
        id: bar
        width: parent.width

        TabButton { id:cameraTB; action: cameraAction; checked:true}
        TabButton { id:diagnosticTB; action: diagnosticsAction }
        TabButton { id:settingsTB; action: settingsAction}
    }

    StackView {
        id: stack
        initialItem: cameraView
        anchors.fill:parent
        //anchors.margins: 10

        CameraView {
            id:cameraView
            parent:null
        }

        DiagnosticView {
            id:diagnosticView
            parent:null
        }

        SettingsView {
            id:settingsView
            parent:null
        }
    }
}
