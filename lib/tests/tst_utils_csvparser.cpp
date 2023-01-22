#include <QTest>
#include <QTemporaryFile>
#include <QDebug>

#include "../src/utils/CSVParser.hpp"

static const constexpr char* tempContents = "This is a temperory file";

namespace Vyom::Tests
{
	class CSVParser_Test
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
			QTextStream stream{ &file };		}

		void parseTest()
		{
			Vyom::Devices::CSVFile device{ "test_data/file_device.csv" };
			device.Recieve();

			Utils::CSVParser parser = Utils::CSVParser("test_data/parser_test.csv");
			std::vector<InputData*>* out = parser();
		}
		
	private:
		QTemporaryFile m_TempFile;
	};

}

QTEST_MAIN(Vyom::Tests::CSVParser_Test)

#include "tst_utils_csvparser.moc"
