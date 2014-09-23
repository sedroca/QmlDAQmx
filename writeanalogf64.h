#ifndef WRITEANALOGF64_H
#define WRITEANALOGF64_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class WriteAnalogF64 : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(FillMode)

    Q_PROPERTY(qint32           numSampsPerChan      READ numSampsPerChan     WRITE setNumSampsPerChan     NOTIFY numSampsPerChanChanged)
    Q_PROPERTY(bool             autoStart            READ autoStart           WRITE setAutoStart           NOTIFY autoStartChanged)
    Q_PROPERTY(qreal            timeout              READ timeout             WRITE setTimeout             NOTIFY timeoutChanged)
    Q_PROPERTY(FillMode         dataLayout           READ dataLayout          WRITE setDataLayout          NOTIFY dataLayoutChanged)

public:
    explicit WriteAnalogF64(QQuickItem *parent = 0);

    //    enum FillMode {GroupByChannel = 0, GroupByScanNumber = 1};
    enum FillMode {GroupByChannel = DAQmx_Val_GroupByChannel, GroupByScanNumber = DAQmx_Val_GroupByScanNumber};

    qint32 numSampsPerChan();   void setNumSampsPerChan(const qint32 &rn);
    bool autoStart();           void setAutoStart(const bool &rn);
    qreal timeout();            void setTimeout(const qreal &rn);
    FillMode dataLayout();      void setDataLayout(const FillMode &rn);


signals:
    void numSampsPerChanChanged();
    void autoStartChanged();
    void timeoutChanged();
    void dataLayoutChanged();


public slots:

private:
    qint32          _numSampsPerChan;
    bool            _autoStart;
    qreal           _timeout;
    FillMode        _dataLayout;



};

#endif // WRITEANALOGF64_H
