#ifndef CSVFILE_HPP
#define CSVFILE_HPP

#include "../utils/CSVHandler.hpp"

#include <vector>
#include <string>

#include "../include/Device.hpp"

namespace Vyom
{
    namespace Devices
    {       
        class CSVFile 
            : public Device
        {
        public:
            CSVFile(const std::string& file_name) 
                : m_FilePath(file_name), m_Parser()
            {}

            virtual std::size_t Send() override;
            virtual void Recieve() override;

            CSVFile* SetWriteData(const Utils::CSVData& data);

            inline bool IsEmpty() const { return !(m_Parser.GetRowCount() > 1); }
            inline std::size_t GetTotalElems() const { return m_Parser.GetRowCount(); }

        private:
            class iterator {
            public:
                iterator(CSVFile& file, size_t row) : m_Document(file), m_RowIdx(row) {}

                iterator& operator++() {
                    ++m_RowIdx;
                    return *this;
                }

                std::vector<std::string> operator*() const {
                    return m_Document.m_Parser.GetRow<std::string>(m_RowIdx);
                }

                bool operator!=(const iterator& other) const {
                    return m_RowIdx != other.m_RowIdx;
                }

            private:
                CSVFile& m_Document;
                size_t m_RowIdx;
            };

        public:
            iterator begin() {
                return iterator(*this, 0);
            }

            iterator end() {
                return iterator(*this, m_Parser.GetRowCount() - 1);
            }

        private:
            std::string m_FilePath;

            Utils::CSVHandler m_Parser;
            Utils::CSVData m_WriteData;
        };
    }
}

#endif // CSVFILE_HPP
