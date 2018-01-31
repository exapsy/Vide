import QtQuick 2.7
import QtCharts 2.0

/**
  * Graph component equips the main application's content with a Graph Plot.
  */

ChartView {
    id: chartView
    title: "Serial - No #0"
    anchors.fill: parent
    antialiasing: true
    theme: ChartView.ChartThemeDark
    animationOptions: ChartView.AllAnimations

    ValueAxis {
        id: axisX
        min: 0
        max: 20
        tickCount: 5
    }

    ValueAxis {
        id: axisY
        min: 0.0
        max: 1000.0
    }

    SplineSeries {
        name: "Microphone"
        axisY: axisY
        axisX: axisX

        XYPoint { x: 0.0; y: 700.3 }
        XYPoint { x: 1.0; y: 500.3 }
        XYPoint { x: 2.0; y: 522.1 }
        XYPoint { x: 3.0; y: 549.9 }
        XYPoint { x: 4.0; y: 803.0 }
        XYPoint { x: 5.0; y: 703.0 }
        XYPoint { x: 6.0; y: 925.3 }
        XYPoint { x: 7.0; y: 625.1 }
        XYPoint { x: 8.0; y: 425.1 }
        XYPoint { x: 9.0; y: 125.1 }
        XYPoint { x: 10.0; y: 725.1 }
        XYPoint { x: 11.0; y: 525.5 }
        XYPoint { x: 15.0; y: 530.0 }
        XYPoint { x: 20.0; y: 525.0 }
    }

    SplineSeries {
        name: "Accerelator"
        axisY: axisY
        axisX: axisX
        style : Qt.DashLine
        color: "#2980b9"
        width: 5

        XYPoint { x: 0.0; y: 525.0 }
        XYPoint { x: 1.0; y: 530.0 }
        XYPoint { x: 2.0; y: 525.5 }
        XYPoint { x: 3.0; y: 725.1 }
        XYPoint { x: 4.0; y: 125.1 }
        XYPoint { x: 5.0; y: 703.0 }
        XYPoint { x: 6.0; y: 500.3 }
        XYPoint { x: 7.0; y: 425.1 }
        XYPoint { x: 8.0; y: 625.1 }
        XYPoint { x: 9.0; y: 803.0 }
        XYPoint { x: 10.0; y: 549.9 }
        XYPoint { x: 11.0; y: 925.3 }
        XYPoint { x: 14.0; y: 522.1 }
        XYPoint { x: 20.0; y: 700.3 }
    }
}
