/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include "qmlmidiout.h"

QmlMidiOut::QmlMidiOut(QDeclarativeItem *parent) :
    QDeclarativeItem(parent), port(-1)
{
}
