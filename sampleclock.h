#ifndef SAMPLECLOCK_H
#define SAMPLECLOCK_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class SampleClock : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(ActiveEdge)
    Q_ENUMS(SampleMode)

    Q_PROPERTY(bool             active                  READ active                 WRITE setActive                 NOTIFY activeChanged)
    Q_PROPERTY(QString          source                  READ source                 WRITE setSource                 NOTIFY sourceChanged)
    Q_PROPERTY(qreal            rate                    READ rate                   WRITE setRate                   NOTIFY rateChanged)
    Q_PROPERTY(ActiveEdge       activeEdge              READ activeEdge             WRITE setActiveEdge             NOTIFY activeEdgeChanged)
    Q_PROPERTY(SampleMode       sampleMode              READ sampleMode             WRITE setSampleMode             NOTIFY sampleModeChanged)
    Q_PROPERTY(quint32          sampsPerChanToAcquire   READ sampsPerChanToAcquire  WRITE setSampsPerChanToAcquire  NOTIFY sampsPerChanToAcquireChanged)

public:
    explicit SampleClock(QQuickItem *parent = 0);

//    enum ActiveEdge {Rising = 10280, Falling = 10171};
//    enum SampleMode {FiniteSamps = 10178, ContSamps = 10123, HWTimedSinglePoint = 12522};
    enum ActiveEdge {Rising = DAQmx_Val_Rising, Falling = DAQmx_Val_Falling};
    enum SampleMode {FiniteSamps = DAQmx_Val_FiniteSamps, ContSamps = DAQmx_Val_ContSamps, HWTimedSinglePoint = DAQmx_Val_HWTimedSinglePoint};

    bool active(); void setActive(const bool &rn);
    QString source(); void setSource(const QString &rn);
    qreal rate(); void setRate(const qreal &rn);
    ActiveEdge activeEdge(); void setActiveEdge(const ActiveEdge &rn);
    SampleMode sampleMode(); void setSampleMode(const SampleMode &rn);
    quint32 sampsPerChanToAcquire(); void setSampsPerChanToAcquire(const quint32 &rn);

signals:
    void activeChanged();
    void sourceChanged();
    void rateChanged();
    void activeEdgeChanged();
    void sampleModeChanged();
    void sampsPerChanToAcquireChanged();

public slots:

private:
    bool            _active;
    QString         _source;
    qreal           _rate;
    ActiveEdge      _activeEdge;
    SampleMode      _sampleMode;
    quint32         _sampsPerChanToAcquire;

};

#endif // SAMPLECLOCK_H
