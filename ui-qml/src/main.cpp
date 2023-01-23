#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QObject>

#include "Data.hpp"
#include "Updater.hpp"
#include "../src/devices/CSVFile.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	
    QTimer* timer = new QTimer(&app);

    Vyom::Devices::CSVFile* device = new Vyom::Devices::CSVFile( "parser_test.csv");
    device->Recieve();
    Vyom::Updater* updater = new Vyom::Updater(device);

    Vyom::Data* altitudeData = new Vyom::Data(updater);
    
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataFromCpp", altitudeData);
    engine.load(QUrl(QStringLiteral("qrc:///app.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
