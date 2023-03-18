#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QObject>

#include "Data.hpp"
#include "Updater.hpp"
#include "../src/devices/Serial.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Vyom::Devices::Serial* device = new Vyom::Devices::Serial("COM7");

    Vyom::Updater* updater = new Vyom::Updater(device);

    Vyom::Data* altitudeData = new Vyom::Data(updater, Vyom::DataModel::Altitude);
    Vyom::Data* temperatureData = new Vyom::Data(updater, Vyom::DataModel::Temperature);
    Vyom::Data* voltageData = new Vyom::Data(updater, Vyom::DataModel::Voltage);
    Vyom::Data* dummyData = new Vyom::Data(updater, Vyom::DataModel::None);
    
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("altitudeData", altitudeData);
    engine.rootContext()->setContextProperty("tempData", temperatureData);
    engine.rootContext()->setContextProperty("voltageData", voltageData);
    engine.rootContext()->setContextProperty("dummyData", dummyData);
    engine.load(QUrl(QStringLiteral("qrc:///app.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
