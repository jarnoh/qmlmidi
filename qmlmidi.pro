# QML Midi plugin
# jarnoh@komplex.org
# Copyright (c) 2011 Jarno Heikkinen
#

TEMPLATE = lib
TARGET = qmlmidi
QT += declarative
CONFIG += qt plugin

DESTDIR = $$PWD/org/komplex/qmlmidi

INCLUDEPATH += rtmidi-1.0.15

# Input
SOURCES += \
    qmlmidi_plugin.cpp \
    rtmidi-1.0.15/RtMidi.cpp \
    qmlmidiin.cpp \
    qmlmidiout.cpp

HEADERS += \
    qmlmidi_plugin.h \
    rtmidi-1.0.15/RtMidi.h \
    rtmidi-1.0.15/RtError.h \
    qmlmidiin.h \
    qmlmidiout.h \
    qmlmidi.h

OTHER_FILES = $$DESTDIR/qmldir \
    piano.qml

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir

windows:DEFINES += __WINDOWS_MM__
windows:LIBS += -lWINMM

macx:DEFINES += __MACOSX_CORE__
macx:LIBS +=  -framework CoreMIDI -framework CoreFoundation -framework CoreAudio

DEFINES += __RTMIDI_DEBUG__
