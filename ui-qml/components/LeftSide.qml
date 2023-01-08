import QtQuick 2.15
import QtQuick.Layouts 6.3
import QtQuick.Controls 2.0

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

    GraphView {

    }
}

