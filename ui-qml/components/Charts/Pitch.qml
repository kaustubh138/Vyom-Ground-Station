import QtQuick 2.8
import QtCharts 2.2
import QtQuick.Window 2.2

Rectangle {
    width: parent.width
    height: parent.height

    Connections {
        target: pitch
        function onSgnl_ValueChanged() {
            if(lineSeries1.count > 5)
                lineSeries1.remove(0);
            lineSeries1.append(pitch.GetValue.x, pitch.GetValue.y)
            axisX.min = lineSeries1.at(0).x
            axisX.max = lineSeries1.at(lineSeries1.count-1).x
        }
    }

    ChartView {
        id: chartView
        width: parent.width
        height: parent.height
        anchors.fill: parent
        animationOptions: ChartView.NoAnimation
        antialiasing: true
        backgroundColor: "#222B45"

        ValueAxis {
            id: axisY1
            min: -30
            max: 30
            gridVisible: false
            color: "#ffffff"
            labelsColor: "#ffffff"
            labelFormat: "%.0f"
        }

        ValueAxis {
            id: axisX
            min: -1
            max: 1
            gridVisible: false
            color: "#ffffff"
            labelsColor: "#ffffff"
            labelFormat: "%.0f"
            tickCount: 5
        }

        LineSeries {
            id: lineSeries1
            name: "Pitch"
            color: "white"
            axisX: axisX
            axisY: axisY1
        }
    }
}
