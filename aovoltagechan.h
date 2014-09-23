#ifndef AOVOLTAGECHAN_H
#define AOVOLTAGECHAN_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class AOVoltageChan : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(Units)

    Q_PROPERTY(bool             active                READ active               WRITE setActive               NOTIFY activeChanged)
    Q_PROPERTY(QString          physicalChannel       READ physicalChannel      WRITE setPhysicalChannel      NOTIFY physicalChannelChanged)
    Q_PROPERTY(qreal            minVal                READ minVal               WRITE setMinVal               NOTIFY minValChanged)
    Q_PROPERTY(qreal            maxVal                READ maxVal               WRITE setMaxVal               NOTIFY maxValChanged)
    Q_PROPERTY(Units            units                 READ units                WRITE setUnits                NOTIFY unitsChanged)

public:
    explicit AOVoltageChan(QQuickItem *parent = 0);

    //    enum Units {Volts = 10348, FromCustomScale = 10065, FromTeds = 12516};
    enum Units {Volts = DAQmx_Val_Volts, FromCustomScale = DAQmx_Val_FromCustomScale};

    bool active(); void setActive(const bool &rn);
    QString physicalChannel();  void setPhysicalChannel(const QString &rn);
    qreal minVal();             void setMinVal(const qreal &rn);
    qreal maxVal();             void setMaxVal(const qreal &rn);
    Units units();              void setUnits(const Units &rn);


signals:
    void activeChanged();
    void physicalChannelChanged();
    void minValChanged();
    void maxValChanged();
    void unitsChanged();

public slots:

private:
    bool            _active;
    QString         _physicalChannel;
    qreal           _minVal;
    qreal           _maxVal;
    Units           _units;


};

#endif // AOVOLTAGECHAN_H
