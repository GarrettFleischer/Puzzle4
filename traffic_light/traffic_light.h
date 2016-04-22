#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QColor>
#include <QSettings>
#include "light.h"

class Traffic_Light : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int light READ get_light_on WRITE toggle_light NOTIFY light_changed)

public:
    Traffic_Light();

signals:
    light_changed(int light);

public slots:
    int get_light_on();
    void toggle_light(int light);

    QColor get_color(int index);

private:
    Light m_light[3];
};
#endif // TRAFFIC_LIGHT_H
