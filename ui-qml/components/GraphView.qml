import QtQuick 2.15
import QtQuick.Layouts 6.3
import QtQuick.Controls 2.0

Rectangle {
    id: graphView
    Layout.alignment: Qt.AlignVCenter
    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.preferredWidth: 50
    Layout.preferredHeight: 64

    TabBar {
        id: tabBar
        width: graphView.width
        height: graphView.height * 0.10

        Repeater {
            model: ["Voltage", "Pressure", "Altitude", "Gyroscope", "Temprature"]
            TabButton {
                text: modelData
            }
        }
    }

    StackLayout
    {
        anchors.fill: parent
        anchors.topMargin: 20
        currentIndex: tabBar.currentIndex


        Item {
            id: voltage

            Chart {
            }
        }

        Item {
            id: tempreture

            Chart {
            }
        }

        Item {
            id: altitude

            Chart {
            }
        }

        Item {
            id: pressure

            Chart {
            }
        }

        Item {
            id: gyroscope

            Chart {
            }
        }
    }
}
