//#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <controller.h>


int main(int argc, char *argv[])
{


    //QGuiApplication app(argc, argv);
    QApplication app(argc,argv);

    Controller c;


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("controller", &c);



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));




    return app.exec();
}
