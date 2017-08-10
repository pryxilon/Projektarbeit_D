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

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    int width;
    int height;
    int x;
    int y;
};

#endif // SEPARATOR_H
