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
			
			InputData* row = new InputData{};
			row->telemeteryView = "";

			while (stream.good()) {
				std::string substr;
				std::getline(stream, substr, ',');
				dataVec.push_back(substr);
				row->telemeteryView += QString::fromStdString(substr + ", ");
			}

			unsigned int index = 0;
			try
			{
				row->teamId = dataVec[index++];
				row->timeStamp = MissionTime(dataVec[index++]);
				row->packetCount = std::stoi(dataVec[index++]);
				row->accData = Accelerometer(std::stod(dataVec[index++]),
					std::stod(dataVec[index++]),
					std::stod(dataVec[index++]));
				row->pitchRollYaw = Gyroscope(std::stoi(dataVec[index++]),
					std::stoi(dataVec[index++]),
					std::stoi(dataVec[index++]));
				row->altitude = Altitude(std::stod(dataVec[index++]));
				row->temp = Temperature(std::stod(dataVec[index++]), Temperature::Unit::Celsius);
				row->voltage = Voltage(std::stod(dataVec[index++]));
				row->gnssData = Gnss(Altitude(std::stoi(dataVec[index++])),
					dataVec[index++],
					dataVec[index++],
					dataVec[index++]);
				row->rpm1 = std::stoi(dataVec[index++]);
				row->rpm2 = std::stoi(dataVec[index++]);
				row->fswState = dataVec[index++];
				row->camera = dataVec[index++];
				row->mechgyro = dataVec[index++];
				row->lidServoEjection = dataVec[index++];
				row->paraControl = dataVec[index++];
				row->finsDeployment = dataVec[index++];
				row->buzzStatus = dataVec[index++];

				return row;
			}
			catch(...)
			{
				return nullptr;
			}
		}
	}
}

#endif
