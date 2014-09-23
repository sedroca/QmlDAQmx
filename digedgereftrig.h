#ifndef DIGEDGEREFTRIG_H
#define DIGEDGEREFTRIG_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class DigEdgeRefTrig : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(ActiveEdge)

    Q_PROPERTY(bool             active               READ active              WRITE setActive              NOTIFY activeChanged)
    Q_PROPERTY(QString          triggerSource        READ triggerSource       WRITE setTriggerSource       NOTIFY triggerSourceChanged)
    Q_PROPERTY(ActiveEdge       triggerEdge          READ triggerEdge         WRITE setTriggerEdge         NOTIFY triggerEdgeChanged)
    Q_PROPERTY(quint32          pretriggerSamples    READ pretriggerSamples   WRITE setPretriggerSamples   NOTIFY pretriggerSamplesChanged)

public:
    explicit DigEdgeRefTrig(QQuickItem *parent = 0);

//    enum ActiveEdge {Rising = 10280, Falling = 10171};
    enum ActiveEdge {Rising = DAQmx_Val_Rising, Falling = DAQmx_Val_Falling};

    bool active();              void setActive(const bool &rn);
    QString triggerSource();    void setTriggerSource(const QString &rn);
    ActiveEdge triggerEdge();   void setTriggerEdge(const ActiveEdge &rn);
    quint32 pretriggerSamples();void setPretriggerSamples(const quint32 &rn);

signals:
    void activeChanged();
    void triggerSourceChanged();
    void triggerEdgeChanged();
    void pretriggerSamplesChanged();

public slots:

private:
    bool            _active;
    QString         _triggerSource;
    ActiveEdge      _triggerEdge;
    quint32         _pretriggerSamples;

};

#endif // DIGEDGEREFTRIG_H
