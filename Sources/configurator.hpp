#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H


#include <QObject>
#include <QSettings>
#include <QSize>
#include <QPoint>


#define ORGANISATION    "MaelSoft"
#define APPLICATION     "WhereIsMyMoney"
#define DEFAULT_NOFILE  "NoMainFile"


class Configurator : public QObject {

    Q_OBJECT

public:

    explicit Configurator(QObject* parent = 0);

    const QString& pathToMainFile(void) const;
    const QPoint& windowPosition(void) const;
    const QSize& windowSize(void) const;
    int bar1Pos(void) const;
    int bar2Pos(void) const;
    void setPathToMainFile(const QString& newPath);
    void setWindowPosition(const QPoint& newPosition);
    void setWindowSize(const QSize& newSize);
    void setBar1Pos(int newBarPos);
    void setBar2Pos(int newBarPos);

    void loadSettings(void);
    void saveSettings(void);


private:

    QSettings*      m_appSettings;
    QString         m_pathToMainFile;
    QPoint          m_windowPosition;
    QSize           m_windowSize;
    int             m_bar1Pos;
    int             m_bar2Pos;
};

#endif // CONFIGURATOR_H
