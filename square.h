#ifndef SQUARE_H
#define SQUARE_H

#include "animation.h"

#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QObject>
#include <QGraphicsView>


class Square: public QGraphicsPixmapItem {
public:
    Square();
    Square(QRectF, QGraphicsView *, int);
    Square(int, int, QGraphicsView *, int);
    Square(QRectF, QGraphicsView *, int, int);
    void setSlotRect(QRectF);
    QRectF getSlotRect();
    void setView(QGraphicsView *);
    QGraphicsView * getView();

    // setter und getter
    void setID1(int);
    int getID1();
    void setPositionToDefault();
    int getType();
    void setType(int);
    int getStepsize() const;
    void setStepsize(int value);
    void setPixmapOfSquare(int);
    void setAnimationOfStaticSquare();
    int getPosY();

    // Y-Axis
    void setDefY(int);
    int getDefY();
    void setMovingY(int);
    int getMovingY();

    // Square dimensions
    void setSqHeight(int);
    int  getSqHeight();
    void setSqWidth(int);
    int  getSqWidth();

    // Hauptfunktion Square
    void moveSquare();

    Animation *getWinAnimation() const;
    void setWinAnimation(Animation *value);

    void setPixmapOfStaticSquare(int type);


private:
    QRectF rect;
    QGraphicsView * view;
    int id1;
    int defY;
    QPixmap pic;
    bool activeMoving;
    int movingY;

    int sqHeight, sqWidth;
    int type;
    int stepsize;
    Animation * winAnimation;
};

#endif // SQUARE_H
