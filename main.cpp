#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ua4qml2.h"
#include "ua4qml.h"

//测试qml的界面跳转的测试
//#define TEST_QML_UI
//测试模板
#define TEST_TEMPLETE

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    engine->rootContext()->setContextProperty("$SigDispatcher", new UA4Qml2);

#ifdef TEST_QML_UI
    engine->load(QUrl(QStringLiteral("qrc:/first.qml")));
#endif

    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
