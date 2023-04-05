#include "Updater.hpp"

namespace Vyom
{
	Updater::Updater(Devices::Device* dev, QObject* parent)
		: m_Device(dev), QObject(parent)
	{
		connect(m_Device, &Devices::Device::sgnl_NewData, this, &Updater::slt_SetInputData);
	}


	Updater::~Updater()
	{
	
	}

	void Updater::slt_SetInputData(InputData* data)
	{
		emit sgnl_DataChanged(data);
	}

}

