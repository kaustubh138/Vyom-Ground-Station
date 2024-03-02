#ifndef SERIAL_HPP
#define SERIAL_HPP

#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QList>
#include <QDebug>
#include <qserialportglobal.h>

#include "Device.hpp"
#include "../utils/StringParser.hpp"
#include "../utils/CircularBuffer.hpp"

#include <string>
#include <iostream>

namespace Vyom
{
	namespace Devices
	{
		class Serial
			: public Device
		{
			Q_OBJECT

		public:
			Serial(const std::string& portName);
			~Serial();

			virtual std::size_t Send() override;
			virtual std::size_t Recieve() override;

		public slots:
			void slt_FeedUpdate() override;
		
		private:
			void open();
			void close();

		private:
			QSerialPort* m_SerialPort;
			QTimer* m_RefreshTimer;
			InputData* m_ReadData;
			std::string m_PortName;

			QList<QByteArray> m_ReadBuffer;
		};
	}
}

#endif // SERIAL_HPP
