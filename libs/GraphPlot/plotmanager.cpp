#include "plotmanager.h"

PlotManager::PlotManager( QCustomPlot *plot, QObject *parent )
    : QObject( parent ), plot( plot )
{

}

quint8 PlotManager::getVariablesCount() const
{
    return variablesCount;
}

void PlotManager::setVariablesCount(const quint8 &value)
{
    variablesCount = value;
}
