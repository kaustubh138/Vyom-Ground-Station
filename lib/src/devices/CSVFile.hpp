#ifndef CSVFILE_HPP
#define CSVFILE_HPP

#include "../utils/CSVHandler.hpp"
#include "../src/format.hpp"

#include <vector>
#include <string>

#include <QTimer>

#include "../include/Device.hpp"

namespace Vyom
{
    namespace Devices
    {       
        class CSVFile 
            : public Device
        {
            Q_OBJECT

        public:
            CSVFile(const std::string& file_name) 
                : m_FilePath(file_name), m_Handler(), m_FeedIndex(0)
            {
                m_ReadData = new std::vector<InputData*>();
            
                m_FeedTimer = new QTimer(this);
                m_FeedTimer->setInterval(1000);
                connect(m_FeedTimer, &QTimer::timeout, this, &CSVFile::slt_FeedUpdate);
                m_FeedTimer->start();
            }

            virtual std::size_t Send() override;
            virtual std::size_t Recieve() override;

            CSVFile* SetWriteData(const Utils::CSVData& data);
            std::vector<InputData*>* GetData() const { return m_ReadData; }

            inline bool IsEmpty() const { return m_ReadData->size() == 0; }
           
			std::vector<InputData*>::iterator begin() {	return m_ReadData->begin(); }
            std::vector<InputData*>::iterator end() { return m_ReadData->end(); }

        public slots:
            virtual void slt_FeedUpdate() override;

        private:
            void parse();

        private:
            std::string m_FilePath;
            std::size_t m_FeedIndex;
            QTimer* m_FeedTimer;

            Utils::CSVHandler m_Handler;
            std::vector<InputData*>* m_ReadData;
            Utils::CSVData m_WriteData;
        };
    }
}

#endif // CSVFILE_HPP
