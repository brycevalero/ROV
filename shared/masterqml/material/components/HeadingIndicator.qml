import QtQuick 2.6
import QtQuick.Extras 1.4
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import material.core 1.0

Item {
    id: component
    property real angle: 0
    property real heading: 0
    property real adjustedHeading: {360 - heading%360}
    property int pixelSize: component.width * .1
    width: 260
    height: 260

    onAdjustedHeadingChanged: {
        friction = .95;
    }

    property bool _clockwiseOld: true
    property bool clockwise: true
    property real speed: .1
    property real maxspeed: 5
    property real friction: 0
    property real dr: 0

    function move() {

        //Restrict heading to [0-360] range
        var h = adjustedHeading%360;
        _clockwiseOld = component.clockwise

        //Move the compass towards heading
        if(component.angle < h) {
            if(Math.abs(component.angle - h)<180) {
                dr += speed;
                clockwise = true;
            } else { dr -= speed; clockwise = false;}
        } else {
            if(Math.abs(component.angle - h)<180) {
                dr -= speed;
                clockwise = false;
            } else { dr += speed; clockwise = true;}
        }

        //Dont exceed maxspeed while moving
        if (dr > maxspeed) {
            dr = maxspeed;
        } else if (dr < -maxspeed) {
            dr = (-maxspeed);
        }

        //limit the amount we bounce by increasing friction each time
        if(component.clockwise !== _clockwiseOld){
            friction *= .98
            if (friction < .01) {
                friction =0;
            }
        }

        dr *= friction;

        //Restrict angle to [0-360] range
        var tempAngle = component.angle%360
        //Add accelleration and friction
        tempAngle += dr;

        //make sure we dont go negative and spin out of control
        if(tempAngle <0){
            tempAngle = 360 + tempAngle;
        }
        component.angle = tempAngle%360;

        //console.log("Angle:" + angle + " ACC:" + dr + " Friction:" + friction);
    }

    Timer {
        interval: 20; running: true; repeat: true
        onTriggered: move()
    }

    Timer {
        interval: 100; running: true; repeat: true
        onTriggered: angleTxt.text = Math.round(360 - angle%360);
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
            //visible: false
            width: 2
            height: parent.height
            radius: 5
            color: "#ccc"
            anchors.centerIn: parent
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
                    ctx.fillStyle = "red"
                    ctx.beginPath();

                    //n point
                    ctx.moveTo(centerx, 0);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx-offset, centery-offset);
                    ctx.closePath();

                    //n point
                    ctx.moveTo(centerx, 0);
                    ctx.lineTo(centerx, centery);
                    ctx.lineTo(centerx+offset, centery-offset);
                    ctx.closePath();

                    ctx.fill();
                }
            }

            CircularGauge {
                id: gauge
                anchors.centerIn: parent
                minimumValue: 0
                maximumValue: 359
                width: parent.width+5
                height: parent.height+5
                style: CircularGaugeStyle {
                    labelInset: outerRadius * 0.2
                    minimumValueAngle: 0
                    maximumValueAngle: 359
                    tickmarkStepSize: 30
                    tickmarkLabel: null
                    minorTickmarkCount: 2
                    needle: null
                    foreground: null

                    tickmark: Rectangle {
                        rotation: 0

                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.top: parent.bottom
                            text: {
                                var a = (styleData.index * 30)

                                if(a === 0){
                                    return "N";
                                } else if (a === 90){
                                    return "E";
                                }else if (a === 180){
                                    return "S";
                                }else if (a === 270){
                                    return "W";
                                }

                                return a;
                            }

                            color: "#333"
                        }
                    }
                }
            }
        }
    }

    //Center readout
    Rectangle {
        //visible:false
        anchors.centerIn: parent
        color: "white"
        width: 60
        height: 60
        border.color: Theme.primaryActive
        border.width: 1
        radius: width*0.5

        Text {
            id: angleTxt
            anchors.centerIn: parent
            font.pixelSize: 25;
            color:"black"
        }
    }
}
