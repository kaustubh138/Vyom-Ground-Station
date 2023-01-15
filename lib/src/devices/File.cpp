#include "File.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

namespace Vyom
{
	File::File(const std::string& fpath)
		: m_Path(fpath)
	{}

	std::string File::Read()
	{
		std::ifstream stream(m_Path);
		if (stream)
			return std::string(std::istreambuf_iterator<char>(stream), (std::istreambuf_iterator<char>()));
		else
			std::cerr << "Failed to open file " << m_Path << std::endl;
		return {};
	}
	
	std::size_t File::Send()
	{
		return std::size_t();
	}

	std::string File::Recieve()
	{
		return Read();
	}
}
