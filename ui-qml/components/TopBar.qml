import QtQuick.Controls 2.5

MenuBar {
    width: parent.width
    anchors {
        top: parent.top
        left: parent.left
        right: parent.left
    }

    Menu {
        title: "File"
        MenuItem {
            text: "Open Session"
        }

        MenuItem {
            text: "Save Session"
        }
    }

    Menu {
        title: "Mode"
        MenuItem {
            text: "Testing"
        }
        MenuItem {
            text: "Live"
        }
    }
}
