#ifndef QMLMIDIIN_H
#define QMLMIDIIN_H

/** QML Midi plugin
  * jarnoh@komplex.org
  * Copyright (c) 2011 Jarno Heikkinen
  */

#include "qmlmidi.h"

class QmlMidiIn : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int portCount READ getPortCount)
    Q_PROPERTY(int port READ getPort WRITE setPort)
    Q_PROPERTY(QString portName READ getPortName WRITE setPortByName)
    Q_PROPERTY(QList<QVariant> portNames READ getPortNames)
    Q_PROPERTY(bool active READ getActive WRITE setActive)

public:
    explicit QmlMidiIn(QQuickItem *parent = 0);

private:
    RtMidiIn midiIn;
    bool active;
    int port;

public:
    int getPortCount()
    {
        DEBUG("getPortCount %d",midiIn.getPortCount());
        return midiIn.getPortCount();
    }

    bool openPort(int portNumber, QString portname=QString("QmlmidiIn"))
    {
        DEBUG("openPort %d", portNumber);
        try
        {
            midiIn.openPort(portNumber, portname.toStdString());
            // midiIn.ignoreTypes(false,false,false);
            return true;
        }
        catch(RtMidiError e)
        {
            DEBUG("Exception %s", e.what());
            return false;
        }
    }

    bool getActive()
    {
        return active;
    }

    void setActive(bool active)
    {
        DEBUG("setActive %d", active);
        this->active=active;
        if(active)
        {
            midiIn.setCallback(callback_emitter, this);
        }
        else
        {
            midiIn.cancelCallback();
        }
    }

    int getPort()
    {
        return port;
    }

    void setPort(int port)
    {
        if(this->port>=0) closePort();
        this->port=port;
        if(!openPort(port)) port=-1;
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

    QString getPortName()
    {
        return getPortName(port);
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

    Q_INVOKABLE void openVirtualPort(QString portname)
    {
        DEBUG("openVirtualPort ");
        midiIn.openVirtualPort(portname.toStdString());
    }

    Q_INVOKABLE void closePort()
    {
        DEBUG("closePort");
        midiIn.closePort();
        port=-1;
    }

    Q_INVOKABLE QString getPortName(int index)
    {
        DEBUG("getPortName %d", index);
        return QString::fromStdString(midiIn.getPortName(index));
    }

    Q_INVOKABLE void ignoreTypes( bool midiSysex = true, bool midiTime = true, bool midiSense = true )
    {
        midiIn.ignoreTypes(midiSysex, midiTime, midiSense);
    }

    Q_INVOKABLE QVariant getMessage()
    {
        std::vector<unsigned char> msg;
        qreal timeStamp = midiIn.getMessage(&msg);

        QList<QVariant> m;
        m.append(timeStamp);
        for(int i=0;i<msg.size();i++) m.append((quint8)msg.at(i));
        return QVariant(m);
    }

    static void callback_emitter(double timeStamp, std::vector<unsigned char> *msg, void *userData)
    {
        ((QmlMidiIn*)userData)->emitMidiMessage(timeStamp, msg);
    }

signals:
    void data(QVariant data);

public slots:
    void emitMidiMessage(double timeStamp, std::vector<unsigned char> *msg)
    {
        QList<QVariant> m;
        m.append((qreal)timeStamp);
        for(int i=0;i<msg->size();i++) m.append((quint8)msg->at(i));
        emit data(QVariant(m));
    }

};

QML_DECLARE_TYPE(QmlMidiIn)

#endif // QMLMIDIIN_H
