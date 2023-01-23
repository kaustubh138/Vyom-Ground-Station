#include "Data.hpp"

namespace Vyom
{
    void Data::slt_UpdateChart(InputData* data)
{
	    m_Value.setX(data->packet.count);
        m_Value.setY(data->altitude);
        emit sgnl_ValueChanged();
    }

    Data::Data(Updater* updater, QObject *parent)
        :m_Updater(updater), QObject(parent)
    {
        connect(m_Updater, &Updater::sgnl_DataChanged, this, &Data::slt_UpdateChart);
    }
}
