#ifndef FILE_HPP
#define FILE_HPP

#include "../include/Device.hpp"

namespace Vyom
{
	class File
		: public Device
	{
	private: 
		std::string m_Path;

	public:
		File(const std::string& fpath);

		virtual std::size_t Send() override;
		virtual std::string Recieve() override;

	private:
		std::string Read();
	};
}

#endif // FILE_HPP
