/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include "qmlmidiin.h"

QmlMidiIn::QmlMidiIn(QDeclarativeItem *parent) :
    QDeclarativeItem(parent), port(-1)
{
}
