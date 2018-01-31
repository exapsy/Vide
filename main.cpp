#include <QApplication>
#include <QQmlApplicationEngine>
 #include "./src/services/Serial/serialportmanager.hpp"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    qmlRegisterType<SerialPortManager>("com.Vide.qml", 1, 0, "SerialPortManager");

    QQmlApplicationEngine engine;

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));



    return app.exec();
}
