import QtQuick 2.6
import QtQuick.Controls 2.4
import material.core 1.0

Item {
    id: component
    property int angle: 0
    property int pixelSize: component.width * .1
    property int radius: 6
    property double percent: .50
    property color color: Theme.primary
    width: 100
    height: 38
    rotation: angle

    onPercentChanged: {
        //[0-120] is the desired colored range out of 360
        var hue = ((component.percent*120) / 360);
        percentFill.width = fillContainer.width * percent;
        percentFill.color = Qt.hsla(hue, 1.0, 0.5, 1.0)
    }

    //the nub on top of battery
    Rectangle {
        anchors.centerIn: parent
        width: parent.width
        height: parent.height * .4
        color: component.color
        radius: component.radius
    }

    //the battery body
    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width * .92
        height: parent.height
        color: component.color
        radius: component.radius

        //the emptyness
        Rectangle {
            anchors.fill: parent
            anchors.margins: parent.height * .1
            color:"gray"
            radius: component.radius

            //fill percent boundries
            Rectangle {
                id: fillContainer
                anchors.fill: parent
                anchors.margins: parent.height * .1
                anchors.bottom: parent.bottom
                color:"transparent"
                radius: component.radius

                //percent of fill
                Rectangle {
                    id: percentFill
                    width: 0
                    height: parent.height
                    anchors.bottom: parent.bottom
                    color: "transparent"
                    radius: component.radius
                }
            }
        }
    }
}
