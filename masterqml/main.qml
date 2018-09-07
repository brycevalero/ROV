import QtQuick 2.9
import QtQuick.Window 2.2
import material.components 1.0
import material.controls 1.0
import material.views 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    CameraView {

    }

    Button {
        id:bnt
        text:"button"
    }
}
