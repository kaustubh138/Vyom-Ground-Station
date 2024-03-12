#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <chrono>
#include <vector>
#include <string>
#include <algorithm>

#include <QString>

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
        None = 3,
        yaw=4,
        pitch=5
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

	public:
        int m_GyroX, m_GyroY, m_GyroZ;
	};

    class Gnss
    {
    public:
        Gnss() = default;
        Gnss(Altitude alt, std::string lat, std::string longitude, std::string stats)
            : m_Altitude(alt),
            m_Lat(lat),
            m_Long(longitude),
            m_Stats(stats)
        {

        }

    private:
        Altitude m_Altitude;
        std::string m_Lat;
        std::string m_Long;
        std::string m_Stats;
    };

	struct InputData
    {
        QString telemeteryView;
        std::string teamId{};
        std::string timeStamp{};
        unsigned int packetCount;
        Accelerometer accData;
        Gyroscope pitchRollYaw;
        unsigned int altitude;
        double temp;
        Voltage voltage;
        Gnss gnssData;
        int rpm1;
        int rpm2;
        std::string fswState{};
        std::string camera{};
        std::string mechgyro{};
        std::string lidServoEjection{};
        std::string paraControl{};
        std::string finsDeployment{};
        std::string buzzStatus{};

        InputData() = default;
    };
}

#endif // FORMAT_HPP
