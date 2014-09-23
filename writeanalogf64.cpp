#include "writeanalogf64.h"

WriteAnalogF64::WriteAnalogF64(QQuickItem *parent) :
    QQuickItem(parent)
{
}


qint32 WriteAnalogF64::numSampsPerChan(){return _numSampsPerChan;}
void WriteAnalogF64::setNumSampsPerChan(const qint32 &rn){
    if (rn != _numSampsPerChan) {
        _numSampsPerChan = rn;
        emit numSampsPerChanChanged();
    }
}

bool WriteAnalogF64::autoStart(){return _autoStart;}
void WriteAnalogF64::setAutoStart(const bool &rn){
    if (rn != _autoStart) {
        _autoStart = rn;
        emit autoStartChanged();
    }
}

qreal WriteAnalogF64::timeout(){return _timeout;}
void WriteAnalogF64::setTimeout(const qreal &rn){
    if (rn != _timeout) {
        _timeout = rn;
        emit timeoutChanged();
    }
}

WriteAnalogF64::FillMode WriteAnalogF64::dataLayout(){return _dataLayout;}
void WriteAnalogF64::setDataLayout(const FillMode &rn){
    if (rn != _dataLayout) {
        _dataLayout = rn;
        emit dataLayoutChanged();
    }
}

