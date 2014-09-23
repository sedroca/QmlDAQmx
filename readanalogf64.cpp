#include "readanalogf64.h"

ReadAnalogF64::ReadAnalogF64(QQuickItem *parent) :
    QQuickItem(parent)
{
}


qint32 ReadAnalogF64::numSampsPerChan(){return _numSampsPerChan;}
void ReadAnalogF64::setNumSampsPerChan(const qint32 &rn){
    if (rn != _numSampsPerChan) {
        _numSampsPerChan = rn;
        emit numSampsPerChanChanged();
    }
}

qreal ReadAnalogF64::timeout(){return _timeout;}
void ReadAnalogF64::setTimeout(const qreal &rn){
    if (rn != _timeout) {
        _timeout = rn;
        emit timeoutChanged();
    }
}

ReadAnalogF64::FillMode ReadAnalogF64::fillMode(){return _fillMode;}
void ReadAnalogF64::setFillMode(const FillMode &rn){
    if (rn != _fillMode) {
        _fillMode = rn;
        emit fillModeChanged();
    }
}
