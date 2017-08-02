#ifndef SEPARATOR_H
#define SEPARATOR_H

#include <QGraphicsRectItem>
#include "gameframe.h"

class Separator: public QGraphicsPixmapItem {
public:
    Separator(int, int);
    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    int getPosX() const;
    void setPosX(int value);

    int getPosY() const;
    void setPosY(int value);

private:
    int width;
    int height;
    int posX;
    int posY;
};

#endif // SEPARATOR_H
