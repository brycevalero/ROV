import QtQuick 2.6
import QtQuick.Controls 2.4
import material.core 1.0

Item {
    id: component
    property int angle: 0
    property int pixelSize: component.width * .1
    property int radius: 8
    property double percent: .50
    width: 75
    height: 200
    rotation: angle

    onPercentChanged: {
        //[0-120] is the desired colored range out of 360
        var hue = ((component.percent*120) / 360);
        percentFill.height = fillContainer.height * percent;
        percentFill.color = Qt.hsla(hue, 1.0, 0.5, 1.0)
    }

    Rectangle {
        anchors.centerIn: parent
        width: parent.width * .4
        height: parent.height
        color:Theme.primary
        radius: component.radius
    }

    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width
        height: parent.height * .92
        color:Theme.primary
        radius: component.radius

        Rectangle {
            anchors.fill: parent
            anchors.margins: parent.width * .08
            color:"gray"
            radius: component.radius

            Rectangle {
                id: fillContainer
                anchors.fill: parent
                anchors.margins: parent.width * .08
                anchors.bottom: parent.bottom
                color:"transparent"
                radius: component.radius

                Rectangle {
                    id: percentFill
                    width: parent.width
                    height: 0
                    anchors.bottom: parent.bottom
                    color: "transparent"
                    radius: component.radius
                }
            }
        }
    }
}
