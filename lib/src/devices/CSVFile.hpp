#ifndef CSVFILE_HPP
#define CSVFILE_HPP

#include "../utils/CSVHandler.hpp"
#include "../src/format.hpp"

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
                : m_FilePath(file_name), m_Handler()
            {
                m_ReadData = new std::vector<InputData*>();
            }

            virtual std::size_t Send() override;
            virtual void Recieve() override;

            CSVFile* SetWriteData(const Utils::CSVData& data);
            std::vector<InputData*>* GetData() const { return m_ReadData; }

            inline bool IsEmpty() const { return m_ReadData->size() == 0; }
           
			std::vector<InputData*>::iterator begin() {	return m_ReadData->begin(); }
            std::vector<InputData*>::iterator end() { return m_ReadData->end(); }

        private:
            void parse();

        private:
            std::string m_FilePath;

            Utils::CSVHandler m_Handler;
            std::vector<InputData*>* m_ReadData;
            Utils::CSVData m_WriteData;
        };
    }
}

#endif // CSVFILE_HPP
