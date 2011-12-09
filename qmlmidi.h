#ifndef QMLMIDI_H
#define QMLMIDI_H

/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include <QDeclarativeItem>
#include "RtMidi.h"

#ifdef __RTMIDI_DEBUG__ // debug output flag shared with rtmidi
#define DEBUG(s...) qDebug(__FILE__ " " s)
#else
#define DEBUG(s...) while(0)
#endif

#endif // QMLMIDI_H
