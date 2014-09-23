#include "aofuncgenchan.h"

AOFuncGenChan::AOFuncGenChan(QQuickItem *parent) :
    QQuickItem(parent)
{
}

QString AOFuncGenChan::physicalChannel(){return _physicalChannel;}
void AOFuncGenChan::setPhysicalChannel(const QString &rn){
    if (rn != _physicalChannel) {
        _physicalChannel = rn;
        emit physicalChannelChanged();
    }
}

AOFuncGenChan::FuncGenType AOFuncGenChan::type(){return _type;}
void AOFuncGenChan::setType(const FuncGenType &rn){
    if (rn != _type) {
        _type = rn;
        emit typeChanged();
    }
}

qreal AOFuncGenChan::frequency(){return _frequency;}
void AOFuncGenChan::setFrequency(const qreal &rn){
    if (rn != _frequency) {
        _frequency = rn;
        emit frequencyChanged();
    }
}

qreal AOFuncGenChan::amplitude(){return _amplitude;}
void AOFuncGenChan::setAmplitude(const qreal &rn){
    if (rn != _amplitude) {
        _amplitude = rn;
        emit amplitudeChanged();
    }
}

qreal AOFuncGenChan::offset(){return _offset;}
void AOFuncGenChan::setOffset(const qreal &rn){
    if (rn != _offset) {
        _offset = rn;
        emit offsetChanged();
    }
}
