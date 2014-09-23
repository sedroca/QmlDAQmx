#include "anlgedgestarttrig.h"

AnlgEdgeStartTrig::AnlgEdgeStartTrig(QQuickItem *parent) :
    QQuickItem(parent)
{
}

bool AnlgEdgeStartTrig::active(){return _active;}
void AnlgEdgeStartTrig::setActive(const bool &rn){
    if (rn != _active) {
        _active = rn;
        emit activeChanged();
    }
}

QString AnlgEdgeStartTrig::triggerSource(){return _triggerSource;}
void AnlgEdgeStartTrig::setTriggerSource(const QString &rn){
    if (rn != _triggerSource) {
        _triggerSource = rn;
        emit triggerSourceChanged();
    }
}

AnlgEdgeStartTrig::TriggerSlope AnlgEdgeStartTrig::triggerSlope(){return _triggerSlope;}
void AnlgEdgeStartTrig::setTriggerSlope(const TriggerSlope &rn){
    if (rn != _triggerSlope) {
        _triggerSlope = rn;
        emit triggerSlopeChanged();
    }
}

qreal AnlgEdgeStartTrig::triggerLevel(){return _triggerLevel;}
void AnlgEdgeStartTrig::setTriggerLevel(const qreal &rn){
    if (rn != _triggerLevel) {
        _triggerLevel = rn;
        emit triggerLevelChanged();
    }
}
