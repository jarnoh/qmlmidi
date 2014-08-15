import QtQuick 2.3

import org.komplex.qmlmidi 1.0

Rectangle
{
    id:main

    width:640
    height:480

    Column
    {
    Text { text: "Out: "+synth.portName }
    Text { text: "Program: #"+synth.program }
    Text { text: "Use up/down to select midi out port, left/right to select program" }
    Text { text: "Use qwerty to play" }
    }

    MidiOut
    {
        id:synth
        port:0

        property int program: 0

        onPortChanged: {
            program=0;
        }

        onProgramChanged: {
            sendMessage(0xc0, program, 0);
        }
    }


    Item {
        id:piano
        anchors.fill: parent
        focus: true

        function key2note(keycode)
        {
            var ch=String.fromCharCode(keycode);
            var n = "Q2W3ER5T6Y7UI9O0P".indexOf(ch);
            if(n==-1) return -1;
            return n+60;
        }

        Keys.onPressed:
        {
            if(event.isAutoRepeat) return;
            var k=key2note(event.key);
            synth.sendMessage(0x90, k, 100);
        }
        Keys.onReleased:
        {
            var k=key2note(event.key);
            synth.sendMessage(0x80, k, 0);
        }

        Keys.onUpPressed:
        {
            if(synth.port+1<synth.portCount)
            {
                synth.port++;
            }
        }

        Keys.onDownPressed:
        {
            if(synth.port>0)
            {
                synth.port--;
            }
        }

        Keys.onLeftPressed:
        {
            synth.program--;
        }

        Keys.onRightPressed:
        {
            synth.program++;
        }

    }

}
