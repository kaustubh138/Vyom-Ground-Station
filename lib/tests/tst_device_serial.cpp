#include "../src/devices/Serial.hpp"
#include <QTest>

namespace Vyom::Tests
{
	class Device_Serial_Test 
		: public QObject
	{
		Q_OBJECT

	public:
		Vyom::Devices::Serial* m_Device;

	private slots:
		void initTestCase()
		{
			m_Device = new Vyom::Devices::Serial("COM3");
		}
	
		void testRecieve()
		{
			QVERIFY(m_Device->Recieve() > 0);
		}
	};
}

QTEST_MAIN(Vyom::Tests::Device_Serial_Test)

#include "tst_device_serial.moc"