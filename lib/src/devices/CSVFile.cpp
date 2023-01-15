#include "CSVFile.hpp"

namespace Vyom
{
	namespace Devices
	{
		std::size_t CSVFile::Send()
		{
			m_Parser = Utils::CSVHandler{ m_FilePath, Utils::CSVParserModes::WriteMode{} };
            return m_Parser.Write(m_WriteData);
		}

		void CSVFile::Recieve()
		{
			m_Parser = Utils::CSVHandler{m_FilePath, Utils::CSVParserModes::ReadMode{} };
		}

		CSVFile* CSVFile::SetWriteData(const Utils::CSVData& data)
		{
			m_WriteData = data;
			return this;
		}
	}
}
