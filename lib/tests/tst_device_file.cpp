#include <QTest>
#include <QTemporaryFile>
#include <QDebug>

#include "../src/devices/File.hpp"

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
            Vyom::File device{ "test_data/file_device.csv"};
			QVERIFY(!device.Recieve().empty());
		}

	private:
		QTemporaryFile m_TempFile;
	};

}

QTEST_MAIN(Vyom::Tests::Device_File_Tests)

#include "tst_device_file.moc"
