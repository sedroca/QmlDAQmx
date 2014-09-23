#include "writeanalogscalarf64.h"

WriteAnalogScalarF64::WriteAnalogScalarF64(QQuickItem *parent) :
    QQuickItem(parent)
{
}



bool WriteAnalogScalarF64::autoStart() {return _autoStart;}
void WriteAnalogScalarF64::setAutoStart(const bool &rn) {
    if (rn != _autoStart) {
        _autoStart = rn;
        emit autoStartChanged();
    }
}

qreal WriteAnalogScalarF64::timeout() {return _timeout;}
void WriteAnalogScalarF64::setTimeout(const qreal &rn) {
    if (rn != _timeout) {
        _timeout = rn;
        emit timeoutChanged();
    }
}

qreal WriteAnalogScalarF64::value() {return _value;}
void WriteAnalogScalarF64::setValue(const qreal &rn) {
    if (rn != _value) {
        _value = rn;
        emit valueChanged();
    }
}

