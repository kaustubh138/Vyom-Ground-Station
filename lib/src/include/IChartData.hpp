#ifndef ICHART_DATA_HPP
#define ICHART_DATA_HPP

#include <QPointF>

#define REFRESH_RATE (1000 / 5)

class IChartData
{
public:
	virtual QPointF GetValue() const = 0;

};

#endif // !ICHART_DATA_HPP
