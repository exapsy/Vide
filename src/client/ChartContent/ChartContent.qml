import QtQuick 2.7
import QtCharts 2.0

/**
  * Graph component equips the main application's content with a Graph Plot.
  */

ChartView {
    title: "Spline"
    anchors.fill: parent
    antialiasing: true
    theme: ChartView.ChartThemeDark

    SplineSeries {
        name: "SplineSeries"
        XYPoint { x: 0; y: 0 }
        XYPoint { x: 1.1; y: 2.1 }
        XYPoint { x: 1.9; y: 3.3 }
        XYPoint { x: 2.1; y: 2.1 }
        XYPoint { x: 2.9; y: 4.9 }
        XYPoint { x: 3.4; y: 3.0 }
        XYPoint { x: 4.1; y: 3.3 }
    }
}
