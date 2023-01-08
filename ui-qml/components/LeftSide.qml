import QtQuick 2.15
import QtQuick.Layouts 6.3

ColumnLayout{
    id: leftSide
    spacing: 5
    width: parent.width * 2/3 - 2

    anchors {
       top: topBar.bottom
       bottom: bottomBar.top
       left: parent.left
       bottomMargin: 3
    }

    Rectangle {
        id: rightTop
        Layout.alignment: Qt.AlignVCenter
        color: "orange"
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 50
        Layout.preferredHeight: 34
    }

    Rectangle {
        id: rightBottom
        Layout.alignment: Qt.AlignVCenter
        color:  "blue"
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 50
        Layout.preferredHeight: 64
    }
}

