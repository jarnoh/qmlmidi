#ifndef QMLMIDI_H
#define QMLMIDI_H

/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */


#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickItem>
#include "RtMidi.h"

#ifdef __RTMIDI_DEBUG__ // debug output flag shared with rtmidi
#define DEBUG(...) qDebug(__FILE__ " " __VA_ARGS__)
#else
#define DEBUG(...) while(0)
#endif

#endif // QMLMIDI_H
