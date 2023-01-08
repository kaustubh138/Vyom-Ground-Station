#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Data.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataFromCpp", new Data());
    engine.load(QUrl(QStringLiteral("qrc:///app.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
