#include "qmldaqmx.h"
//#include "aivoltagechan.h"

const qreal Pi = 3.1415926535897932384626433832795028841971693993751;

int32 DAQmxGetErrorString (int32 errorCode, char errorString[], uInt32 bufferSize);
int32 DAQmxGetExtendedErrorInfo (char errorString[], uInt32 bufferSize);

QmlDAQmx::QmlDAQmx(QQuickItem *parent):
    QQuickItem(parent)
{
    //    int32 status;
    //    status = DAQmxCreateTask ("",&_taskHandle);
    //    QObject::connect(this,QmlDAQmx::newData(),this,QmlDAQmx::updateData());
}

QmlDAQmx::~QmlDAQmx()
{
    int32 status;
    status = DAQmxStopTask (_taskHandle);
    status = DAQmxRegisterDoneEvent (_taskHandle, 0, NULL, NULL);
    status = DAQmxRegisterEveryNSamplesEvent (_taskHandle, NULL, NULL, 0, NULL, NULL);

    status = DAQmxClearTask (_taskHandle);

}

void QmlDAQmx::configureAiVoltageTask()
{
    int32 status;
    char errorString[1024];
    uInt32 chanCount;
    //    uInt32 bufSize;
    uInt32 autoBufSize;
    uInt32 goodBufSize;

    qDebug() << "Initialize Task";

    //char physChannel[256];
    //strcpy(physChannel, physicalChannel.toLatin1().data());
    qDebug() << "About to create channel:" << _aiVoltageChan.physicalChannel().toLatin1().data();

    status = DAQmxCreateAIVoltageChan (_taskHandle, _aiVoltageChan.physicalChannel().toLatin1().data(), "", _aiVoltageChan.terminalConfig(), _aiVoltageChan.minVal(), _aiVoltageChan.maxVal(), _aiVoltageChan.units(), NULL);
    qDebug() << "Ai Voltage channel created. Handle " << _taskHandle <<  "Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}

    status = DAQmxCfgSampClkTiming (_taskHandle, _sampleClock.source().toLatin1().data(), _sampleClock.rate(), _sampleClock.activeEdge(), _sampleClock.sampleMode(), _sampleClock.sampsPerChanToAcquire());
    qDebug() << "Ai Sample clock configured.  Source " << _sampleClock.source().toLatin1().data() << "Rate " <<_sampleClock.rate() << "Edge " << _sampleClock.activeEdge() << "SampleMode " << _sampleClock.sampleMode() << "Count " << _sampleClock.sampsPerChanToAcquire();
    qDebug() <<"Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}


    if (true == _digEdgeStartTrig.active()) {
        status = DAQmxCfgDigEdgeStartTrig (_taskHandle, _digEdgeStartTrig.triggerSource().toLatin1().data(), _digEdgeStartTrig.triggerEdge());
        qDebug() << "Digital start trigger configured.  Status " << status;
        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    }
    else if (true == _anlgEdgeStartTrig.active()) {
        status = DAQmxCfgAnlgEdgeStartTrig (_taskHandle, _anlgEdgeStartTrig.triggerSource().toLatin1().data(), _anlgEdgeStartTrig.triggerSlope(), _anlgEdgeStartTrig.triggerLevel());
        qDebug() << "Analog edge start trigger configured.  Status " << status;
        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    }
    else {
        status = DAQmxDisableStartTrig (_taskHandle);
        qDebug() << "Start trigger disabled.  Status " << status;
        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    }

    if (true == _digEdgeRefTrig.active()) {
        status = DAQmxCfgDigEdgeRefTrig (_taskHandle, _digEdgeRefTrig.triggerSource().toLatin1().data(), _digEdgeRefTrig.triggerEdge(), _digEdgeRefTrig.pretriggerSamples());
        qDebug() << "Digital ref trigger configured.  Status " << status;
        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    }
    else if (true == _anlgEdgeRefTrig.active()) {
        status = DAQmxCfgAnlgEdgeRefTrig (_taskHandle, _anlgEdgeRefTrig.triggerSource().toLatin1().data(), _anlgEdgeRefTrig.triggerSlope(), _anlgEdgeRefTrig.triggerLevel(), _anlgEdgeRefTrig.pretriggerSamples());
        qDebug() << "Analog edge ref trigger configured.  Status " << status;
        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    }
    else {
        status = DAQmxDisableRefTrig (_taskHandle);
        qDebug() << "Ref trigger disabled.  Status " << status;
        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    }

    if (true == _startTrigRetriggerable.active()) {
        status = DAQmxSetStartTrigRetriggerable(_taskHandle, 1);
    }
    else {
        status = DAQmxResetStartTrigRetriggerable(_taskHandle);
    }

    // Set buffers
    // Leaves the _data[] set to a reasonable size.

    status = DAQmxGetTaskNumChans(_taskHandle, &chanCount);
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}

    _dataSize = _readAnalogF64.numSampsPerChan() * chanCount;
    _data = new (std::nothrow) float64[_dataSize];
    if (_data == nullptr) {
        qDebug() << "Error: memory could not be allocated." << _dataSize << "not allocated" << endl;
    }

    status = DAQmxGetBufInputBufSize(_taskHandle, &autoBufSize);
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    goodBufSize = _everyNSamplesEvent.numSamples() * 5;

    if (goodBufSize > autoBufSize) {
        status = DAQmxSetBufInputBufSize(_taskHandle, goodBufSize);
        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    }

    status = DAQmxRegisterEveryNSamplesEvent (_taskHandle, _everyNSamplesEvent.eventType(), _everyNSamplesEvent.numSamples(), 0, &EveryNSamplesEventCallback, this);
    qDebug() << "Every N-sample event registered.  Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}

    status = DAQmxRegisterDoneEvent (_taskHandle, 0, &DoneCallback, this);
    qDebug() << "Done event registered.  Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}

}

//     enum FuncGenType {Sine = 14751, Triangle = 14752, Square = 14753, Sawtooth = 14754};
void QmlDAQmx::initializeFuncGenTask()
{

    qreal *data;
    quint32 numSampsInPeriod;
    qreal actualFrequency;
    quint32 i;
    //    data = new (std::nothrow) float64[_AnalogF64_NumSampsPerChan];

    // adds 1.5.  1 as necessary to end up back on the same value and 0.5 for nearest integer
    numSampsInPeriod = quint32(1.5 + _sampleClock.rate() / _aoFuncGenChan.frequency());
    qDebug() << "Sample clock rate: " << _sampleClock.rate() << " FuncGen Frequency: " << _aoFuncGenChan.frequency() << " numSampsInPeriod: " << numSampsInPeriod;
    actualFrequency = _sampleClock.rate() / ((qreal) numSampsInPeriod -1);
    qDebug() << "Actual frequency: " << actualFrequency << "numSampsInPeriod: " << numSampsInPeriod;

    data = new (std::nothrow) float64[numSampsInPeriod];
    if (data == nullptr) {
        qDebug() << "Error: memory could not be allocated." << numSampsInPeriod << " floatF64 not allocated";
        delete[] data;
    }
    else {

        //    status = DAQmxCreateAOFuncGenChan (_taskHandle, _aoFuncGenChan_PhysicalChannel.toLatin1().data(), "", _aoFuncGenChan_Type, _aoFuncGenChan_Frequency, _aoFuncGenChan_Amplitude, _aoFuncGenChan_Offset);

        switch (_aoFuncGenChan.type()) {
        case AOFuncGenChan::Sine:
            for (i=0;i<numSampsInPeriod;i++) {
                //            data[i] = _aoFuncGenChan_Offset + _aoFuncGenChan_Amplitude * sin((qreal) i * 2.0 * M_PI / (_sampleClock_Rate));
                data[i] = _aoFuncGenChan.offset() + _aoFuncGenChan.amplitude() * sin((qreal) i * 2.0 * Pi / (_sampleClock.rate()));
            }
            _readStringList.clear();
            for (i=0; i<numSampsInPeriod; i++) {
                _writeStringList.append(QString("%1").arg(data[i],0,'E',6));
            }
            emit writeStringListChanged();
            qDebug() << "Sine wave";
            break;
        case AOFuncGenChan::Triangle:
            qDebug() << "Triangle wave";
            break;
        case AOFuncGenChan::Square:
            qDebug() << "Square wave";
            break;
        case AOFuncGenChan::Sawtooth:
            qDebug() << "Sawtooth";
            break;
        default:
            break;

        }
        qDebug() << "AO Function Generator waveform created.";
        delete[] data;
    }
}

void QmlDAQmx::configureAoVoltageTask()
{

    int32 status;
    char errorString[1024];
    quint32 i;
    float64 *p;
    quint32 numSamples;

    status = DAQmxCreateAOVoltageChan (_taskHandle, _aoVoltageChan.physicalChannel().toLatin1().data(), "", _aoVoltageChan.minVal(), _aoVoltageChan.maxVal(), _aoVoltageChan.units(), "");
    qDebug() << "AO Voltage Channel created.  Handle " << _taskHandle << "Status " << status;
    if (status < 0) { DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}

    if (true == _sampleClock.active()) {
        status = DAQmxCfgSampClkTiming (_taskHandle, _sampleClock.source().toLatin1().data(), _sampleClock.rate(), _sampleClock.activeEdge(), _sampleClock.sampleMode(), _sampleClock.sampsPerChanToAcquire());
        qDebug() << "Analog out Sample clock configured.  Source " << _sampleClock.source().toLatin1().data() << "Rate " <<_sampleClock.rate() << "Edge " << _sampleClock.activeEdge()<< "SampleMode " << _sampleClock.sampleMode()<< "Count " << _sampleClock.sampsPerChanToAcquire();
        qDebug() <<"Status " << status;
        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    }

    if (true == _digEdgeStartTrig.active()) {
        status = DAQmxCfgDigEdgeStartTrig (_taskHandle, _digEdgeStartTrig.triggerSource().toLatin1().data(), _digEdgeStartTrig.triggerEdge());
        qDebug() << "Digital start trigger configured.  Status " << status;
    }
    else {
        status = DAQmxDisableStartTrig (_taskHandle);
        qDebug() << "Start trigger disabled.  Status " << status;
    }
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}

    if (true == _startTrigRetriggerable.active()) {
        status = DAQmxSetStartTrigRetriggerable(_taskHandle, 1);
        qDebug() << "Retriggerable enabled" << _startTrigRetriggerable.active() << "with status " << status;
    }
    else {
        status = DAQmxResetStartTrigRetriggerable(_taskHandle);
        qDebug() << "Retriggerable disabled" << _startTrigRetriggerable.active() << "with status" << status;

    }
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}

    //    numSamples = _writeStringList.length();
    //    qDebug() << "NumSamples from writeStringList" << numSamples;

    //    p = new (std::nothrow) float64[numSamples];
    //    if (p == nullptr) {
    //        qDebug() << "Error: memory could not be allocated." << numSamples << "not allocated";
    //        delete[] p;
    //    }
    //    else {
    //        for (i=0; i<numSamples; i++) {
    //            p[i] = _writeStringList.at(i).toDouble();
    //        }
    //        status = DAQmxWriteAnalogF64 (_taskHandle, _writeAnalogF64.numSampsPerChan(), _writeAnalogF64.autoStart(), _writeAnalogF64.timeout(), _writeAnalogF64.dataLayout(), p, NULL, NULL);
    //        qDebug() << "Write analog F64.  Status " << status;
    //        if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    //        delete[] p;
    //    }


    //    status = DAQmxWriteAnalogF64 (_taskHandle, _writeAnalogF64.numSampsPerChan(), _writeAnalogF64.autoStart(), _writeAnalogF64.timeout(), _writeAnalogF64.dataLayout(), _dataOut, NULL, NULL);
    //    qDebug() << "Write analog F64.  Status " << status;
    //    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}

}

void QmlDAQmx::createTask()
{

    int32 status;
    char errorString[1024];

    status = DAQmxCreateTask ("",&_taskHandle);
    qDebug() << "Task created.  Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
}

void QmlDAQmx::startTask()
{

    int32 status;
    char errorString[1024];

    status = DAQmxStartTask (_taskHandle);
    qDebug() << "Task started.  Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
}

void QmlDAQmx::stopTask()
{
    int32 status;
    char errorString[1024];
    status = DAQmxStopTask (_taskHandle);
    qDebug() << "Task stopped.  Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
}

void QmlDAQmx::clearTask()
{
    int32 status;
    char errorString[1024];
    status = DAQmxClearTask (_taskHandle);
    qDebug() << "Task cleared.  Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
}

void QmlDAQmx::writeAnalogOut1Pt(const qreal &rn) {
    int32 status;
    char errorString[1024];
    //    status = DAQmxWriteAnalogF64 (_taskHandle, _writeAnalogF64.numSampsPerChan(), _writeAnalogF64.autoStart(), _writeAnalogF64.timeout(), _writeAnalogF64.dataLayout(), _dataOut, &sampsWritten, NULL);
    qDebug() << "Write analog scalar F64.  Autostart: " << _writeAnalogScalarF64.autoStart() << "timeout: " << _writeAnalogScalarF64.timeout() << "data: " << rn;
    status = DAQmxWriteAnalogScalarF64 (_taskHandle,  _writeAnalogScalarF64.autoStart(), _writeAnalogScalarF64.timeout(), rn, NULL);
    _numWritten = 1;
    emit numWrittenChanged();
    //    qDebug() << "Write analog scalar F64.  Status " << status;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    if (status < 0) {DAQmxGetExtendedErrorInfo (errorString, 1024); qDebug() << errorString;}
}

void QmlDAQmx::writeAnalogOutArray(const QList<qreal> &rn) {
    quint32 i;
    quint32 bufsize;
    qreal* buf;
    int32 status;
    char errorString[1024];

    //quint32 sampsWritten;
    bufsize = rn.length();
    buf = new (std::nothrow) qreal[bufsize];
    if (buf == nullptr) {
        qDebug() << "Error: memory could not be allocated." << bufsize << "not allocated";
    }
    for (i=0; i<bufsize; i++) {
        buf[i] = rn.at(i);
    }
    status = DAQmxWriteAnalogF64 (_taskHandle, _writeAnalogF64.numSampsPerChan(), _writeAnalogF64.autoStart(), _writeAnalogF64.timeout(), _writeAnalogF64.dataLayout(), buf, (int32*)&_numWritten, NULL);
    emit numWrittenChanged();
    qDebug() << "Samps written: " << _numWritten;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    if (status < 0) {DAQmxGetExtendedErrorInfo (errorString, 1024); qDebug() << errorString;}

}

void QmlDAQmx::writeAnalogOut() {
    //quint32 sampsWritten;
    int32 status;
    char errorString[1024];

    status = DAQmxWriteAnalogF64 (_taskHandle, _writeAnalogF64.numSampsPerChan(), _writeAnalogF64.autoStart(), _writeAnalogF64.timeout(), _writeAnalogF64.dataLayout(), _dataOut, (int32*)&_numWritten, NULL);
    emit numWrittenChanged();
    qDebug() << "Samps written: " << _numWritten;
    if (status < 0) {DAQmxGetErrorString (status, errorString, 1024); qDebug() << errorString;}
    if (status < 0) {DAQmxGetExtendedErrorInfo (errorString, 1024); qDebug() << errorString;}

}

void QmlDAQmx::setDataOut(const QList<qreal> &rn) {
    quint32 i;
    quint32 bufsize;

    bufsize = rn.length();
    qDebug() << "bufsize " << bufsize << " data " << rn[0];
    _dataOut = new (std::nothrow) float64[bufsize];
    qDebug() << "dataout" << _dataOut[0];
    if (_dataOut == nullptr) {
        qDebug() << "Error: memory could not be allocated." << bufsize << "not allocated" << endl;
    }
    for (i=0; i<bufsize; i++) {
        _dataOut[i] = rn.at(i);
    }
    qDebug() << "dataOut" << _dataOut[0];
}

// Analog input voltage channel

AIVoltageChan* QmlDAQmx::aiVoltageChan() {return &_aiVoltageChan;}

// Sample clock

SampleClock* QmlDAQmx::sampleClock() {return &_sampleClock;}

// Digital edge start trigger

DigEdgeStartTrig* QmlDAQmx::digEdgeStartTrig() {return &_digEdgeStartTrig;}

// Every N samples event

EveryNSamplesEvent* QmlDAQmx::everyNSamplesEvent() {return &_everyNSamplesEvent;}

// Read analog F64

ReadAnalogF64* QmlDAQmx::readAnalogF64() {return &_readAnalogF64;}

// Analog Edge Start Trigger

AnlgEdgeStartTrig* QmlDAQmx::anlgEdgeStartTrig() {return &_anlgEdgeStartTrig;}

// Digital edge reference trigger

DigEdgeRefTrig* QmlDAQmx::digEdgeRefTrig() {return &_digEdgeRefTrig;}

// Analog edge reference trigger

AnlgEdgeRefTrig* QmlDAQmx::anlgEdgeRefTrig() {return &_anlgEdgeRefTrig;}

// Start trigger retriggerable

StartTrigRetriggerable* QmlDAQmx::startTrigRetriggerable() {return &_startTrigRetriggerable;}

// Analog out function generator

AOFuncGenChan* QmlDAQmx::aoFuncGenChan() {return &_aoFuncGenChan;}

// Analog out voltage channel

AOVoltageChan* QmlDAQmx::aoVoltageChan() {return &_aoVoltageChan;}

// Write analog F64

WriteAnalogF64* QmlDAQmx::writeAnalogF64() {return &_writeAnalogF64;}

// Write analog scalar F64

WriteAnalogScalarF64* QmlDAQmx::writeAnalogScalarF64() {return &_writeAnalogScalarF64;}

// Status and read / write buffers (all data is moved via stringlists for now).

QString QmlDAQmx::statusMsg(){return _statusMsg;}
// Read only

QStringList QmlDAQmx::readStringList(){return _readStringList;}
// Read only

QList<qreal> QmlDAQmx::dataList() {return _dataList;}
// Read only

QList<qreal> QmlDAQmx::getDataList() {return _dataList;}




QList<qreal> QmlDAQmx::getData() {
    quint32 i;
    //    QList<qreal> tempList;
    _dataList.clear();
    _min = _max = _data[0];
    for (i=0; i<_dataSize; i++) {
        _dataList.append(_data[i]);
        if (_data[i] > _max) {_max = _data[i];}
        if (_data[i] < _min) {_min = _data[i];}
    }
    emit maxChanged();
    emit minChanged();
    return _dataList;
}

//QmlDAQmx::updateData() {
//    quint32 i;
//    //    QList<qreal> tempList;
//    _dataList.clear();
//    _min = _max = _data[0];
//    for (i=0; i<_dataSize; i++) {
//        _dataList.append(_data[i]);
//        if (_data[i] > _max) {_max = _data[i];}
//        if (_data[i] < _min) {_min = _data[i];}
//    }
//    emit maxChanged();
//    emit minChanged();
//    emit realData
//}

QStringList QmlDAQmx::writeStringList(){return _writeStringList;}
void QmlDAQmx::setWriteStringList(const QStringList &rn){
    if (rn != _writeStringList) {
        _writeStringList = rn;
        emit writeStringListChanged();
    }
}

quint32 QmlDAQmx::numRead() {return _numRead;}
qint32 QmlDAQmx::numWritten() {return _numWritten;}
qreal QmlDAQmx::max() {return _max;}
qreal QmlDAQmx::min() {return _min;}

int32 CVICALLBACK DoneCallback(TaskHandle taskHandle, int32 eventStatus, void *callbackData)
{
    int32 status;
    QmlDAQmx* ob = static_cast<QmlDAQmx*>(callbackData);

    qDebug() << "Entered DoneCallback. eventStatus: " << eventStatus;
    return 0;
}

int32 CVICALLBACK EveryNSamplesEventCallback (TaskHandle taskHandle, int32 eventType, uInt32 numSamples, void *callbackData)
{
    int32 status;
    //    float64 *p;
    //    uInt32 i;
    int32 ncount;
    //    uInt32 chanCount;
    //    int32 bufSize;
    char errorString[1024];
    QmlDAQmx* ob = static_cast<QmlDAQmx*>(callbackData);


    //    status = DAQmxGetTaskNumChans(taskHandle, &chanCount);
    //    bufSize = ob->_readAnalogF64.numSampsPerChan() * chanCount;
    //    p = new (std::nothrow) float64[bufSize];

    //    if (p == nullptr) {
    //        qDebug() << "Error: memory could not be allocated." << numSamples << "not allocated" << endl;
    //        delete[] p;
    //    }
    //    else {

    status = DAQmxReadAnalogF64(taskHandle, ob->_readAnalogF64.numSampsPerChan(), ob->_readAnalogF64.timeout(), ob->_readAnalogF64.fillMode(), ob->_data, ob->_dataSize, &ncount, NULL);
    if (status < 0) {
        DAQmxGetErrorString (status, errorString, 1024);
        qDebug() << errorString << endl;
    }
    ob->_numRead = ncount;
    //    ob->_qRealDataList.clear();
    //    ob->_max = p[0];
    //    ob->_min = p[0];

    //    for (i=0; i<chanCount*ncount; i++) {
    //        if (p[i] > ob->_max) {ob->_max = p[i];}
    //        if (p[i] < ob->_min) {ob->_min = p[i];}
    //        ob->_qRealDataList.append(p[i]);
    //    }

    //    emit ob->qRealDataListChanged();
    emit ob->numReadChanged();
    emit ob->newData();
    //    emit ob->maxChanged();
    //    emit ob->minChanged();

    //    }
    //    delete[] p;
    return 0;
}





