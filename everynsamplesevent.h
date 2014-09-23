#ifndef EVERYNSAMPLESEVENT_H
#define EVERYNSAMPLESEVENT_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class EveryNSamplesEvent : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(EventType)

    Q_PROPERTY(EventType        eventType        READ eventType       WRITE setEventType       NOTIFY eventTypeChanged)
    Q_PROPERTY(quint32          numSamples       READ numSamples      WRITE setNumSamples      NOTIFY numSamplesChanged)

public:
    explicit EveryNSamplesEvent(QQuickItem *parent = 0);

//    enum EventType {AcquiredIntoBuffer = 1, TransferredFromBuffer = 2};
    enum EventType {AcquiredIntoBuffer = DAQmx_Val_Acquired_Into_Buffer, TransferredFromBuffer = DAQmx_Val_Transferred_From_Buffer};

    EventType eventType();  void setEventType(const EventType &rn);
    quint32 numSamples();   void setNumSamples(const quint32 &rn);

signals:
    void eventTypeChanged();
    void numSamplesChanged();

public slots:

private:
    EventType       _eventType;
    quint32         _numSamples;

};

#endif // EVERYNSAMPLESEVENT_H
