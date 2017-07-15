#ifndef PLOTVARIABLE_H
#define PLOTVARIABLE_H

#include <QObject>

class PlotVariable : public QObject
{
    Q_OBJECT
public:
    explicit PlotVariable(QObject *parent = 0);

    double getValue() const;
    void setValue(double value);

    QString getName() const;
    void setName(const QString &value);

    quint64 getMilli() const;
    void setMilli(const quint64 &value);

signals:

public slots:
private:
    quint64 milli;
    QString name;
    double value;
};

#endif // PLOTVARIABLE_H
