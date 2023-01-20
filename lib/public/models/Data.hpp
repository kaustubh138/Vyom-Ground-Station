#ifndef DATA_HPP
#define DATA_HPP

#include <QObject>
#include <QPointF>
#include <QTimer>

#include "IChartData.hpp"

#define HIGH 100
#define LOW 0

class Data 
    : public QObject, IChartData
{
    Q_OBJECT
    Q_PROPERTY(QPointF GetValue READ GetValue NOTIFY sgnl_ValueChanged)

public:
    Data(QObject* parent = Q_NULLPTR);
    virtual QPointF GetValue() const override { return m_Value; }

private:
    QTimer* m_Timer;
    QPointF m_Value;

signals:
    void sgnl_ValueChanged();

private slots:
    void slt_Timeout();
};

#endif // DATA_HPP
