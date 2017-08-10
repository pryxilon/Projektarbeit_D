#ifndef SQUARE_H
#define SQUARE_H

#include "animation.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsView>


class Square: public QGraphicsPixmapItem {
public:
    Square();
    Square(int, int, QGraphicsView *, int);
    Square(int, int, QGraphicsView *, int, int);

    // setter und getter

    void setView(QGraphicsView *);
    QGraphicsView * getView();
    void setID(int);
    int  getID();
    int  getParentalID() const;
    void setParentalID(int value);
    int  getType();
    void setType(int);
    int  getPosX() const;
    void setPosX(int value);
    int  getPosY() const;
    void setPosY(int value);
    int  getStepsize() const;
    void setStepsize(int value);
    Animation *getWinAnimation() const;
    void setWinAnimation(Animation *value);

    // Y-Axis
    void setDefY(int);
    int  getDefY();
    void setMovingY(int);
    int  getMovingY();

    void setYPositionToDefault();
    void setPixmapOfSquare(int);
    void setPixmapOfStaticSquare(int type);
    void hidePixmapOfStaticSquare();
    void setAnimationOfStaticSquare();

    // Hauptfunktion Square
    void moveSquare();

private:
    int posX;
    int posY;
    QRectF rect;
    int parentalID;
    QGraphicsView * view;
    int ID;
    int defY;
    QPixmap pic;
    bool activeMoving;
    int movingY;

    int type;
    int stepsize;
    Animation * winAnimation;
};

#endif // SQUARE_H
