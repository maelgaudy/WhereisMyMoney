#ifndef LOADER_HPP
#define LOADER_HPP


#include <QObject>
#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QQuickView>
#include <QQmlContext>
#include <QStringList>
#include <QQuickItem>
#include "configurator.hpp"


class Loader : public QObject {

    Q_OBJECT

public:

    explicit Loader(QObject* parent = 0);
    ~Loader();


protected:

    QQuickView*     m_mainView;
    QObject*        m_mainViewObject;
    Configurator*   m_config;
};

#endif // LOADER_HPP
