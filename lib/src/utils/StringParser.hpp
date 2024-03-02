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

			try
			{
				unsigned int index = 0;
				if (index + 1 < dataVec.size() - 1)
					row->teamId = dataVec[index++];
				if (index + 1 < dataVec.size() - 1)
					row->timeStamp = dataVec[index++];
				if (index + 1 < dataVec.size() - 1)
					row->packetCount = std::stoi(dataVec[index++]);
				if (index + 3 < dataVec.size() - 1)
					row->accData = Accelerometer(std::stod(dataVec[index++]),
						std::stod(dataVec[index++]),
						std::stod(dataVec[index++]));
				if (index + 3 < dataVec.size() - 1)
					row->pitchRollYaw = Gyroscope(std::stoi(dataVec[index++]),
						std::stoi(dataVec[index++]),
						std::stoi(dataVec[index++]));
				if (index + 1 < dataVec.size() - 1)
					row->altitude = std::stod(dataVec[index++]);
				if (index + 1 < dataVec.size() - 1)
					row->temp = std::stod(dataVec[index++]);
				if (index + 1 < dataVec.size() - 1)
					row->voltage = Voltage(std::stod(dataVec[index++]));
				if (index + 4 < dataVec.size() - 1)
					row->gnssData = Gnss(std::stoi(dataVec[index++]),
						dataVec[index++],
						dataVec[index++],
						dataVec[index++]);
				if (index + 1 < dataVec.size() - 1)
					row->rpm1 = std::stoi(dataVec[index++]);
				if (index + 1 < dataVec.size() - 1)
					row->rpm2 = std::stoi(dataVec[index++]);
				if (index + 1 < dataVec.size() - 1)
					row->fswState = dataVec[index++];
				if (index + 1 < dataVec.size() - 1)
					row->camera = dataVec[index++];
				if (index + 1 < dataVec.size() - 1)
					row->mechgyro = dataVec[index++];
				if (index + 1 < dataVec.size() - 1)
					row->lidServoEjection = dataVec[index++];
				if (index + 1 < dataVec.size() - 1)
					row->paraControl = dataVec[index++];
				if (index + 1 < dataVec.size() - 1)
					row->finsDeployment = dataVec[index++];
				if (index + 1 < dataVec.size() - 1)
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
