#include "Data.hpp"

void Data::slt_Timeout()
{
    int val = rand() % (HIGH - LOW + 1) + LOW;
    m_Value.setX(m_Value.x()+1);
    m_Value.setY(val);
    emit sgnl_ValueChanged();
}

Data::Data(QObject *parent):QObject(parent)
{
    m_Timer = new QTimer(this);
    m_Timer->setInterval((1000 / 5));
    connect(m_Timer, &QTimer::timeout, this, &Data::slt_Timeout);
    m_Timer->start();
}
