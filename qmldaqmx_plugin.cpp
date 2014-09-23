#include "qmldaqmx_plugin.h"
#include "qmldaqmx.h"

#include <qqml.h>

void QmlDAQmxPlugin::registerTypes(const char *uri)
{
    // @uri com.github.qmldaqmx
    qmlRegisterType<QmlDAQmx>(uri, 1, 0, "QmlDAQmx");
    qmlRegisterType<AIVoltageChan>(uri, 1, 0, "AIVoltageChan");
    qmlRegisterType<SampleClock>(uri, 1, 0, "SampleClock");
    qmlRegisterType<DigEdgeStartTrig>(uri, 1, 0, "DigEdgeStartTrig");
    qmlRegisterType<EveryNSamplesEvent>(uri, 1, 0, "EveryNSamplesEvent");
    qmlRegisterType<ReadAnalogF64>(uri, 1, 0, "ReadAnalogF64");
    qmlRegisterType<AnlgEdgeStartTrig>(uri, 1, 0, "AnlgEdgeStartTrig");
    qmlRegisterType<DigEdgeRefTrig>(uri, 1, 0, "DigEdgeRefTrig");
    qmlRegisterType<AnlgEdgeRefTrig>(uri, 1, 0, "AnlgEdgeRefTrig");
    qmlRegisterType<AOFuncGenChan>(uri, 1, 0, "AOFuncGenChan");
    qmlRegisterType<AOVoltageChan>(uri, 1, 0, "AOVoltageChan");
    qmlRegisterType<WriteAnalogF64>(uri, 1, 0, "WriteAnalogF64");
    qmlRegisterType<WriteAnalogScalarF64>(uri, 1, 0, "WriteAnalogScalerF64");
    qmlRegisterType<StartTrigRetriggerable>(uri, 1, 0, "StartTrigRetriggerable");
}


