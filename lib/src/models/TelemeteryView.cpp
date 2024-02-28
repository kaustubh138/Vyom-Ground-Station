#include "TelemeteryView.hpp"

namespace Vyom
{
    void TelemeteryView::slt_UpdateTelemetery(InputData* data)
    {
        m_Value = data->telemeteryView;
        emit sgnl_TelemeteryUpdated();
    }

    TelemeteryView::TelemeteryView(Updater* updater, QObject* parent)
        :m_Updater(updater), QObject(parent)
    {
        connect(m_Updater, &Updater::sgnl_DataChanged, this, &TelemeteryView::slt_UpdateTelemetery);
    }
}