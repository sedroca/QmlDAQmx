#ifndef ANLGEDGEREFTRIG_H
#define ANLGEDGEREFTRIG_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class AnlgEdgeRefTrig : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(TriggerSlope)

    Q_PROPERTY(bool             active              READ active             WRITE setActive             NOTIFY activeChanged)
    Q_PROPERTY(QString          triggerSource       READ triggerSource      WRITE setTriggerSource      NOTIFY triggerSourceChanged)
    Q_PROPERTY(TriggerSlope     triggerSlope        READ triggerSlope       WRITE setTriggerSlope       NOTIFY triggerSlopeChanged)
    Q_PROPERTY(qreal            triggerLevel        READ triggerLevel       WRITE setTriggerLevel       NOTIFY triggerLevelChanged)
    Q_PROPERTY(quint32          pretriggerSamples   READ pretriggerSamples  WRITE setPretriggerSamples  NOTIFY pretriggerSamplesChanged)

public:
    explicit AnlgEdgeRefTrig(QQuickItem *parent = 0);

    //    enum TriggerSlope {RisingSlope = 10280, FallingSlope = 10171};
    enum TriggerSlope {RisingSlope = DAQmx_Val_RisingSlope, FallingSlope = DAQmx_Val_FallingSlope};

    bool active();              void setActive(const bool &rn);
    QString triggerSource();    void setTriggerSource(const QString &rn);
    TriggerSlope triggerSlope();void setTriggerSlope(const TriggerSlope &rn);
    qreal triggerLevel();       void setTriggerLevel(const qreal &rn);
    quint32 pretriggerSamples();void setPretriggerSamples(const quint32 &rn);

signals:
    void activeChanged();
    void triggerSourceChanged();
    void triggerSlopeChanged();
    void triggerLevelChanged();
    void pretriggerSamplesChanged();

public slots:

private:

    bool            _active;
    QString         _triggerSource;
    TriggerSlope    _triggerSlope;
    qreal           _triggerLevel;
    quint32         _pretriggerSamples;

};

#endif // ANLGEDGEREFTRIG_H
