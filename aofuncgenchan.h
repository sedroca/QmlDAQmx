#ifndef AOFUNCGENCHAN_H
#define AOFUNCGENCHAN_H

#ifndef NIDAQMX_H
#define NIDAQMX_H
#include "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h"
#endif  // NIDAQMX_H

#include <QQuickItem>

class AOFuncGenChan : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(FuncGenType)

    Q_PROPERTY(QString          physicalChannel       READ physicalChannel      WRITE setPhysicalChannel      NOTIFY physicalChannelChanged)
    Q_PROPERTY(FuncGenType      type                  READ type                 WRITE setType                 NOTIFY typeChanged)
    Q_PROPERTY(qreal            frequency             READ frequency            WRITE setFrequency            NOTIFY frequencyChanged)
    Q_PROPERTY(qreal            amplitude             READ amplitude            WRITE setAmplitude            NOTIFY amplitudeChanged)
    Q_PROPERTY(qreal            offset                READ offset               WRITE setOffset               NOTIFY offsetChanged)

public:
    explicit AOFuncGenChan(QQuickItem *parent = 0);

    //    enum FuncGenType {Sine = 14751, Triangle = 14752, Square = 14753, Sawtooth = 14754};
    enum FuncGenType {Sine = DAQmx_Val_Sine, Triangle = DAQmx_Val_Triangle, Square = DAQmx_Val_Square, Sawtooth = DAQmx_Val_Sawtooth};

    QString physicalChannel();  void setPhysicalChannel(const QString &rn);
    FuncGenType type();         void setType(const FuncGenType &rn);
    qreal frequency();          void setFrequency(const qreal &rn);
    qreal amplitude();          void setAmplitude(const qreal &rn);
    qreal offset();             void setOffset(const qreal &rn);


signals:
    void physicalChannelChanged();
    void typeChanged();
    void frequencyChanged();
    void amplitudeChanged();
    void offsetChanged();

public slots:

private:
    QString         _physicalChannel;
    FuncGenType     _type;
    qreal           _frequency;
    qreal           _amplitude;
    qreal           _offset;

};

#endif // AOFUNCGENCHAN_H
