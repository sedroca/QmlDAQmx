#include "sampleclock.h"

SampleClock::SampleClock(QQuickItem *parent) :
    QQuickItem(parent)
{
}

bool SampleClock::active() {return _active;}
void SampleClock::setActive(const bool &rn) {
    if (rn != _active) {
        _source = rn;
        emit activeChanged();
    }
}

QString SampleClock::source(){return _source;}
void SampleClock::setSource(const QString &rn){
    if (rn != _source) {
        _source = rn;
        emit sourceChanged();
    }
}

qreal SampleClock::rate(){return _rate;}
void SampleClock::setRate(const qreal &rn){
    if (rn != _rate) {
        _rate = rn;
        emit rateChanged();
    }
}

SampleClock::ActiveEdge SampleClock::activeEdge(){return _activeEdge;}
void SampleClock::setActiveEdge(const ActiveEdge &rn){
    if (rn != _activeEdge) {
        _activeEdge = rn;
        emit activeEdgeChanged();
    }
}

SampleClock::SampleMode SampleClock::sampleMode(){return _sampleMode;}
void SampleClock::setSampleMode(const SampleMode &rn){
    if (rn != _sampleMode) {
        _sampleMode = rn;
        emit sampleModeChanged();
    }
}

quint32 SampleClock::sampsPerChanToAcquire(){return _sampsPerChanToAcquire;}
void SampleClock::setSampsPerChanToAcquire(const quint32 &rn){
    if (rn != _sampsPerChanToAcquire) {
        _sampsPerChanToAcquire = rn;
        emit sampsPerChanToAcquireChanged();
    }
}
