#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "loader.hpp"


int main(int argc, char *argv[]) {

    QGuiApplication app(argc, argv);

    Loader loader;

    return app.exec();
}
