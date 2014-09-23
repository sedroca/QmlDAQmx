#include "aivoltagechan.h"
//#include "qmldaqmx.h"

AIVoltageChan::AIVoltageChan(QQuickItem *parent) :
    QQuickItem(parent)
{
}

bool AIVoltageChan::active() {return _active;}
void AIVoltageChan::setActive(const bool &rn) {
    if (rn != _active) {
        _active = rn;
        emit activeChanged();
    }
}

QString AIVoltageChan::physicalChannel() {return _physicalChannel;}
void AIVoltageChan::setPhysicalChannel(const QString &rn) {
    if (rn != _physicalChannel) {
        _physicalChannel = rn;
        emit physicalChannelChanged();
    }
}

AIVoltageChan::TerminalConfig AIVoltageChan::terminalConfig() {return _terminalConfig;}
void AIVoltageChan::setTerminalConfig(const TerminalConfig &rn){
    if (rn != _terminalConfig) {
        _terminalConfig = rn;
        emit terminalConfigChanged();
    }
}

qreal AIVoltageChan::minVal(){return _minVal;}
void AIVoltageChan::setMinVal(const qreal &rn){
    if (rn != _minVal) {
        _minVal = rn;
        emit minValChanged();
    }
}

qreal AIVoltageChan::maxVal(){return _maxVal;}
void AIVoltageChan::setMaxVal(const qreal &rn){
    if (rn != _maxVal) {
        _maxVal = rn;
        emit maxValChanged();
    }
}

AIVoltageChan::Units AIVoltageChan::units(){return _units;}
void AIVoltageChan::setUnits(const Units &rn){
    if (rn != _units) {
        _units = rn;
        emit unitsChanged();
    }
}
