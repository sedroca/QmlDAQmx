#ifndef QMLDAQMX_PLUGIN_H
#define QMLDAQMX_PLUGIN_H

#include <QQmlExtensionPlugin>

class QmlDAQmxPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QMLDAQMX_PLUGIN_H

