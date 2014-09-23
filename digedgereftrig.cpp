#include "digedgereftrig.h"

DigEdgeRefTrig::DigEdgeRefTrig(QQuickItem *parent) :
    QQuickItem(parent)
{
}


bool DigEdgeRefTrig::active(){return _active;}
void DigEdgeRefTrig::setActive(const bool &rn){
    if (rn != _active) {
        _active = rn;
        emit activeChanged();
    }
}

QString DigEdgeRefTrig::triggerSource(){return _triggerSource;}
void DigEdgeRefTrig::setTriggerSource(const QString &rn){
    if (rn != _triggerSource) {
        _triggerSource = rn;
        emit triggerSourceChanged();
    }
}

DigEdgeRefTrig::ActiveEdge DigEdgeRefTrig::triggerEdge(){return _triggerEdge;}
void DigEdgeRefTrig::setTriggerEdge(const ActiveEdge &rn){
    if (rn != _triggerEdge) {
        _triggerEdge = rn;
        emit triggerEdgeChanged();
    }
}

quint32 DigEdgeRefTrig::pretriggerSamples(){return _pretriggerSamples;}
void DigEdgeRefTrig::setPretriggerSamples(const quint32 &rn){
    if (rn != _pretriggerSamples) {
        _pretriggerSamples = rn;
        emit pretriggerSamplesChanged();
    }
}
