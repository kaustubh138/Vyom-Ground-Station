#ifndef UPDATER_HPP
#define UPDATER_HPP

#include <QObject>
#include <QTimer>
#include "../src/format.hpp"
#include "../src/include/Device.hpp"

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

	public:
		Updater(Devices::Device* dev, QObject* parent = nullptr);
		~Updater();

	public slots:
		void slt_SetInputData(InputData* data);

	signals:
		void sgnl_DataChanged(InputData* data);

	private:
		Devices::Device* m_Device;
	};
}

#endif
