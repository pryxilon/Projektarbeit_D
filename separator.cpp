#include "separator.h"
#include "globals.h"

Separator::Separator(int x, int y)
{
    setPos(x, y);
    setWidth(20);
    setHeight(720);
    setX(x);
    setY(y);
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

int Separator::getX() const
{
    return x;
}

void Separator::setX(int value)
{
    x = value;
}

int Separator::getY() const
{
    return y;
}

void Separator::setY(int value)
{
    y = value;
}
