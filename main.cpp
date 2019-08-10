#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ua4qml2.h"
#include "ua4qml.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    engine->rootContext()->setContextProperty("$SigDispatcher", new UA4Qml2);
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
