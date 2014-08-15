/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include "qmlmidiin.h"

QmlMidiIn::QmlMidiIn(QQuickItem *parent) :
    QQuickItem(parent), port(-1)
{
}
