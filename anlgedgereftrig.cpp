#include "anlgedgereftrig.h"

AnlgEdgeRefTrig::AnlgEdgeRefTrig(QQuickItem *parent) :
    QQuickItem(parent)
{
}


bool AnlgEdgeRefTrig::active(){return _active;}
void AnlgEdgeRefTrig::setActive(const bool &rn){
    if (rn != _active) {
        _active = rn;
        emit activeChanged();
    }
}

QString AnlgEdgeRefTrig::triggerSource(){return _triggerSource;}
void AnlgEdgeRefTrig::setTriggerSource(const QString &rn){
    if (rn != _triggerSource) {
        _triggerSource = rn;
        emit triggerSourceChanged();
    }
}

AnlgEdgeRefTrig::TriggerSlope AnlgEdgeRefTrig::triggerSlope(){return _triggerSlope;}
void AnlgEdgeRefTrig::setTriggerSlope(const TriggerSlope &rn){
    if (rn != _triggerSlope) {
        _triggerSlope = rn;
        emit triggerSlopeChanged();
    }
}

qreal AnlgEdgeRefTrig::triggerLevel(){return _triggerLevel;}
void AnlgEdgeRefTrig::setTriggerLevel(const qreal &rn){
    if (rn != _triggerLevel) {
        _triggerLevel = rn;
        emit triggerLevelChanged();
    }
}

quint32 AnlgEdgeRefTrig::pretriggerSamples(){return _pretriggerSamples;}
void AnlgEdgeRefTrig::setPretriggerSamples(const quint32 &rn){
    if (rn != _pretriggerSamples) {
        _pretriggerSamples = rn;
        emit pretriggerSamplesChanged();
    }
}
