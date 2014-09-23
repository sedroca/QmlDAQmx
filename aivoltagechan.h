#ifndef AIVOLTAGECHAN_H
#define AIVOLTAGECHAN_H



#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class AIVoltageChan : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(TerminalConfig)
    Q_ENUMS(Units)

    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(QString                      physicalChannel       READ physicalChannel      WRITE setPhysicalChannel      NOTIFY physicalChannelChanged)
    Q_PROPERTY(TerminalConfig               terminalConfig        READ terminalConfig       WRITE setTerminalConfig       NOTIFY terminalConfigChanged)
    Q_PROPERTY(qreal                        minVal                READ minVal               WRITE setMinVal               NOTIFY minValChanged)
    Q_PROPERTY(qreal                        maxVal                READ maxVal               WRITE setMaxVal               NOTIFY maxValChanged)
    Q_PROPERTY(Units                        units                 READ units                WRITE setUnits                NOTIFY unitsChanged)

public:
    explicit AIVoltageChan(QQuickItem *parent = 0);

//    enum TerminalConfig {Default = -1, RSE = 10083, NRSE = 10078, Diff = 10106, PseudoDiff = 12529 };
//    enum Units {Volts = 10348, FromCustomScale = 10065, FromTeds = 12516};

    enum TerminalConfig {Default = DAQmx_Val_Cfg_Default, RSE = DAQmx_Val_RSE, NRSE = DAQmx_Val_NRSE, Diff = DAQmx_Val_Diff, PseudoDiff = DAQmx_Val_PseudoDiff };
    enum Units {Volts = DAQmx_Val_Volts, FromCustomScale = DAQmx_Val_FromCustomScale, FromTeds = DAQmx_Val_FromTEDS};

    bool active(); void setActive(const bool &rn);
    QString physicalChannel(); void setPhysicalChannel(const QString &rn);
    TerminalConfig terminalConfig(); void setTerminalConfig(const TerminalConfig &rn);
    qreal minVal(); void setMinVal(const qreal &rn);
    qreal maxVal(); void setMaxVal(const qreal &rn);
    Units units(); void setUnits(const Units &rn);

signals:
    void activeChanged();
    void physicalChannelChanged();
    void terminalConfigChanged();
    void minValChanged();
    void maxValChanged();
    void unitsChanged();

public slots:

private:
    bool            _active;
    QString         _physicalChannel;
    TerminalConfig  _terminalConfig;
    qreal           _minVal;
    qreal           _maxVal;
    Units           _units;

};

#endif // AIVOLTAGECHAN_H
