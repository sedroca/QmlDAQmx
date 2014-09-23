#ifndef WRITEANALOGSCALARF64_H
#define WRITEANALOGSCALARF64_H

#include <QQuickItem>

class WriteAnalogScalarF64 : public QQuickItem
{
    Q_OBJECT


    Q_PROPERTY(bool     autoStart   READ autoStart  WRITE setAutoStart  NOTIFY autoStartChanged)
    Q_PROPERTY(qreal    timeout     READ timeout    WRITE setTimeout    NOTIFY timeoutChanged)
    Q_PROPERTY(qreal    value       READ value      WRITE setValue      NOTIFY valueChanged)

public:
    explicit WriteAnalogScalarF64(QQuickItem *parent = 0);

    bool autoStart(); void setAutoStart(const bool &rn);
    qreal timeout(); void setTimeout(const qreal &rn);
    qreal value(); void setValue(const qreal &rn);

signals:
    void autoStartChanged();
    void timeoutChanged();
    void valueChanged();

public slots:

private:
    bool  _autoStart;
    qreal _timeout;
    qreal _value;

};

#endif // WRITEANALOGSCALARF64_H
