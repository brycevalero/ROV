import QtQuick 2.6
import QtQuick.Controls 2.4
import material.core 1.0

Item {
    id: component
    property int angle: 0
    property int pixelSize: component.width * .1
    width: 150
    height: 150
    rotation: angle

    Canvas {
        id: canvas

        width: component.width * .8
        height: component.height * .8
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
        font.pixelSize: parent.pixelSize
        width: parent.width
        height: parent.height
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignTop
    }

    Text {
        text:"S"
        font.pixelSize: parent.pixelSize
        width: parent.width
        height: parent.height
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignBottom
    }

    Text {
        text:"E"
        font.pixelSize: parent.pixelSize
        width: parent.width
        height: parent.height
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        text:"W"
        font.pixelSize: parent.pixelSize
        width: parent.width
        height: parent.height
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
}
