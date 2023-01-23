#include "CSVFile.hpp"

namespace Vyom
{
	namespace Devices
	{
		std::size_t CSVFile::Send()
		{
			m_Handler = Utils::CSVHandler{ m_FilePath, Utils::CSVParserModes::WriteMode{} };
            return m_Handler.Write(m_WriteData);
		}

		void CSVFile::Recieve()
		{
			m_Handler = Utils::CSVHandler{m_FilePath, Utils::CSVParserModes::ReadMode{} };
			parse();
		}

		CSVFile* CSVFile::SetWriteData(const Utils::CSVData& data)
		{
			m_WriteData = data;
			return this;
		}

		void CSVFile::slt_FeedUpdate()
		{
			if (m_FeedIndex < m_ReadData->size())
				emit Device::sgnl_NewData((*m_ReadData)[m_FeedIndex++]);
		}

		void CSVFile::parse()
		{
			int index = 0;
			for (auto item : m_Handler)
			{
				index = 0;
				InputData* row = new InputData();
				row->teamID = TeamID(std::stoi(item[index++]));
				row->missionTime = MissionTime(item[index++]);
				row->packet = PacketData{ std::stoull(item[index++]), item[index++] };
				row->mode = item[index++];													// Mode
				row->tp_released = item[index++];						// TP_RELEASED
				row->altitude = Altitude(std::stod(item[index++]));
				row->temperature = Temperature(std::stod(item[index++]), Temperature::Unit::Celsius);
				row->voltage = Voltage(std::stod(item[index++]));
				row->gps = GPSData(item[index++], std::stod(item[index++]), std::stod(item[index++]), std::stod(item[index++]), std::stoi(item[index++])); // GPS = Latitude Longitude Time Sat
				row->software_state = item[index++];		// Software State
				row->cmdEcho = item[index++];				// CMD Echo

				m_ReadData->emplace_back(row);
			}
		}
	}
}
