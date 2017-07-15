#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
// Serial Port and Data Handling Libs
#include "libs/SerialCommunication/serialdatamanager.hpp"
// Plotting
#include "libs/GraphPlot/qcustomplot.h"

#define PLOT_DEFAULT_COLOR QColor( 255, 41, 77 )
#define PLOT_COLOR1 QColor( 68, 129, 77 )
#define PLOT_COLOR2 QColor( 241, 196, 15 )
#define PLOT_COLOR3 QColor( 22, 160, 133)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void makePlot( );

private slots:
    void writeDownByte();
    void on_openSerialButton_clicked();
    void serialButtonOpened();
    void serialButtonClosed();

    void updateGraph();
private:
    Ui::MainWindow *ui;
    SerialDataManager *serialData;
    QCPGraph *graph1;

    QVector<double> *graphY;
    qint32 graphyIndex;
    QVector<double> *graphX;
};

#endif // MAINWINDOW_H
