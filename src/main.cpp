#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext> // Add

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/UI/Main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    // Add
#ifdef QT_DEBUG
    engine.rootContext()->setContextProperty("QT_DEBUG", true);
#else
    engine.rootContext()->setContextProperty("QT_DEBUG", false);
#endif

    return app.exec();
}
