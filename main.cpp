#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQuick/QQuickView>
#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>

#include "logger.h"

int main(int argc, char **argv)
{
    // QApplication app(argc, argv);
    // // QQuickWindow::setGraphicsApi(QSGRendererInterface::Metal);

    // QQuickView view;
    // view.setResizeMode(QQuickView::SizeRootObjectToView);
    // view.setSource(QUrl("qrc:///scenegraph/metaltextureimport/main.qml"));
    // // view.resize(1280, 720);
    // // view.setFlags(Qt::FramelessWindowHint);
    // // view.show();
    // QWidget* widget = QWidget::createWindowContainer(&view);
    // //widget->resize(800, 600);
    // //widget->show();

    // QQuickView logger;
    // Logger log;
    // qmlRegisterType<Logger>("Logger", 1, 0, "Logger");
    // logger.setSource(QUrl("qrc:///scenegraph/metaltextureimport/Logger.qml"));
    // //logger.resize(1280, 400);
    // //logger.show();
    // QWidget* loggerWidget = QWidget::createWindowContainer(&logger);
    // //loggerWidget->resize(1280, 200);
    // //loggerWidget->show();

    // QWidget* mainWindow = new QWidget();
    // QVBoxLayout* layout = new QVBoxLayout(mainWindow);
    // layout->addWidget(widget, 2);
    // layout->addWidget(loggerWidget, 1);
    // mainWindow->resize(1280, 720);
    // mainWindow->show();

    // return app.exec();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("Logger_text", &engine_logger);

    const QUrl url{QUrl("qrc:///scenegraph/metaltextureimport/main.qml")};
    const QUrl log_url{QUrl("qrc:///scenegraph/metaltextureimport/Logger.qml")};
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    QObject::connect(&engine_logger, &Logger::dataChanged, [&engine](){
        engine.rootObjects().first()->setProperty("mainDataChanged", true);
    });
    engine.load(url);

    return app.exec();
}
