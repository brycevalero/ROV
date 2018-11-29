import QtQuick 2.6
import QtQuick.Controls 2.4
import material.core 1.0

Item {
    id: component

    Canvas {
        id: canvas

        property var size: (component.height>component.width)?component.width:component.height
        width: canvas.size
        height: canvas.size

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
}
