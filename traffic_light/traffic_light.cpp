#include "traffic_light.h"

Traffic_Light::Traffic_Light()
{
    for(int i = 0; i < 3; i++)
    {
        m_light[i].set_color(static_cast<Color>(i));
        m_light[i].set_light(false);
    }

    //m_light[0].set_light(true); // Red light
    int light = QSettings("GameSmith","Traffic Light").value("Light", 0).toInt();
    toggle_light(light);

    qDebug() << "Traffic light ctor.";
}

int Traffic_Light::get_light_on()
{
    for(int i = 0; i < 3; ++i)
    {
         if(m_light[i].get_light())
             return i;
    }

    return -1;
}

void Traffic_Light::toggle_light(int index)
{
    for(int i = 0; i < 3; ++i)
    {
        if(i == index)
            m_light[i].set_light(true);
        else
            m_light[i].set_light(false);
    }

    QSettings("GameSmith","Traffic Light").setValue("Light", index);

    emit light_changed(index);
}

QColor Traffic_Light::get_color(int index)
{
    return m_light[index].get_color();
}

