#include "Serial.hpp"

namespace Vyom
{
	namespace Devices
	{

		Serial::Serial(const std::string& portName)
			: m_PortName(portName), m_ReadData(new InputData()), m_ReadBuffer()
		{
			open();
			connect(m_SerialPort, &QSerialPort::readyRead, this, &Serial::slt_FeedUpdate);
		}

		Serial::~Serial()
		{
			delete m_SerialPort;
			delete m_ReadData;
		}

		std::size_t Serial::Recieve()
		{
			if (!m_SerialPort->error())
			{
				const QByteArray data = m_SerialPort->readAll();
				for (QByteArray d : data.split('\n'))
					m_ReadBuffer.push_back(d);
				return data.size();
			}
			return NULL;
		}

		std::size_t Serial::Send()
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void Serial::open()
		{
			m_SerialPort = new QSerialPort(this);

			m_SerialPort->setPortName(QString::fromStdString(m_PortName));
			m_SerialPort->open(QIODevice::ReadWrite);

			// Todo: set properties according to settings
			m_SerialPort->setBaudRate(QSerialPort::Baud9600);
			m_SerialPort->setStopBits(QSerialPort::OneStop);
			m_SerialPort->setParity(QSerialPort::NoParity);
			m_SerialPort->setDataBits(QSerialPort::Data8);
			m_SerialPort->setFlowControl(QSerialPort::NoFlowControl);

			if (m_SerialPort->isOpen() == true)
				qDebug() << "[INFO] Opened Serial Port: " << m_PortName.c_str();
			else
				qDebug() << "[ERROR] Error opening serial port " << m_PortName.c_str();

		}

		void Serial::close()
		{
			if (m_SerialPort->isOpen())
			{
				m_SerialPort->close();
				qDebug() << "[INFO] Closed Serial Port " << m_PortName.c_str();
			}
		}

		void Serial::slt_FeedUpdate()
		{
			if (!m_SerialPort->bytesAvailable())
			{
				qDebug() << "[WARNING] Received Empty String!";
				return;
			}

			Recieve();

			QByteArray data = m_ReadBuffer.front();
			m_ReadBuffer.pop_front();
			
			std::string dataStr = std::string(data.constData(), data.length());
			m_ReadData = Utils::StringParser(dataStr);

			std::clog << "[INFO] Data Received: " << dataStr;

			emit sgnl_NewData(m_ReadData);
		}
	}
}
