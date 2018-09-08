import QtQuick 2.11
import QtQml 2.11
import material.controls 1.0

Item {

    Column {
        spacing: 8

        Button {
            text: "Button"
        }

        CheckBox {
            text: "CheckBox"
        }

        RadioButton {
            text: "RadioButton"
        }

        ProgressBar {
            value: 0.25
        }

        ProgressBar {
            value: 0.5
        }

        ProgressBar {
            value: 0.75
        }

    }

}
