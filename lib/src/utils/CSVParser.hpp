#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include "../devices/CSVFile.hpp"
#include "../format.hpp"

#include <string>

/*
* Format of input data
*	TEAM_ID, MISSION_TIME, PACKET_COUNT, PACKET_TYPE, MODE,
*	TP_RELEASED, ALTITUDE, TEMP, VOLTAGE, GPS_TIME, GPS LATITUDE,
*	GPS_LONGITUDE, GPS_ALTITUDE, GPS_SATS, SOFTWARE_STATE, CMD_ECHO
*
*/

namespace Vyom
{
	static std::vector<InputData*>* s_PlotData;

	namespace Utils
	{
		class CSVParser
		{
		public:
			CSVParser(const std::string& filename)
				: m_File(filename)
			{
				m_File.Recieve();
			}

            std::vector<InputData*>* operator()()
            {
				s_PlotData = new std::vector<InputData*>;
				int index = 0;
				for (auto item : m_File)
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
					
					s_PlotData->emplace_back(row);
                }
				return s_PlotData;
            }

		private:
            Devices::CSVFile m_File;
		};
	}
}

#endif // CSV_PARSER_HPP
