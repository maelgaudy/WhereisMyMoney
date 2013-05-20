#include "loader.hpp"


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Constructor & destructor
Loader::Loader(QObject* parent) : QObject(parent) {

    m_config = new Configurator(this);
    QStringList accountList;
    accountList << "Compte courant" << "Livret A" << "Livret jeune";

    m_mainView = new QQuickView;
    m_mainView->rootContext()->setContextProperty("accountList", QVariant::fromValue(accountList));
    m_mainView->setSource(QUrl::fromLocalFile("qml/WhereisMyMoney/main.qml"));
    m_mainView->setResizeMode(QQuickView::SizeRootObjectToView);

    m_mainView->show();

    m_mainView->setFramePosition(m_config->windowPosition());
    m_mainView->setWidth(m_config->windowSize().width());
    m_mainView->setHeight(m_config->windowSize().height());

    m_mainViewObject = m_mainView->rootObject();
    QMetaObject::invokeMethod(m_mainViewObject, "setBarPosition", Q_ARG(QVariant, 1),
                              Q_ARG(QVariant, m_config->bar1Pos()));
    QMetaObject::invokeMethod(m_mainViewObject, "setBarPosition", Q_ARG(QVariant, 2),
                              Q_ARG(QVariant, m_config->bar2Pos()));
}


Loader::~Loader() {

    m_config->setWindowPosition(m_mainView->framePosition());
    m_config->setWindowSize(QSize(m_mainView->width(), m_mainView->height()));

    QVariant barPos;
    QMetaObject::invokeMethod(m_mainViewObject, "getBarPosition", Q_RETURN_ARG(QVariant, barPos),
                              Q_ARG(QVariant, 1));
    m_config->setBar1Pos(barPos.toInt());
    QMetaObject::invokeMethod(m_mainViewObject, "getBarPosition", Q_RETURN_ARG(QVariant, barPos),
                              Q_ARG(QVariant, 2));
    m_config->setBar2Pos(barPos.toInt());

    m_config->saveSettings();

    delete m_mainViewObject;
}
