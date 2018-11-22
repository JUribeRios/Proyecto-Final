#include "particula.h"

Particula::Particula()
{

}

float Particula::getpos_x()
{
    return px;
}

float Particula::getpos_y()
{
    return py;
}

float Particula::getvel_x()
{
    return vx;
}

float Particula::getvel_y()
{
    return vy;
}

float Particula::getradio()
{
    return r;
}

float Particula::setradio(float rad)
{
    r = rad;
}

void Particula::setvelocidad(float velx, float vely)
{
    vx=velx;
    vy=vely;
}

void Particula::setposicion(int x, int y)
{
    x0=x;
    y0=y;
}

void Particula::setangulo(int a)
{
    ang=a;
}

int Particula::getangulo()
{
    return  ang;
}

void Particula::mover(float vertlim)
{
    px=x0+vx*cos((ang*pi)/180)*t;  //Ecuacion para calcular posicion en x
    py=y0+(vy*sin((ang*pi)/180)*t)-0.5*g*pow(t,2);  //Ecuacion para calcular posicion en y
    t=t+0.1; //Contador para aumentar el tiempo
    setPos(getpos_x(),(vertlim-getpos_y()));
}

void Particula::colision(float horzlim, float vertlim)
{

    if(getpos_x()<getradio()|| getpos_x()>horzlim-getradio())
    {
     setvelocidad(-1*getvel_x(),getvel_y());
    }
    if(getpos_y()<getradio()||getpos_y()>vertlim-getradio())
    {
        if(getpos_y()<0||getpos_y()>vertlim-getradio())
        {
            u=sqrt(2*g*y0);
            v=E*u;
            y0=pow(E,2*n)*y0;
            n++;
            vx=v;
            vy=v;
            t=0;
            x0=px;
        }

         //setvelocidad(getvel_x(),-1*getvel_y());
    }

}

QRectF Particula::boundingRect() const
{
   return QRectF(-1*r,-1*r,2*r,2*r);
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setBrush(Qt::darkMagenta);              // da color a la particula de magenta
    painter->drawEllipse(boundingRect());        // Dibuja una figura eliptica y la encierra en un rectangulo
}
