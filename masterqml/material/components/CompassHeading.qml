import QtQuick 2.6
import QtQuick.Controls 2.4
import material.core 1.0

Rectangle {
    id: component
    property int angle: 0
    property int pixelSize: component.width * .1
    property double tickSize: 10
    property double tickPosition: 0
    width: 300
    height: 150
    color:"gray"
    //rotation: angle

    onAngleChanged: {
        //tickPosition = angle * tickSize;
        canvas.requestPaint();
    }

    Canvas {
        id: canvas

        width: component.width
        height: component.height
        anchors.centerIn: parent

        onPaint: {
            var ctx = getContext("2d");
            var interval = 10;
            var spacing = 50;

            ctx.clearRect(0,0,canvas.width,canvas.height);
            ctx.fillStyle = Theme.primaryActive
            ctx.strokeStyle = Theme.primary
            ctx.lineWidth = 2;
            ctx.font = "30px Georgia";

            //e point
            ctx.beginPath();

            ctx.moveTo(width/2, 0);
            ctx.lineTo(width/2, 40);
            ctx.strokeText(angle, width/2, 40)
            ctx.font = "15px Georgia";

            for(var i=0; i<=15; i++){

                //get angle before and after
                var ndiff = angle%interval;
                var pdiff = Math.abs(interval - ndiff);

                var angleLeftTxt = angle-ndiff-interval*i;
                if(angleLeftTxt<=0){angleLeftTxt+=360;}
                var position = width/2 - spacing*i - (ndiff/interval*spacing)
                ctx.moveTo(position, 0);
                ctx.lineTo(position, 20);
                ctx.strokeText(angleLeftTxt, position, 20)

                var angleRightTxt = angle+pdiff+interval*i
                if(angleRightTxt>360){angleRightTxt-=360;}
                position = width/2 + spacing*i + (pdiff/interval*spacing)
                ctx.moveTo(position, 0);
                ctx.lineTo(position, 20);
                ctx.strokeText(angleRightTxt, position, 20)
            }

            ctx.closePath();
            ctx.stroke();
        }
    }
}
