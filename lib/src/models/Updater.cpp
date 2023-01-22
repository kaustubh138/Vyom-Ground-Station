#include "Updater.hpp"

namespace Vyom
{
	Updater::Updater(QObject* parent)
		: QObject(parent)
	{
		m_Timer = new QTimer(this);
		m_Timer->setInterval(REFRESH_RATE);
		connect(m_Timer, &QTimer::timeout, this, &Updater::sgnl_DataChanged);
	}


	Updater::~Updater()
	{
		delete m_Timer;
	}

	void Updater::slt_SetInputData()
	{
		static int one = 1;
		m_Data = InputData();
		m_Data.altitude += (one++);
		m_Data.packet.count += (one++);
		emit sgnl_DataChanged();
	}

}

