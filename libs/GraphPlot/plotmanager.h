#ifndef PLOTMANAGER_H
#define PLOTMANAGER_H

#include <QObject>
#include <libs/GraphPlot/qcustomplot.h>

class PlotManager : public QObject
{
    Q_OBJECT
public:
    explicit PlotManager( QCustomPlot *plot, QObject *parent = 0 );

    quint8 getVariablesCount() const;
    void setVariablesCount(const quint8 &value);

signals:

public slots:

private:
    QCustomPlot *plot;
    QVector<*QCPGraph> graphs;
    quint8 variablesCount;

};

#endif // PLOTMANAGER_H
