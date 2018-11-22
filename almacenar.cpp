#include "almacenar.h"

Almacenar::Almacenar()
{

}

int Almacenar::getAng()
{
    return ang;
}

int Almacenar::getPosx()
{
    return posx;
}

int Almacenar::getPosy()
{
    return posy;
}

int Almacenar::getVelx()
{
    return velx;
}

int Almacenar::getVely()
{
    return vely;
}
int Almacenar::getRad()
{
    return r;
}

void Almacenar::setAng(int a)
{
    ang=a;
}

void Almacenar::setPosx(int x)
{
    posx=x;
}

void Almacenar::setPosy(int y)
{
    posy=y;
}

void Almacenar::setVel(int vx, int vy)
{
    velx=vx;
    vely=vy;
}
void Almacenar::setRad(int rad)
{
    r=rad;
}


