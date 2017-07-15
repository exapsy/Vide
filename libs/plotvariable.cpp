#include "plotvariable.h"

PlotVariable::PlotVariable(QObject *parent) : QObject(parent)
{

}

double PlotVariable::getValue() const
{
    return value;
}

void PlotVariable::setValue(double value)
{
    value = value;
}

QString PlotVariable::getName() const
{
    return name;
}

void PlotVariable::setName(const QString &value)
{
    name = value;
}

quint64 PlotVariable::getMilliseconds() const
{
    return milliseconds;
}

void PlotVariable::setMilliseconds(const quint64 &value)
{
    milliseconds = value;
}

quint64 PlotVariable::getMilli() const
{
    return milli;
}

void PlotVariable::setMilli(const quint64 &value)
{
    milli = value;
}
