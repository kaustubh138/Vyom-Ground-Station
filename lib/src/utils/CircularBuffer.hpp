#pragma once

#include <iostream>
#include <optional>

namespace Vyom {
    namespace Utils {

        template <typename T, size_t Size>
        class CircularBuffer
    	{
        public:
            CircularBuffer()
        		: m_Head(0), m_Tail(0), m_IsFull(false)
            {}

            ~CircularBuffer() {}

            void Insert(const T& value)
            {
                if (m_IsFull) 
                {
                    // Overwrite the oldest element
                    m_Buffer[m_Head] = value;
                    incrementIndex(m_Head);
                    m_Tail = m_Head;
                }
                else 
                {
                    // Insert at the tail
                    m_Buffer[m_Tail] = value;
                    incrementIndex(m_Tail);

                    if (m_Tail == m_Head)
                        m_IsFull = true;
                }
            }

            std::optional<T> Get()
            {
                if (IsEmpty()) 
                {
                    std::cerr << "[WARNING] Buffer is empty" << std::endl;
                    return std::nullopt;
                }

                T value = m_Buffer[m_Head];
                incrementIndex(m_Head);

                m_IsFull = false;

                return value;
            }

            bool IsEmpty() const { return !m_IsFull && (m_Head == m_Tail); }
            bool IsFull() const { return m_IsFull; }
            static constexpr size_t GetSize() { return Size; }

        private:
            void incrementIndex(size_t& index) { index = (index + 1) % Size; }

        private:
            T m_Buffer[Size];
            size_t m_Head;
            size_t m_Tail;
            bool m_IsFull;
        };
    }
}
