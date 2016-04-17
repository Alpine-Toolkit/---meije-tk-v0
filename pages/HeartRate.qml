import QtQml 2.2
import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Layouts 1.1
import Qt.labs.controls 1.0
import Qt.labs.controls.material 1.0

// import Local 1.0
import QtSensors 5.8 // 1

Pane {
    id: altimeter_pane

    StepCounterSensor {
        id: step_counter_sensor
        active: true

        onReadingChanged: {
            var step_counter = step_counter_sensor.reading.stepCounter;
            step_counter_label.text = step_counter;
            console.info("Step counter", step_counter);
        }
    }

    HeartRateSensor {
        id: heart_rate_sensor
        active: true

        onReadingChanged: {
            var heart_rate = heart_rate_sensor.reading.heartRate;
            heart_rate_label.text = heart_rate;
            console.info("Heart rate", heart_rate);
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.topMargin: 30
        spacing: 30

        GridLayout {
            width: parent.width
            Layout.alignment: Qt.AlignCenter
            columns: 2
            columnSpacing : 2 * Screen.devicePixelRatio
            rowSpacing : 2 * Screen.devicePixelRatio

            Label {
                font.pointSize: 20
                text: qsTr("Step Counter")
            }
            Label {
                font.pointSize: 20
                id: step_counter_label
                text: "unknown"
            }

            Label {
                font.pointSize: 20
                text: qsTr("Heart Rate")
            }
            Label {
                font.pointSize: 20
                id: heart_rate_label
                text: "unknown"
            }
        }
    }
}

