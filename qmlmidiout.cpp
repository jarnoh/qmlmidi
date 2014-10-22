/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include "qmlmidiout.h"

QmlMidiOut::QmlMidiOut(QQuickItem *parent) :
    QQuickItem(parent), port(-1)
{
}
