#ifndef STARTTRIGRETRIGGERABLE_H
#define STARTTRIGRETRIGGERABLE_H

#include <QQuickItem>

class StartTrigRetriggerable : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(bool             active       READ active      WRITE setActive      NOTIFY activeChanged)

public:
    explicit StartTrigRetriggerable(QQuickItem *parent = 0);

    bool active();  void setActive(const bool &rn);


signals:
    void activeChanged();

public slots:

private:
    bool _active;
};

#endif // STARTTRIGRETRIGGERABLE_H
