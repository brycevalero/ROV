import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

//Added for the styling
import material.components 1.0
import material.controls 1.0
import material.core 1.0

import registered.comm 1.0

ApplicationWindow {
    id: window
    visible: true
    visibility: "Windowed"
    width: 1280
    height: 800
    title: qsTr("ROV CTRL")

    ActionGroup { id: windowGroup; exclusive: true }
    ActionGroup { id: viewsGroup; exclusive: true }

    Action { id: open; text: qsTr("Open..."); checkable: true }
    Action { id: quit; text: qsTr("Quit"); onTriggered: Qt.quit() }
    Action { id: fullScreen; text: qsTr("FullScreen"); checkable: true; ActionGroup.group: windowGroup; onTriggered: window.visibility = "FullScreen"}
    Action { id: windowed; text: qsTr("Windowed"); checkable: true; checked: true; ActionGroup.group: windowGroup; onTriggered: window.visibility = "Windowed"}
    Action { id: cameraAction; text: qsTr("Camera"); checkable: true; checked: true; ActionGroup.group: viewsGroup; onTriggered: {stack.replace(cameraView);}}
    Action { id: diagnosticsAction; text: qsTr("Diagnostics"); checkable: true; ActionGroup.group: viewsGroup; onTriggered: {stack.replace(diagnosticView);}}
    Action { id: settingsAction; text: qsTr("Settings"); checkable: true; ActionGroup.group: viewsGroup; onTriggered: {stack.replace(settingsView);}}

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { action: quit }
        }

        Menu {
            title: "Edit"
        }

        Menu {
            title: "View"
            MenuItem { action: fullScreen }
            MenuItem { action: windowed }
            MenuSeparator {}
            MenuItem { action: cameraAction }
            MenuItem { action: diagnosticsAction }
            MenuItem { action: settingsAction }
        }
    }

    MainComm{
        id: mainComm
        focus: true
        anchors.fill: parent

        Component.onCompleted: {
            console.log("IS THIS ONLINE")
            console.log(mainComm.sensors.online)
        }
    }

    StackView {
        id: stack
        initialItem: cameraView
        anchors.fill:parent

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

    //NavigationComm{
    //    id: navcom
    //    focus: true
    //    anchors.fill: parent
    //}

    footer: StatusBar{
        id: statusBar
    }
}
