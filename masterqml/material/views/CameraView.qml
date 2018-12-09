import QtQuick 2.11
import QtQml 2.11
import QtMultimedia 5.8
import material.components 1.0
import material.controls 1.0

Item {

    Compass {
        width: parent.width/10
    }

    Video {
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
        /*Keys.onSpacePressed: video.paused = !video.paused
        Keys.onLeftPressed: video.position -= 5000
        Keys.onRightPressed: video.position += 5000*/
    }
}
