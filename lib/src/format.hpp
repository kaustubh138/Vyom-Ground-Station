#ifndef FORMAT_HPP
#define FORMAT_HPP

/*
* Format of input data
*	TEAM_ID, MISSION_TIME, PACKET_COUNT, PACKET_TYPE, MODE,
*	TP_RELEASED, ALTITUDE, TEMP, VOLTAGE, GPS_TIME, GPS LATITUDE,
*	GPS_LONGITUDE, GPS_ALTITUDE, GPS_SATS, SOFTWARE_STATE, CMD_ECHO
* 
* Time Data:
*	1. Mission Time
*	2. GPS Time
*/

#include <chrono>

namespace Vyom
{
    struct MissionTime {
        std::chrono::system_clock::time_point time;
        std::string epoch;
        std::string time_system;

        MissionTime(std::chrono::system_clock::time_point t, std::string e, std::string ts) :
            time(t), epoch(e), time_system(ts) 
        {}
    };
}

#endif // FORMAT_HPP
