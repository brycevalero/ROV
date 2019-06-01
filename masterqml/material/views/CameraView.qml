import QtQuick 2.11
import QtQml 2.11
import QtMultimedia 5.8
import material.components 1.0
import material.controls 1.0
import material.core 1.0

Item {

    anchors.fill:parent

    Rectangle{
        anchors.top: parent.top
        width:parent.width
        height: 50

        CompassHeading {
            id: heading
            width: parent.width
            height: 50
            angle: 0
        }

        Battery {
            id: battery
            y: 60
            x: 10
        }
    }

    HeadingIndicator {
        id: compass
        width: 260
        height: 260
        angle: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }

    AttitudeIndicator {
        id: attitude
        width: 260
        height: 260
        anchors.left: compass.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }

    Timer {
        interval: 100; running: true; repeat: true
        onTriggered: {
            //console.log(compass.angle)
            compass.angle = compass.angle +1
            heading.angle = heading.angle +1
            if(heading.angle > 360){
                heading.angle = 0;
            }
            battery.percent = battery.percent + .01
            if(battery.percent > 1){
                battery.percent = 0;
            }
        }
    }



    /*Video {
        id: video
        width : 800
        height : 600
        source: "video.avi"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                //video.play()
            }
        }

        focus: true
    }*/
}
