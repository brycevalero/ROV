import QtQuick 2.6
import QtQuick.Controls 2.4
import material.core 1.0

Item {
    id: component
    property real angle: 0
    property real heading: 0
    property int pixelSize: component.width * .1
    width: 260
    height: 260

    property real speed: .1
    property real maxspeed: 20
    property real friction: .95
    property real dr: 0

    function move() {
        console.log(component.angle);
        component.angle = component.angle%360
        component.angle += dr;
        dr *= friction;

        var h = heading%360;

        if(component.angle < h) {
            if(Math.abs(component.angle - h)<180)
               dr += speed;
            else dr -= speed;
        } else {
            if(Math.abs(component.angle - h)<180)
               dr -= speed;
            else dr += speed;
        }

        if (dr > maxspeed) {
            dr = maxspeed;
        } else if (dr < -maxspeed) {
            dr = (-maxspeed);
        }
    }

    Timer {
        interval: 20; running: true; repeat: true
        onTriggered: move()
    }


    //circle around compass
    Rectangle {
         anchors.fill:parent
         color: "white"
         border.color: Theme.primaryActive
         border.width: 1
         radius: width*0.5
         anchors.horizontalCenter: parent.horizontalCenter

         //the needle
         Rectangle {
             width: 4
             height: parent.height/2
             radius: 5
             border.color: "red"
             border.width: 1
             color: "transparent"
             anchors.horizontalCenter: parent.horizontalCenter
         }

        //something to rotate
        Item {
            rotation: component.angle
            width: parent.width-20
            height: parent.height-20
            anchors.centerIn: parent

            Canvas {
                id: canvas

                width: parent.width * .8
                height: parent.height * .8
                anchors.centerIn: parent

                onPaint: {
                    var ctx = getContext("2d");
                    var offset = width/12;
                    var centerx = width/2;
                    var centery = height/2;

                    // Start path
                    ctx.fillStyle = Theme.primaryActive
                    ctx.strokeStyle = Theme.primary
                    ctx.lineWidth = 4;

                    // Draw a circle
                    ctx.beginPath();
                    ctx.moveTo(centerx+(width*1/3), centery);
                    ctx.arc(centerx, centery, (width*1/3), 0, 2*Math.PI, true)
                    ctx.stroke();

                    // Draw a circle
                    ctx.beginPath();
                    ctx.moveTo(centerx+(width*5/12), centery);
                    ctx.arc(centerx, centery, (width*5/12), 0, 2*Math.PI, true)
                    ctx.stroke();

                    //reference points
                    //use y – y1 = m(x – x1)
                    ctx.beginPath();
                    var y1 = 1*(width*3/4 - centerx) + centery;
                    var y2 = 1*(width*1/4 - centerx) + centery;
                    //se point
                    ctx.moveTo(width*3/4, y1);
                    ctx.lineTo(centerx, (centery+offset));
                    //sw point
                    ctx.lineTo(width*1/4, y1);
                    ctx.lineTo((centerx-offset), centery);
                    //nw point
                    ctx.lineTo(width*1/4, y2);
                    ctx.lineTo(centerx, (centery-offset));
                    //ne point
                    ctx.lineTo(width*3/4, y2);
                    ctx.lineTo((centerx+offset), centery);

                    ctx.closePath();
                    ctx.fill();
                    ctx.beginPath();

                    //n point
                    ctx.moveTo(centerx, 0);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx+offset, centery-offset);
                    ctx.closePath();

                    //e point
                    ctx.moveTo(width, centery);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx+offset, centery+offset);
                    ctx.closePath();

                    //s point
                    ctx.moveTo(centerx, height);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx-offset, centery+offset);
                    ctx.closePath();

                    //w point
                    ctx.moveTo(0, centery);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx-offset, centery-offset);
                    ctx.closePath();

                    ctx.fill();
                    ctx.fillStyle = Theme.primary
                    ctx.beginPath();

                    //n point
                    ctx.moveTo(centerx, 0);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx-offset, centery-offset);
                    ctx.closePath();

                    //e point
                    ctx.moveTo(width, centery);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx+offset, centery-offset);
                    ctx.closePath();

                    //s point
                    ctx.moveTo(centerx, height);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx+offset, centery+offset);
                    ctx.closePath();

                    //w point
                    ctx.moveTo(0, centery);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx-offset, centery+offset);
                    ctx.closePath();

                    ctx.fill();
                }
            }

            Text {
                text:"N"
                font.pixelSize: component.pixelSize
                width: parent.width
                height: parent.height
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignTop
            }

            Text {
                text:"S"
                font.pixelSize: component.pixelSize
                width: parent.width
                height: parent.height
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
            }

            Text {
                text:"E"
                font.pixelSize: component.pixelSize
                width: parent.width
                height: parent.height
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                text:"W"
                font.pixelSize: component.pixelSize
                width: parent.width
                height: parent.height
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
