#ifndef PLOTMANAGER_H
#define PLOTMANAGER_H

#include <QObject>
#include <libs/GraphPlot/qcustomplot.h>

class PlotManager : public QObject
{
    Q_OBJECT
public:
    explicit PlotManager(QObject *parent = 0);

signals:

public slots:
};

#endif // PLOTMANAGER_H
