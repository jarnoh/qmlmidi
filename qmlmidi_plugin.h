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

public:
    void registerTypes(const char *uri);
};

#endif // QMLMIDI_PLUGIN_H

