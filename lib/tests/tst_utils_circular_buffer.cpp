#include <QTest>

#include "../utils/CircularBuffer.hpp"

namespace Vyom
{
	namespace Tests
	{
		using namespace Utils;

		class CircularBuffer_Tests
			: public QObject
		{
			Q_OBJECT

		private slots:
		    void init() {}
			
		    void testInsert()
			{
		        Vyom::Utils::CircularBuffer<int, 5> buffer;

		        QVERIFY(buffer.IsEmpty());

		        buffer.Insert(1);
		        buffer.Insert(2);
		        buffer.Insert(3);
		        buffer.Insert(4);
		        buffer.Insert(5);

		        QVERIFY(buffer.IsFull());
		    }

		    void testRemove()
			{
		        Vyom::Utils::CircularBuffer<int, 5> buffer;

				std::optional<int> value = buffer.Get();
				QVERIFY(value.has_value() == false);

		        buffer.Insert(1);
		        buffer.Insert(2);
		        buffer.Insert(3);
		        buffer.Insert(4);
		        buffer.Insert(5);

		        QCOMPARE(buffer.Get(), 1);
		        QCOMPARE(buffer.Get(), 2);
		        QCOMPARE(buffer.Get(), 3);
		        QCOMPARE(buffer.Get(), 4);
		        QCOMPARE(buffer.Get(), 5);

		        QVERIFY(buffer.IsEmpty());
		    }
		};
	}
}

QTEST_MAIN(Vyom::Tests::CircularBuffer_Tests)

#include "tst_utils_circular_buffer.moc"