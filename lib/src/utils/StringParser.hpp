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

			unsigned int index = 0;
			try
			{
				InputData* row = new InputData{};
				row->teamName = dataVec[index++];
				row->teamID = dataVec[index++];
				row->dk = dataVec[index++];
				row->altitude = Altitude(std::stod(dataVec[index++]));
				row->pressure = Pressure(std::stod(dataVec[index++]));
				row->temperature = Temperature(std::stod(dataVec[index++]), Temperature::Unit::Celsius);
				row->dk2 = dataVec[index++];
				row->accData = Accelerometer(std::stoi(dataVec[index++]),
					std::stoi(dataVec[index++]),
					std::stoi(dataVec[index++]));
				row->gyroData = Gyroscope(std::stoi(dataVec[index++]),
					std::stoi(dataVec[index++]),
					std::stoi(dataVec[index++]));
				row->missionTime = dataVec[index++];
				row->humidity = Humidity(std::stoi(dataVec[index++]));
				row->voltage = Voltage(std::stod(dataVec[index++]));

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
