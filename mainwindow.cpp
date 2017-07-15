#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent ) :
	QMainWindow( parent ),
	ui( new Ui::MainWindow )

{
    graphX = new QVector<double>(1023);
    graphY = new QVector<double>(1023);
    graphyIndex = 0;

	serialData = new SerialDataManager( );

	ui->setupUi( this );
	// PortNames comboBox
	ui->serialPortsComboBox->addItems( SerialSettings::availablePortNames( ) );
	// Adding BaudRates values onto the according ComboBox
	ui->baudRatesComboBox->setInsertPolicy( QComboBox::NoInsert );
	ui->baudRatesComboBox->addItem( "9600", QSerialPort::Baud9600 );
	ui->baudRatesComboBox->addItem( "1200", QSerialPort::Baud1200 );
	ui->baudRatesComboBox->addItem( "2400", QSerialPort::Baud2400 );
	ui->baudRatesComboBox->addItem( "4800", QSerialPort::Baud4800 );
	ui->baudRatesComboBox->addItem( "19200", QSerialPort::Baud19200 );
	ui->baudRatesComboBox->addItem( "38400", QSerialPort::Baud38400 );
	ui->baudRatesComboBox->addItem( "57600", QSerialPort::Baud57600 );
	ui->baudRatesComboBox->addItem( "115200", QSerialPort::Baud115200 );
	// Start/Stop button Connections
    connect( serialData->serialRecorder, SIGNAL(serialOpened( ) ),
			 this, SLOT(serialButtonOpened( ) ) );
    connect( serialData->serialRecorder, SIGNAL(serialClosed( ) ),
			 this, SLOT(serialButtonClosed( ) ) );
	// When there is a new byte recorded, write it down
    connect( serialData, SIGNAL(dataChanged( ) ),
             this, SLOT(writeDownByte( ) ) );

    makePlot( );
    connect(serialData, SIGNAL(dataChanged( ) ),
            this, SLOT(updateGraph( ) ) );
}

MainWindow::~MainWindow( )
{
    delete ui;
}

void MainWindow::makePlot()
{
    ui->customPlot->legend->setVisible( true );
    ui->customPlot->legend->setFont( QFont( "Helvetica", 9 ) );

    for ( int i = 0; i < 1023; i++ ) {
        (*graphX)[ i ] = i;
    }
    for ( int i = 0; i < 1023; i++ ) {
        (*graphY)[ i ] = 0;
    }


    graph1 = ui->customPlot->addGraph();
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));


    ui->customPlot->xAxis->setLabel( "x" );
    ui->customPlot->yAxis->setLabel( "y" );

    ui->customPlot->xAxis->setRange( 0, 1023 );
    ui->customPlot->yAxis->setRange( 0, 1023 );

    graph1->setData( (*graphX), (*graphY) );

    // set some pens, brushes and backgrounds:
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->customPlot->setBackground(plotGradient);
}

void MainWindow::serialButtonOpened( ) {
	ui->openSerialButton->setText( "Stop" );
    ui->serialPortsComboBox->setEnabled(false);
    ui->baudRatesComboBox->setEnabled(false);
}

void MainWindow::serialButtonClosed( ) {
    ui->openSerialButton->setText( "Start" );
    ui->serialPortsComboBox->setEnabled(true);
    ui->baudRatesComboBox->setEnabled(true);
}

void MainWindow::updateGraph() {
    QMap<QString, double> updateData = serialData->getMappedDoubles();

    for ( int i = 0; i < updateData.count(); i++ ) {
        if (graphY->size() == 1023 )
            graphY->pop_back();
        if ( updateData[i].size() > 0 ) {
            graphY->insert( 0, (double) updateData[i][0] );
        }
    }
    if ( graph1->dataCount() > 1023 )
        ui->customPlot->clearPlottables();


    graph1->setData( *graphX, *graphY );

    ui->customPlot->replot();

}

void MainWindow::writeDownByte( ) {
	// Place the last bytes recorded to the serialManagement class
	// Which subtracts the last byte as a carry if and only it doesn't end with CR or NL
	qDebug() << "🢂 Byte: \n" << serialData->getData( ) << endl;
}

void MainWindow::on_openSerialButton_clicked( ) {
    if ( !( serialData->serialRecorder->isSerialOpen( ) ) ) {
		SerialSettings settings ( ui->serialPortsComboBox->currentText( ), ui->baudRatesComboBox->currentData( ).toInt( ) );
        serialData->serialRecorder->setSettings( settings );
        serialData->serialRecorder->openSerialPort( );
	} else {
        serialData->serialRecorder->closeSerialPort( );
	}
}
