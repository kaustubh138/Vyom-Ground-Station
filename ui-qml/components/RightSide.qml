import QtQuick 2.15
import QtQuick.Layouts 6.3

ColumnLayout{
    id: right
    spacing: 5
    anchors {
       top: topBar.bottom
       bottom: bottomBar.top
       right: parent.right
       bottomMargin: 3
    }

    width: parent.width * 1/3

    Rectangle {
        id: leftTop
        Layout.alignment: Qt.AlignVCenter
        color: "plum"
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 50
        Layout.preferredHeight: 37
    }

    ColumnLayout {
        id: leftBottom
        spacing: 5
        Layout.alignment: Qt.AlignLeft
        Layout.preferredHeight: 70

        Rectangle {
            id: map
            Layout.alignment: Qt.AlignVCenter
            color: "magenta"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 50
            Layout.preferredHeight: 50
        }

        Rectangle {
            id: telemetry
            Layout.alignment: Qt.AlignVCenter
            color: "grey"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 50
            Layout.preferredHeight: 50
        }
    }
}
