#include "digedgestarttrig.h"

DigEdgeStartTrig::DigEdgeStartTrig(QQuickItem *parent) :
    QQuickItem(parent)
{
}

bool DigEdgeStartTrig::active(){return _active;}
void DigEdgeStartTrig::setActive(const bool &rn){
    if (rn != _active) {
        _active = rn;
        emit activeChanged();
    }
}

QString DigEdgeStartTrig::triggerSource(){return _triggerSource;}
void DigEdgeStartTrig::setTriggerSource(const QString &rn){
    if (rn != _triggerSource) {
        _triggerSource = rn;
        emit triggerSourceChanged();
    }
}

DigEdgeStartTrig::ActiveEdge DigEdgeStartTrig::triggerEdge(){return _triggerEdge;}
void DigEdgeStartTrig::setTriggerEdge(const ActiveEdge &rn){
    if (rn != _triggerEdge) {
        _triggerEdge = rn;
        emit triggerEdgeChanged();
    }
}
