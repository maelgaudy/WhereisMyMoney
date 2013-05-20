#include "configurator.hpp"


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Constructor & destructor
Configurator::Configurator(QObject* parent) : QObject(parent) {

    m_appSettings = new QSettings(ORGANISATION, APPLICATION, this);

    this->loadSettings();

    if(m_pathToMainFile == DEFAULT_NOFILE) {
        // The user has to create one
    }
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Public method
const QString& Configurator::pathToMainFile() const {

    return m_pathToMainFile;
}


const QPoint& Configurator::windowPosition() const {

    return m_windowPosition;
}


const QSize& Configurator::windowSize(void) const {

    return m_windowSize;
}


int Configurator::bar1Pos(void) const {

    return m_bar1Pos;
}


int Configurator::bar2Pos(void) const {

    return m_bar2Pos;
}


void Configurator::setPathToMainFile(const QString& newPath) {

    m_pathToMainFile = newPath;
}


void Configurator::setWindowPosition(const QPoint& newPosition) {

    m_windowPosition = newPosition;
}


void Configurator::setWindowSize(const QSize& newSize) {

    m_windowSize = newSize;
}


void Configurator::setBar1Pos(int newBarPos) {

    m_bar1Pos = newBarPos;
}


void Configurator::setBar2Pos(int newBarPos) {

    m_bar2Pos = newBarPos;
}


void Configurator::loadSettings(void) {

    m_pathToMainFile = m_appSettings->value("Datas/MainFile", DEFAULT_NOFILE).toString();
    m_windowSize = m_appSettings->value("Window/Size", QSize(800, 600)).toSize();
    m_windowPosition = m_appSettings->value("Window/Position", QPoint(100, 100)).toPoint();
    m_bar1Pos = m_appSettings->value("Window/Bar1Pos", int(m_windowSize.width()/3)).toInt();
    m_bar2Pos = m_appSettings->value("Window/Bar2Pos", int(m_windowSize.width()*2/3)).toInt();
}


void Configurator::saveSettings(void) {

    m_appSettings->setValue("Datas/MainFile", m_pathToMainFile);
    m_appSettings->setValue("Window/Size", m_windowSize);
    m_appSettings->setValue("Window/Position", m_windowPosition);
    m_appSettings->setValue("Window/Bar1Pos", m_bar1Pos);
    m_appSettings->setValue("Window/Bar2Pos", m_bar2Pos);
}
