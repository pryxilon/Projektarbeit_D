#include "separator.h"
#include "globals.h"

Separator::Separator(int x, int y)
{
    setPos(x, y);
    setWidth(20);
    setHeight(720);
    setPosX(x);
    setPosY(y);
    setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Separator/Separator2.png"));
}

int Separator::getWidth() const
{
    return width;
}

void Separator::setWidth(int value)
{
    width = value;
}

int Separator::getHeight() const
{
    return height;
}

void Separator::setHeight(int value)
{
    height = value;
}

int Separator::getPosX() const
{
    return posX;
}

void Separator::setPosX(int value)
{
    posX = value;
}

int Separator::getPosY() const
{
    return posY;
}

void Separator::setPosY(int value)
{
    posY = value;
}
