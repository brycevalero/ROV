import QtQuick 2.0
import material.core 1.0
import material.components 1.0
import material.controls 1.0

Rectangle {
    width: parent.width
    height: 50
    color: Theme.primary

    Battery {
        id: battery
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        color: "black"
    }

    Timer {
        interval: 1000; running: true; repeat: true
        onTriggered: {
            battery.percent = battery.percent + .05
            if(battery.percent > 1){
                battery.percent = 0;
            }
        }
    }
}
