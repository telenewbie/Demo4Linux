#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ua4qml2.h"
#include "ua4qml.h"

//测试qml的界面跳转的测试
#define TEST_QML_UI

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    engine->rootContext()->setContextProperty("$SigDispatcher", new UA4Qml2);
#ifndef TEST_QML_UI
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
#else
    engine->load(QUrl(QStringLiteral("qrc:/first.qml")));
#endif

    return app.exec();
}
