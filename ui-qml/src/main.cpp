#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QObject>

#include "Data.hpp"
#include "src/utils/CSVParser.hpp"
#include "Updater.hpp"
#include "../src/devices/CSVFile.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	
    QTimer* timer = new QTimer(&app);
    
    Vyom::Updater* updater = new Vyom::Updater();
    
    Vyom::Data* altitudeData = new Vyom::Data(updater);

    QObject::connect(timer, &QTimer::timeout,updater, &Vyom::Updater::slt_SetInputData);
    timer->start(1000); // update every 1000 milliseconds

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataFromCpp", altitudeData);
    engine.load(QUrl(QStringLiteral("qrc:///app.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
