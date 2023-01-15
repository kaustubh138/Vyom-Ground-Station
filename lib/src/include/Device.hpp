#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <cstddef>
#include <string>

namespace Vyom
{
	class Device 
	{
	public:
		virtual std::size_t Send() = 0;
		virtual void Recieve() = 0;
	};
}

#endif // DEVICE_HPP
