#ifndef QMLMIDI_PLUGIN_H
#define QMLMIDI_PLUGIN_H

/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include <QtDeclarative/QDeclarativeExtensionPlugin>

class QmlMidiPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
#endif

public:
    void registerTypes(const char *uri);
};

#endif // QMLMIDI_PLUGIN_H

