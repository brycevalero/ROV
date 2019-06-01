import QtQuick 2.0
import QtQuick.Shapes 1.12
import material.core 1.0

Item {
    width: 150
    height: 150

    //circle around compass
    Rectangle {
         anchors.fill:parent
         color: "white"
         border.color: Theme.primaryActive
         border.width: 1
         radius: width*0.5
    }

    Canvas {
        id: canvas

        width: parent.width * .8
        height: parent.height * .8
        anchors.centerIn: parent

        onPaint: {
            var ctx = getContext("2d");
            var offset = width/3;
            var centerx = width/2;
            var centery = height/2;

            // Start path
            ctx.fillStyle = Theme.primary
            ctx.strokeStyle = Theme.primary
            ctx.lineWidth = 4;

            //pointer
            ctx.beginPath();
            ctx.moveTo(centerx,0);
            ctx.lineTo(centerx-(15), 30);
            ctx.lineTo(centerx+(15), 30);
            ctx.lineTo(centerx,0);
            ctx.stroke();

            ctx.lineWidth = 6;

            //wings
            ctx.beginPath();
            ctx.moveTo(centerx-(width*.1) - offset, centery);
            ctx.lineTo(centerx-(width*.1), centery);
            ctx.arc(centerx, centery, (width*.1), Math.PI, 0, true)
            ctx.lineTo(centerx+(width*.1) + offset, centery);
            ctx.stroke();

            //point
            ctx.beginPath();
            ctx.moveTo(centerx+5, centery);
            ctx.arc(centerx, centery, 5, 0, 2*Math.PI, true)
            ctx.fill();
        }
    }
}
