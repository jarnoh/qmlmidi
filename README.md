qmlmidi
-------

QML extension plugin enabling access to MIDI in/out devices, based on RtMidi library.  Tested on Windows and OS X platforms.

Instructions
------------

Compile plugin, then use in any QML application or QML viewer.

Requirements
------------

Qt5

Example
-------
See piano.qml.

If you are using QMLViewer, please start with "qmlviewer -I . piano.qml" so that the current (project) directory is included in module search path.

 * Up/down arrows to change MIDI output device 
 * Left/right arrow to change program (instrument)
 * qwerty (protracker) keys play notes.


Legal
-----

**qmlmidi** is available under MIT License.

Copyright (c) 2011 Jarno Heikkinen <jarnoh@komplex.org>.

---

The RtMidi license is similar to the the MIT License, with the added "feature" that modifications be sent to the developer.

    RtMidi: realtime MIDI i/o C++ classes
    Copyright (c) 2003-2011 Gary P. Scavone

