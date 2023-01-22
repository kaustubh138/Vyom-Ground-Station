#include "Data.hpp"

namespace Vyom
{
    void Data::slt_UpdateChart()
    {
	    int val = rand() % (HIGH - LOW + 1) + LOW;
        m_Value.setX(m_Updater->value().packet.count + 1);
        m_Value.setY(m_Updater->value().altitude +  1);
        emit sgnl_ValueChanged();
    }

    Data::Data(Updater* updater, QObject *parent)
        :m_Updater(updater), QObject(parent)
    {
        connect(m_Updater, &Updater::sgnl_DataChanged, this, &Data::slt_UpdateChart);
    }
}
