#ifndef CSV_HANDLER_HPP
#define CSV_HANDLER_HPP

#include "../../vendor/rapidcsv/src/rapidcsv.h"

#include <vector>
#include <tuple>

namespace Vyom
{
    namespace Utils
    {
        struct DimType
        {
            std::size_t rows;
            std::size_t columns;
        };

        namespace CSVParserModes
        {
            struct ReadMode{};
            struct WriteMode{};
        }
        using CSVData = std::vector<std::vector<std::string>>;

        class CSVHandler
        {
        public:
            CSVHandler() = default;
            CSVHandler(const std::string& filename, CSVParserModes::ReadMode read);
            CSVHandler(const std::string& filename, CSVParserModes::WriteMode write);

            inline std::size_t GetRowCount() const { return m_Size.rows; }
            inline std::size_t GetColCount() const { return m_Size.columns; }
            inline std::size_t GetDim() const { return m_Size.rows * m_Size.columns; }
            inline rapidcsv::Document GetDocument() const { return m_Document; }

            std::size_t Write(const CSVData& data);

            template<typename T>
            T GetCell(std::size_t row, std::size_t col) {
                return m_Document.GetCell<T>(col, row);
            }

            template<typename T>
            std::vector<T> GetRow(std::size_t row) {
                std::vector<T> data{};
                for (std::size_t c = 0; c < GetColCount(); c++) {
                    data.emplace_back(GetCell<T>(row, c));
                }
                return data;
            }

            template<typename T>
            std::vector<T> GetCol(std::size_t col) {
                std::vector<T> data;
                for (std::size_t r = 0; r < GetRowCount(); r++) {
                    data.push_back(GetCell<T>(r, col));
                }
                return data;
            }

		private:
			class iterator {
			public:
				iterator(CSVHandler& file, size_t row) : m_Handler(file), m_RowIdx(row) {}

				iterator& operator++() {
					++m_RowIdx;
					return *this;
				}

				std::vector<std::string> operator*() const {
					return m_Handler.GetRow<std::string>(m_RowIdx);
				}

				bool operator!=(const iterator& other) const {
					return m_RowIdx != other.m_RowIdx;
				}

			private:
                CSVHandler& m_Handler;
				size_t m_RowIdx;
			};

		public:
			iterator begin() {
				return iterator(*this, 0);
			}

			iterator end() {
				return iterator(*this, GetRowCount() - 1);
			}

        private:
            rapidcsv::Document m_Document;
            DimType m_Size{ NULL, NULL };
            std::string m_FilePath;
        };
    }
}

#endif // CSV_PARSER_HPP
