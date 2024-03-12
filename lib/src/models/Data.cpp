#include "Data.hpp"

namespace Vyom
{
    void Data::slt_UpdateChart(InputData* data)
    {
        static unsigned int packetCount = 0;
        m_Value.setX(packetCount++);
        //m_Value.setX(data->packet.count);

        switch (m_ModelType)
        {
        case(DataModel::Temperature):
        {
            m_Value.setY(29);
            break;
        }
        case(DataModel::Altitude):
        {
            m_Value.setY(568.21);
            break;
        }
        case(DataModel::Voltage):
        {
            m_Value.setY(data->voltage);
            break;
        }
        case (DataModel::yaw):
        {
            m_Value.setY(data->pitchRollYaw.m_GyroZ);
            break;
        }
        case (DataModel::pitch):
        {
            m_Value.setY(data->pitchRollYaw.m_GyroX);
            break;
        }
        default: {
            int val = rand() % (HIGH - LOW + 1) + LOW;
            m_Value.setX(m_Value.x() + 1);
            m_Value.setY(val);
        }
        }

        emit sgnl_ValueChanged();
    }

    Data::Data(Updater* updater, DataModel modeltype, QObject *parent)
        :m_Updater(updater), m_ModelType(modeltype), QObject(parent), m_PacketNum(0)
    {
        connect(m_Updater, &Updater::sgnl_DataChanged, this, &Data::slt_UpdateChart);
    }
}
