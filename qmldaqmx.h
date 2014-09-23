#ifndef QMLDAQMX_H
#define QMLDAQMX_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QtGlobal>
#include <QQmlListProperty>
#include <QList>

#define _USE_MATH_DEFINES
#include <cmath>

#include "aivoltagechan.h"
#include "sampleclock.h"
#include "digedgestarttrig.h"
#include "everynsamplesevent.h"
#include "readanalogf64.h"
#include "anlgedgestarttrig.h"
#include "digedgereftrig.h"
#include "anlgedgereftrig.h"
#include "aofuncgenchan.h"
#include "aovoltagechan.h"
#include "writeanalogf64.h"
#include "writeanalogscalarf64.h"
#include "starttrigretriggerable.h"

#include <QQuickItem>

int32 CVICALLBACK DoneCallback (TaskHandle taskHandle, int32 status, void *callbackData);
int32 CVICALLBACK EveryNSamplesEventCallback (TaskHandle taskHandle, int32 eventType, uInt32 numSamples, void *callbackData);

class QmlDAQmx : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(QmlDAQmx)

    friend int32 CVICALLBACK DoneCallback (TaskHandle taskHandle, int32 status, void *callbackData);
    friend int32 CVICALLBACK EveryNSamplesEventCallback (TaskHandle taskHandle, int32 eventType, uInt32 numSamples, void *callbackData);

    //    Q_ENUMS(TerminalConfig)
    //    Q_ENUMS(Units)
    //    Q_ENUMS(ActiveEdge)
    //    Q_ENUMS(SampleMode)
    //    Q_ENUMS(EventType)
    //    Q_ENUMS(FillMode)
    //    Q_ENUMS(TriggerSlope)
    //    Q_ENUMS(FuncGenType)

    Q_PROPERTY(AIVoltageChan*           aiVoltageChan           READ aiVoltageChan )
    Q_PROPERTY(SampleClock*             sampleClock             READ sampleClock )
    Q_PROPERTY(DigEdgeStartTrig*        digEdgeStartTrig        READ digEdgeStartTrig )
    Q_PROPERTY(EveryNSamplesEvent*      everyNSamplesEvent      READ everyNSamplesEvent )
    Q_PROPERTY(ReadAnalogF64*           readAnalogF64           READ readAnalogF64 )
    Q_PROPERTY(AnlgEdgeStartTrig*       anlgEdgeStartTrig       READ anlgEdgeStartTrig )
    Q_PROPERTY(DigEdgeRefTrig*          digEdgeRefTrig          READ digEdgeRefTrig )
    Q_PROPERTY(AnlgEdgeRefTrig*         anlgEdgeRefTrig         READ anlgEdgeRefTrig )
    Q_PROPERTY(StartTrigRetriggerable*  startTrigRetriggerable  READ startTrigRetriggerable )
    Q_PROPERTY(AOFuncGenChan*           aoFuncGenChan           READ aoFuncGenChan )
    Q_PROPERTY(AOVoltageChan*           aoVoltageChan           READ aoVoltageChan )
    Q_PROPERTY(WriteAnalogF64*          writeAnalogF64          READ writeAnalogF64 )
    Q_PROPERTY(WriteAnalogScalarF64*    writeAnalogScalarF64    READ writeAnalogScalarF64)


    Q_PROPERTY(QString          statusMsg           READ statusMsg                                      NOTIFY statusMsgChanged)
    Q_PROPERTY(QStringList      readStringList      READ readStringList                                 NOTIFY readStringListChanged)
    Q_PROPERTY(QList<qreal>     dataList            READ dataList                                       NOTIFY dataListChanged)
    Q_PROPERTY(QStringList      writeStringList     READ writeStringList    WRITE setWriteStringList    NOTIFY writeStringListChanged)
    Q_PROPERTY(quint32          numRead             READ numRead                                        NOTIFY numReadChanged)
    Q_PROPERTY(qint32           numWritten          READ numWritten                                     NOTIFY numWrittenChanged)
    Q_PROPERTY(qreal            max                 READ max                                            NOTIFY maxChanged)
    Q_PROPERTY(qreal            min                 READ min                                            NOTIFY minChanged)


public:
    QmlDAQmx(QQuickItem *parent = 0);
    ~QmlDAQmx();

    //    enum TerminalConfig {Default = -1, RSE = 10083, NRSE = 10078, Diff = 10106, PseudoDiff = 12529 };
    //    enum Units {Volts = 10348, FromCustomScale = 10065, FromTeds = 12516};
    //    enum ActiveEdge {Rising = 10280, Falling = 10171};
    //    enum SampleMode {FiniteSamps = 10178, ContSamps = 10123, HWTimedSinglePoint = 12522};
    //    enum EventType {AcquiredIntoBuffer = 1, TransferredFromBuffer = 2};
    //    enum FillMode {GroupByChannel = 0, GroupByScanNumber = 1};
    //    enum TriggerSlope {RisingSlope = 10280, FallingSlope = 10171};
    //    enum FuncGenType {Sine = 14751, Triangle = 14752, Square = 14753, Sawtooth = 14754};

    Q_INVOKABLE void configureAiVoltageTask();
    Q_INVOKABLE void initializeFuncGenTask();
    Q_INVOKABLE void configureAoVoltageTask();
    Q_INVOKABLE void createTask();
    Q_INVOKABLE void startTask();
    Q_INVOKABLE void stopTask();
    Q_INVOKABLE void clearTask();
    Q_INVOKABLE QList<qreal> getDataList();
    Q_INVOKABLE QList<qreal> getData();

    Q_INVOKABLE void setDataOut(const QList<qreal> &rn);
    Q_INVOKABLE void writeAnalogOut1Pt(const qreal &rn);
    Q_INVOKABLE void writeAnalogOutArray(const QList<qreal> &rn);
    Q_INVOKABLE void writeAnalogOut();

    AIVoltageChan* aiVoltageChan();
    SampleClock* sampleClock();
    DigEdgeStartTrig* digEdgeStartTrig();
    EveryNSamplesEvent* everyNSamplesEvent();
    ReadAnalogF64* readAnalogF64();
    AnlgEdgeStartTrig* anlgEdgeStartTrig();
    DigEdgeRefTrig* digEdgeRefTrig();
    AnlgEdgeRefTrig* anlgEdgeRefTrig();
    StartTrigRetriggerable* startTrigRetriggerable();
    AOFuncGenChan* aoFuncGenChan();
    AOVoltageChan* aoVoltageChan();
    WriteAnalogF64* writeAnalogF64();
    WriteAnalogScalarF64* writeAnalogScalarF64();

    QString statusMsg();
    // Read only

    QStringList readStringList();
    // Read only
    QList<qreal> dataList();
    // Read only


    QStringList writeStringList();
    void setWriteStringList(const QStringList &rn);

    quint32 numRead();
    qint32 numWritten();
    qreal max();
    qreal min();

signals:
    void statusMsgChanged();
    void readStringListChanged();
    void writeStringListChanged();
    void numReadChanged();
    void numWrittenChanged();
    void maxChanged();
    void minChanged();

    void dataListChanged();
    void newData();

//slots:
//    void updateData();


private:

    TaskHandle              _taskHandle;

    AIVoltageChan           _aiVoltageChan;
    SampleClock             _sampleClock;
    DigEdgeStartTrig        _digEdgeStartTrig;
    EveryNSamplesEvent      _everyNSamplesEvent;
    ReadAnalogF64           _readAnalogF64;
    AnlgEdgeStartTrig       _anlgEdgeStartTrig;
    DigEdgeRefTrig          _digEdgeRefTrig;
    AnlgEdgeRefTrig         _anlgEdgeRefTrig;
    AOFuncGenChan           _aoFuncGenChan;
    AOVoltageChan           _aoVoltageChan;
    WriteAnalogF64          _writeAnalogF64;
    WriteAnalogScalarF64    _writeAnalogScalarF64;
    StartTrigRetriggerable  _startTrigRetriggerable;

    //    bool            _startTrigRetriggerable_Active;

    QString         _statusMsg;
    QStringList     _readStringList;
    QStringList     _writeStringList;
    QList<qreal>    _qRealDataList;

    qreal*          _data;
    quint32         _dataSize;
    QList<qreal>    _dataList;

    qreal*          _dataOut;
    quint32         _dataOutSize;
    QList<qreal>    _dataOutList;

    quint32         _numRead;
    qint32          _numWritten;
    qreal           _max;
    qreal           _min;
};

#endif // QMLDAQMX_H












