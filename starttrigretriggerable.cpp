#include "starttrigretriggerable.h"

StartTrigRetriggerable::StartTrigRetriggerable(QQuickItem *parent) :
    QQuickItem(parent)
{
}

bool StartTrigRetriggerable::active(){return _active;}
void StartTrigRetriggerable::setActive(const bool &rn){
    if (rn != _active) {
        _active = rn;
        emit activeChanged();
    }
}
