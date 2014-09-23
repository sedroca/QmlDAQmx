#include "everynsamplesevent.h"



EveryNSamplesEvent::EveryNSamplesEvent(QQuickItem *parent) :
    QQuickItem(parent)
{
}

// Every N samples event

EveryNSamplesEvent::EventType EveryNSamplesEvent::eventType(){return _eventType;}
void EveryNSamplesEvent::setEventType(const EventType &rn){
    if (rn != _eventType) {
        _eventType = rn;
        emit eventTypeChanged();
    }
}

quint32 EveryNSamplesEvent::numSamples(){return _numSamples;}
void EveryNSamplesEvent::setNumSamples(const quint32 &rn){
    if (rn != _numSamples) {
        _numSamples = rn;
        emit numSamplesChanged();
    }
}
