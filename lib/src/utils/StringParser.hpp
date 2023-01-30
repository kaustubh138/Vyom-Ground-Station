#ifndef STRING_PARSER_HPP
#define STRING_PARSER_HPP

#include "../format.hpp"
#include <sstream>
#include <string>

namespace Vyom
{
	namespace Utils
	{
		static InputData* StringParser(const std::string& data)
		{
			std::vector<std::string> dataVec;
			dataVec.reserve(20);

			std::istringstream stream{data};
			std::string buffer{};

			while (stream.good()) {
				std::string substr;
				std::getline(stream, substr, ',');
				dataVec.push_back(substr);
			}

			InputData* row = new InputData();
			for (std::string d : dataVec)
			{
				row->teamID = TeamID(std::stoi(d));
				row->missionTime = MissionTime(d);
				row->packet = PacketData{ std::stoull(d), d };
				row->mode = d;												// Mode
				row->tp_released = d;										// TP_RELEASED
				row->altitude = Altitude(std::stod(d));
				row->temperature = Temperature(std::stod(d), Temperature::Unit::Celsius);
				row->voltage = Voltage(std::stod(d));
				row->gps = GPSData(d, std::stod(d), std::stod(d),
					std::stod(d), std::stoi(d));							// GPS = Latitude Longitude Time Sat
				row->software_state = d;									// Software State
				row->cmdEcho = d;											// CMD Echo
			}
			
			return row;

		}
	}
}

#endif
