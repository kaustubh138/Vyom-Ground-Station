#ifndef TELEMETERY_VIEW_HPP
#define TELEMETERY_VIEW_HPP

#include "Updater.hpp"

#include <QObject>
#include <QTextStream>

namespace Vyom
{
	class TelemeteryView
		: public QObject
	{
		Q_OBJECT
		Q_PROPERTY(QString GetValue READ GetValue NOTIFY sgnl_TelemeteryUpdated)

	public:
		TelemeteryView(Updater* updater, QObject* parent = Q_NULLPTR);
		QString GetValue() const { return m_Value; }

	private:
		QString m_Value;
		Updater* m_Updater;
		
	signals:
		void sgnl_TelemeteryUpdated();

	private slots:
		void slt_UpdateTelemetery(InputData* data);
	};
}

#endif // TELEMETERY_VIEW_HPP
