import QtQuick 2.6
import QtQuick.Controls 2.4 as Controls
import material.core 1.0

Controls.StackView {
    id: control

    popEnter: Transition {
        XAnimator {
            from: (control.mirrored ? -1 : 1) * -control.width
            to: 0
            duration: 400
            easing.type: Easing.OutCubic
        }
    }

    popExit: Transition {
        XAnimator {
            from: 0
            to: (control.mirrored ? -1 : 1) * control.width
            duration: 400
            easing.type: Easing.OutCubic
        }
    }
}
