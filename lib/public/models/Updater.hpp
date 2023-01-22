#ifndef UPDATER_HPP
#define UPDATER_HPP

#include <QObject>
#include <QTimer>
#include "../src/format.hpp"

#define REFRESH_RATE (1000 / 5)

/* Sketch:
Updater.Register(datamodel, "name")
updater maintains a list of all registered data models

Updater Constructor:
	connect QTimer::timeOut signal <=> Updator::up
	for (data model in registered data mode)
	connect DataModel::valueChanged slot <=> Updator::InputDataChanged
*/

namespace Vyom
{
	class Updater
		: public QObject
	{
		Q_OBJECT
		Q_PROPERTY(InputData value READ value NOTIFY sgnl_DataChanged)

	public:
		Updater(QObject* parent = nullptr);
		~Updater();

		InputData value() const { return m_Data; }

	public slots:
		void slt_SetInputData();

	signals:
		void sgnl_DataChanged();

	private:
		InputData m_Data;
		QTimer* m_Timer;
	};
}

#endif
