#ifndef QMLMIDIOUT_H
#define QMLMIDIOUT_H

/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include "qmlmidi.h"

class QmlMidiOut : public QDeclarativeItem
{
    Q_OBJECT

    Q_PROPERTY(int portCount READ getPortCount)
    Q_PROPERTY(int port READ getPort WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(QString portName READ portName WRITE setPortByName NOTIFY portChanged)
    Q_PROPERTY(QList<QVariant> portNames READ getPortNames)

public:
    explicit QmlMidiOut(QDeclarativeItem *parent = 0);

signals:
    void portChanged();
    void portNameChanged();

public slots:

private:
    int port;


public:
    int getPort()
    {
        return port;
    }

    void setPort(int port)
    {
        DEBUG("setPort %d", port);
        if(this->port!=port)
        {
            if(this->port>=0) closePort();
            if(port==-1 || !openPort(port))
                this->port=-1;
            else
                this->port=port;
            DEBUG("emit portChanged");
            emit portChanged();
        }
    }

    QList<QVariant> getPortNames()
    {
        QList<QVariant> l;
        for(int i=0;i<getPortCount();i++)
        {
            l.append(QVariant(getPortName(i)));
        }
        return l;
    }

    QString portName()
    {
        DEBUG("portName (%d)", port);
        if(port==-1) return QString("(none)");
        return getPortName(port);
    }

    Q_INVOKABLE int getPortCount()
    {
        DEBUG("getPortCount");
        return midiOut.getPortCount();
    }

    void setPortByName(QString name)
    {
        for(int i=0;i<getPortCount();i++)
        {
            if(getPortName(i)==name)
            {
                setPort(i);
                return;
            }
        }
    }


    Q_INVOKABLE bool openPort(int portNumber, QString portname=QString("QmlMidiOut"))
    {
        DEBUG("openPort %d", portNumber);
        try
        {
            midiOut.openPort(portNumber, portname.toStdString());
            return true;
        }
        catch(RtError e)
        {
            DEBUG("Exception %s", e.what());
            return false;
        }
    }

    Q_INVOKABLE void openVirtualPort(QString portname)
    {
        DEBUG("openVirtualPort ");
        midiOut.openVirtualPort(portname.toStdString());
    }

    Q_INVOKABLE void closePort()
    {
        DEBUG("closePort");
        midiOut.closePort();
    }

    Q_INVOKABLE QString getPortName(int index)
    {
        DEBUG("getPortName %d", index);
        return QString::fromStdString(midiOut.getPortName(index));
    }

    Q_INVOKABLE bool sendMessage(int a, int b, int c)
    {
        DEBUG("sendMessage %d %d %d", a,b,c);
        std::vector<unsigned char> m;
        m.push_back(a);
        m.push_back(b);
        m.push_back(c);

        try
        {
            midiOut.sendMessage(&m);
            return true;
        }
        catch(RtError e)
        {
            DEBUG("Exception %s", e.what());
            return false;
        }

    }

protected:
    RtMidiOut midiOut;

};

QML_DECLARE_TYPE(QmlMidiOut)

#endif // QMLMIDIOUT_H
