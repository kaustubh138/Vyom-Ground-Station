#include "CSVFile.hpp"
#include "../utils/StringParser.hpp"

namespace Vyom
{
	namespace Devices
	{
		std::size_t CSVFile::Send()
		{
			m_Handler = Utils::CSVHandler{ m_FilePath, Utils::CSVParserModes::WriteMode{} };
            return m_Handler.Write(m_WriteData);
		}

		std::size_t CSVFile::Recieve()
		{
			m_Handler = Utils::CSVHandler{m_FilePath, Utils::CSVParserModes::ReadMode{} };
			parse();
			return m_ReadData->size();
		}

		CSVFile* CSVFile::SetWriteData(const Utils::CSVData& data)
		{
			m_WriteData = data;
			return this;
		}

		void CSVFile::slt_FeedUpdate()
		{
			if (m_FeedIndex < m_ReadData->size())
				emit Device::sgnl_NewData((*m_ReadData)[m_FeedIndex++]);
		}

		void CSVFile::parse()
		{
			for (std::vector<std::string> item : m_Handler)
			{
				InputData* row = Utils::StringParser(item);
				m_ReadData->emplace_back(row);
			}
		}
	}
}
