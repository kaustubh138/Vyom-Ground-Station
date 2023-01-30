#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <QObject>

#include <cstddef>
#include <string>

#include "../format.hpp"

namespace Vyom
{
	namespace Devices
	{
		class Device 
			: public QObject
		{
			Q_OBJECT

		public:
			virtual std::size_t Send() = 0;
			virtual std::size_t Recieve() = 0;

		public slots:
			virtual void slt_FeedUpdate() = 0;

		signals:
			void sgnl_NewData(InputData* data);
		};
	}
}

#endif // DEVICE_HPP
