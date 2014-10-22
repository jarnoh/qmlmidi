#ifndef QMLMIDI_PLUGIN_H
#define QMLMIDI_PLUGIN_H

/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include <QtQml/QQmlExtensionPlugin>

class QmlMidiPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri);
};

#endif // QMLMIDI_PLUGIN_H
