#ifndef READANALOGF64_H
#define READANALOGF64_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class ReadAnalogF64 : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(FillMode)

    Q_PROPERTY(qint32           numSampsPerChan       READ numSampsPerChan      WRITE setNumSampsPerChan      NOTIFY numSampsPerChanChanged)
    Q_PROPERTY(qreal            timeout               READ timeout              WRITE setTimeout              NOTIFY timeoutChanged)
    Q_PROPERTY(FillMode         fillMode              READ fillMode             WRITE setFillMode             NOTIFY fillModeChanged)

public:
    explicit ReadAnalogF64(QQuickItem *parent = 0);

    //        enum FillMode {GroupByChannel = 0, GroupByScanNumber = 1};
    enum FillMode {GroupByChannel = DAQmx_Val_GroupByChannel, GroupByScanNumber = DAQmx_Val_GroupByScanNumber};

    qint32 numSampsPerChan();   void setNumSampsPerChan(const qint32 &rn);
    qreal timeout();            void setTimeout(const qreal &rn);
    FillMode fillMode();        void setFillMode(const FillMode &rn);

signals:

    void numSampsPerChanChanged();
    void timeoutChanged();
    void fillModeChanged();

public slots:

private:
    qint32          _numSampsPerChan;
    qreal           _timeout;
    FillMode        _fillMode;

};

#endif // READANALOGF64_H
