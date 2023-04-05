#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <chrono>
#include <vector>
#include <string>
#include <algorithm>

/*
* Format of input data
*	TEAM_ID, MISSION_TIME, PACKET_COUNT, PACKET_TYPE, MODE,
*	TP_RELEASED, ALTITUDE, TEMP, VOLTAGE, GPS_TIME, GPS LATITUDE,
*	GPS_LONGITUDE, GPS_ALTITUDE, GPS_SATS, SOFTWARE_STATE, CMD_ECHO
*
*/

namespace Vyom
{
    using UnknownType = std::string;

    using TeamID = unsigned int;

    using Altitude = double;
    using Voltage = double;
    using Humidity = double;
    using Pressure = double;

    enum class DataModel
    {
        Temperature = 0,
        Altitude = 1,
        Voltage = 2,
        None = 3
    };

    struct MissionTime {
        std::chrono::steady_clock::time_point time;
        std::string epoch;
        std::string time_system;

        MissionTime() = default;

        MissionTime(std::string& timeString)
        {
            timeString.erase(std::remove_if(timeString.begin(), timeString.end(), [](char c) { return c == '.' || c == ':'; }), timeString.end());
            time = std::chrono::steady_clock::time_point(std::chrono::system_clock::duration(std::stoll(timeString)));
        }

        MissionTime(const std::chrono::steady_clock::time_point& t, const std::string& e, const std::string& ts) :
            time(t), epoch(e), time_system(ts) 
        {}
    };

    struct GPSData
    {
        std::chrono::time_point<std::chrono::steady_clock> time;
        double latitude;
        double longitude;
        double altitude;
        int sat;

        GPSData() = default;

        GPSData(std::string& timeString, double lat, double longi, double altitude, int sat)
            : latitude(lat), longitude(longi), sat(sat)
        {
            timeString.erase(std::remove_if(timeString.begin(), timeString.end(), [](char c) { return c == '.' || c == ':'; }), timeString.end());
            time = std::chrono::steady_clock::time_point(std::chrono::system_clock::duration(std::stoll(timeString)));
        }
    };

    class Temperature 
    {
    public:
        enum class Unit { Kelvin, Celsius, Fahrenheit };

        Temperature() = default;
        Temperature(double temp, Unit u = Unit::Celsius) 
            : temperature(temp), unit(u) 
        {}

        double GetTemperature() const { return temperature; }
        Unit GetUnit() const { return unit; }

        double toKelvin() const 
        {
            if (unit == Unit::Kelvin) {
                return temperature;
            }
            else if (unit == Unit::Celsius) {
                return temperature + 273.15;
            }
            else {
                return (temperature + 459.67) * 5 / 9;
            }
        }

        double toCelsius() const 
        {
            if (unit == Unit::Celsius) {
                return temperature;
            }
            else if (unit == Unit::Kelvin) {
                return temperature - 273.15;
            }
            else {
                return (temperature - 32) * 5 / 9;
            }
        }

        double toFahrenheit() const 
        {
            if (unit == Unit::Fahrenheit) {
                return temperature;
            }
            else if (unit == Unit::Kelvin) {
                return temperature * 9 / 5 - 459.67;
            }
            else {
                return temperature * 9 / 5 + 32;
            }
        }

    private:
        double temperature = 0;
        Unit unit = Unit::Celsius;
    };

    struct PacketData
    {
        std::size_t count = 0;
        std::string type = "";
    };

    class Accelerometer
	{
	public:
        Accelerometer() = default;
		Accelerometer(int acc_x, int acc_y, int acc_z)
			: m_AccX(acc_x),
			  m_AccY(acc_y),
			  m_AccZ(acc_z)
		{}

	private:
        int m_AccX, m_AccY, m_AccZ;
	};

	class Gyroscope
	{
	public:
        Gyroscope() = default;
		Gyroscope(int gyro_x, int gyro_y, int gyro_z)
			: m_GyroX(gyro_x),
			  m_GyroY(gyro_y),
			  m_GyroZ(gyro_z)
		{}

	private:
        int m_GyroX, m_GyroY, m_GyroZ;
	};


	/*
	 * Old Format:

	struct InputData
    {
        TeamID teamID = 0;
        MissionTime missionTime;
        PacketData packet;
        UnknownType mode;
        UnknownType tp_released;
        Altitude altitude = 0;
        Temperature temperature;
        Voltage voltage = 0;
        GPSData gps;
        UnknownType software_state;
        UnknownType cmdEcho;
        
        InputData() = default;
		InputData(TeamID team, MissionTime mission, PacketData pack, UnknownType md, std::string& tp, Altitude alt, Temperature temp, Voltage volt, GPSData gps, UnknownType st, UnknownType cmd)
			: teamID(team), missionTime(mission), packet(pack), mode(md), tp_released(tp), altitude(alt), temperature(temp), voltage(volt), gps(gps), software_state(st), cmdEcho(cmd)
		{}
    };

	*/

    // New Format for Test
    struct InputData
    {
        std::string teamName{};
        std::string teamID{};
        UnknownType dk{};
        Altitude altitude = 0;
        Temperature temperature;
        Pressure pressure = 0;
        UnknownType dk2{};
        UnknownType missionTime;
        Accelerometer accData{};
        Gyroscope gyroData{};
        Voltage voltage = 0;
        Humidity humidity = 0;
        UnknownType dk3{};

        InputData() = default;
    };

}

#endif // FORMAT_HPP
