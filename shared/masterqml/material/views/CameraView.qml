import QtQuick 2.6
import QtQuick.Extras 1.4
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
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

        HeadingRibbon {
            id: heading
            width: parent.width
            height: 50
            angle: 0
        }
    }

    AttitudeIndicator {
        id: attitude
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
    }

    Canvas {
        id: canvas

        width: parent.width
        height: 260
        anchors.bottom: parent.bottom
        opacity:.5

        onPaint: {
            var ctx = getContext("2d");
            var offset = 50;
            var centerx = width/2;
            var centery = height/2;
            var sRadius = 50;

            // Start path
            ctx.fillStyle = "white"
            ctx.strokeStyle = Theme.primary
            ctx.lineWidth = 4;

            //our weird shape
            ctx.lineWidth = 2;
            ctx.beginPath();
            ctx.moveTo(0, centery + sRadius);
            //make the arcs
            ctx.arc(centerx-(120+sRadius), centery, sRadius, Math.PI/2, 0, true)
            ctx.arc(centerx, centery, (120), Math.PI, 0, false)
            ctx.arc(centerx+(120+sRadius), centery, sRadius, Math.PI, Math.PI/2, true)
            //draw rest of box
            ctx.lineTo(width, centery + sRadius);
            ctx.lineTo(width, height);
            ctx.lineTo(0, height);
            ctx.lineTo(0, centery + sRadius);
            ctx.stroke();
            ctx.fill();
        }
    }

    Battery {
        id: battery
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        //opacity:.5
    }

    HeadingIndicator {
        id: compass
        heading: 45
        width: 220
        height: 220
        angle: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        //opacity: .5
    }

    Timer {
        interval: 5000; running: true; repeat: true
        onTriggered: {
            //console.log(compass.angle)
            compass.heading = Math.floor(Math.random()*(360-0+1)+0);
            //compass.heading = 360
            console.log(compass.heading);

            heading.angle = heading.angle +30
            if(heading.angle > 360){
                heading.angle = 0;
            }
            battery.percent = battery.percent + .1
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
