#ifndef DATA_HPP
#define DATA_HPP

#include <QPointF>
#include "Updater.hpp"
#include "../src/include/IChartData.hpp"

#define HIGH 100
#define LOW 0

namespace Vyom
{
	class Data
		: public QObject, IChartData
	{
		Q_OBJECT
		Q_PROPERTY(QPointF GetValue READ GetValue NOTIFY sgnl_ValueChanged)

	public:
		Data(Updater* updater, QObject* parent = Q_NULLPTR);
		virtual QPointF GetValue() const override { return m_Value; }
		void SetValue(QPointF value) { m_Value = value; }

	private:
		QPointF m_Value;
		Updater* m_Updater;

	signals:
		void sgnl_ValueChanged();

	private slots:
		void slt_UpdateChart(InputData* data);
	};
}

#endif // DATA_HPP
