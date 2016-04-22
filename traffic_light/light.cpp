#include "light.h"

Light::Light()
    :m_light_on(true), m_color(RED)
{
    qDebug() << "Light ctor.";
}

void Light::set_color(Color color)
{
    m_color = color;
}

QColor Light::get_color()
{
    switch(m_color)
    {
    case RED:
        return Qt::red;
    case YELLOW:
        return Qt::yellow;
    case GREEN:
        return Qt::green;
    }
}

void Light::set_light(bool is_on)
{
    if(is_on == true)
        m_light_on = true;
    else
        m_light_on = false;
}

bool Light::get_light()
{
    return m_light_on;
}
