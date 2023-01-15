#include <QTest>
#include <QTemporaryFile>
#include <QDebug>

#include "../src/devices/CSVFile.hpp"

static const constexpr char* tempContents = "This is a temperory file";

namespace Vyom::Tests
{
	class Device_File_Tests
		: public QObject
	{
		Q_OBJECT

	private slots:
		void initTestCase()
		{
			if (m_TempFile.exists())
				return;

			QVERIFY2(m_TempFile.open(), "Failed to create a temprory file");
			QFile file{ m_TempFile.fileName() };

			QVERIFY(file.open(QIODevice::ReadWrite));
			QTextStream stream{ &file };

			stream << tempContents;
		}

		void readTest()
		{
            Vyom::Devices::CSVFile device{ "test_data/file_device.csv"};
			device.Recieve();
			QVERIFY(device.IsEmpty() == false);
		}

		void writeTest()
		{
			Vyom::Devices::CSVFile device{ "test_data/write_test.csv" };
			Vyom::Utils::CSVData data = {
				{"Name", "Age", "Gender"},
				{"John", "30", "Male"},
				{"Jane", "25", "Female"},
				{"Bob", "35", "Male"}
			};
			
			std::size_t sent = device.SetWriteData(data)->Send();
			device.Recieve();
			QVERIFY(sent == data.size());
			QVERIFY(device.IsEmpty());
		}

	private:
		QTemporaryFile m_TempFile;
	};

}

QTEST_MAIN(Vyom::Tests::Device_File_Tests)

#include "tst_device_file.moc"
