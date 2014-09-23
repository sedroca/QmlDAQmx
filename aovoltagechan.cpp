#include "aovoltagechan.h"

AOVoltageChan::AOVoltageChan(QQuickItem *parent) :
    QQuickItem(parent)
{
}

bool AOVoltageChan::active() {return _active;}
void AOVoltageChan::setActive(const bool &rn) {
    if (rn != _active) {
        _active = rn;
        emit activeChanged();
    }
}

QString AOVoltageChan::physicalChannel(){return _physicalChannel;}
void AOVoltageChan::setPhysicalChannel(const QString &rn){
    if (rn != _physicalChannel) {
        _physicalChannel = rn;
        emit physicalChannelChanged();
    }
}

qreal AOVoltageChan::minVal(){return _minVal;}
void AOVoltageChan::setMinVal(const qreal &rn){
    if (rn != _minVal) {
        _minVal = rn;
        emit minValChanged();
    }
}

qreal AOVoltageChan::maxVal(){return _maxVal;}
void AOVoltageChan::setMaxVal(const qreal &rn){
    if (rn != _maxVal) {
        _maxVal = rn;
        emit maxValChanged();
    }
}

AOVoltageChan::Units AOVoltageChan::units(){return _units;}
void AOVoltageChan::setUnits(const Units &rn){
    if (rn != _units) {
        _units = rn;
        emit unitsChanged();
    }
}
