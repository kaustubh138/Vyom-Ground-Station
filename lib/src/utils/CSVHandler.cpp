#include "CSVHandler.hpp"

namespace Vyom
{
    namespace Utils
    {
        CSVHandler::CSVHandler(const std::string& filename, CSVParserModes::ReadMode read)
            : m_Document(filename, rapidcsv::LabelParams(-1, -1)), m_FilePath(filename)
        {
            m_Size = DimType{m_Document.GetRowCount(), m_Document.GetColumnCount()};
        }
        
        CSVHandler::CSVHandler(const std::string& filename, CSVParserModes::WriteMode write)
        {
            m_FilePath = filename;

            std::ofstream file(m_FilePath);
            if (!file.good())
            {
                std::fstream file;
                file.open(m_FilePath, std::ios::out);
                if (!file)
                    std::cout << "[ERROR] Unable to create file" << m_FilePath;
            }
                
            m_Document = rapidcsv::Document(filename, rapidcsv::LabelParams(-1, -1));
            m_Size = DimType{m_Document.GetColumnCount(), m_Document.GetRowCount()};
        }
        
        std::size_t CSVHandler::Write(const CSVData& data)
        {
            std::size_t writtenSize{};
            for (size_t i = 0; i < data.size(); ++i) {
                m_Document.InsertRow(i, data[i]);
                writtenSize++;
            }

            m_Size = DimType{ m_Document.GetColumnCount(), m_Document.GetRowCount() };
            m_Document.Save(m_FilePath);
            return writtenSize;
        }
    }
}
