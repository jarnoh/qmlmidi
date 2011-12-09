/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include "qmlmidi_plugin.h"
#include "qmlmidiin.h"
#include "qmlmidiout.h"
#include <QtDeclarative/qdeclarative.h>

void QmlMidiPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<QmlMidiIn>("org.komplex.qmlmidi", 1, 0, "MidiIn");
    qmlRegisterType<QmlMidiOut>("org.komplex.qmlmidi", 1, 0, "MidiOut");
}

Q_EXPORT_PLUGIN2(QmlMidi, QmlMidiPlugin)

