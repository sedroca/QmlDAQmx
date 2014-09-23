#ifndef ANLGEDGESTARTTRIG_H
#define ANLGEDGESTARTTRIG_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class AnlgEdgeStartTrig : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(TriggerSlope)

    Q_PROPERTY(bool             active            READ active           WRITE setActive           NOTIFY activeChanged)
    Q_PROPERTY(QString          triggerSource     READ triggerSource    WRITE setTriggerSource    NOTIFY triggerSourceChanged)
    Q_PROPERTY(TriggerSlope     triggerSlope      READ triggerSlope     WRITE setTriggerSlope     NOTIFY triggerSlopeChanged)
    Q_PROPERTY(qreal            triggerLevel      READ triggerLevel     WRITE setTriggerLevel     NOTIFY triggerLevelChanged)

public:
    explicit AnlgEdgeStartTrig(QQuickItem *parent = 0);

    //    enum TriggerSlope {RisingSlope = 10280, FallingSlope = 10171};
    enum TriggerSlope {RisingSlope = DAQmx_Val_RisingSlope, FallingSlope = DAQmx_Val_FallingSlope};

    bool active();                  void setActive(const bool &rn);
    QString triggerSource();        void setTriggerSource(const QString &rn);
    TriggerSlope triggerSlope();    void setTriggerSlope(const TriggerSlope &rn);
    qreal triggerLevel();           void setTriggerLevel(const qreal &rn);

signals:

    void activeChanged();
    void triggerSourceChanged();
    void triggerSlopeChanged();
    void triggerLevelChanged();

public slots:

private:
    bool            _active;
    QString         _triggerSource;
    TriggerSlope    _triggerSlope;
    qreal           _triggerLevel;

};

#endif // ANLGEDGESTARTTRIG_H
