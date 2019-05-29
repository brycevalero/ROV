import QtQuick 2.11
import QtQml 2.11
import QtMultimedia 5.8
import material.components 1.0
import material.controls 1.0

Item {

    Text {
        text:"Camera view"
    }

    Battery {
        id: battery
        x:400
        //width:50
        //height:120
    }

    Compass {
        id: compass
        width: 150
        height: 150
        angle: 0
    }

    Rectangle{
        anchors.bottom: parent.bottom
        width:parent.width
        height: 150

        CompassHeading {
            id: heading
            width: parent.width
            height: 50
            angle: 0
        }
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
