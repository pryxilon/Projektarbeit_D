#include "animation.h"
#include "square.h"
#include "globals.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QRectF>

Square::Square()
{
    qDebug() << "Default Constructor Square";
}

Square::Square(QRectF rect, QGraphicsView * view, int i)
{
    //set Slot, View, ID,
    setSlotRect(rect);
    setView(view);
    setID1(i);
    setSqWidth(rect.width());
    setSqHeight(rect.height() / 3);
    setPos(rect.x(), rect.y() + getSqHeight() * i);
    setAnimationOfStaticSquare();
}

Square::Square(int x, int y, QGraphicsView * view, int i)
{
    //set Slot, View, ID,
    setView(view);
    setID1(i);
    setSqWidth(squareWidth);
    setSqHeight(squareHeight);
    setPos(x, y);
    setAnimationOfStaticSquare();
}

Square::Square(QRectF rect, QGraphicsView * view, int i, int type)
{
    //set Slot, View, ID,
    setSlotRect(rect);
    setView(view);
    setID1(i);
    setSqWidth(rect.width());
    setSqHeight(rect.height() / 3);
    setStepsize(40);                                                        //Standard 10
    setDefY(rect.y() - getSqHeight() * 2 - 80 /*getStepsize() * 4*/ /*160*/);              // 120 bei stepsize 20, 120/80 bei 40
    setMovingY(getDefY());
    setType(type);
    setPos(rect.x(), rect.y());
    setPixmapOfSquare(type);
}

void Square::setSlotRect(QRectF rect)
{
    this->rect = rect;
}

QRectF Square::getSlotRect()
{
    return rect;
}

void Square::setView(QGraphicsView * view)
{
    this->view = view;
}

QGraphicsView *Square::getView()
{
    return view;
}

void Square::setID1(int i)
{
    this->id1 = i;
}

int Square::getID1()
{
    return id1;
}

void Square::setPositionToDefault()
{
    setPos(getSlotRect().x(), getDefY());
}

void Square::setDefY(int defY)
{
    this->defY = defY;
}

int Square::getDefY()
{
    return defY;
}

void Square::setMovingY(int y)
{
    movingY = y;
}

int Square::getMovingY()
{
    return movingY;
}

void Square::setSqHeight(int height)
{
    sqHeight = height;
}

int Square::getSqHeight()
{
    return sqHeight;
}

void Square::setSqWidth(int width)
{
    sqWidth = width;
}

int Square::getSqWidth()
{
    return sqWidth;
}

int Square::getType()
{
    return type;
}

void Square::setType(int type)
{
    this->type = type;
}

void Square::setPixmapOfSquare(int type)
{
    switch(type){
    case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Erde.png")); break;
    case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Mond.png")); break;
    case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Shuttle.png")); break;
    case 3: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Astronaut.png")); break;
    case 4: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Wurmloch.png")); break;
    case 5: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Ten.png")); break;
    case 6: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Jack.png")); break;
    case 7: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Queen.png")); break;
    case 8: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/King.png")); break;
    case 9: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Ace.png")); break;
    }
}

void Square::setPixmapOfStaticSquare(int type)
{
    switch(type){
    case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/empty240.png")); break;
    case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/win240.png")); break;
    }
}

void Square::setAnimationOfStaticSquare()
{
    winAnimation = new Animation(getView(), this->x(), this->y());
}

int Square::getPosY()
{
    return this->y();
}

int Square::getStepsize() const
{
    return stepsize;
}

void Square::setStepsize(int value)
{
    stepsize = value;
}

void Square::moveSquare()
{
    if(y() >= getSlotRect().height() + getSqHeight()){
        setPos(getSlotRect().x(), getDefY());              // Position wird gesetzt, muss vom Ausgangs-Y noch um 105 px verschoben werden
    } else {
        setPos(x(),y() + getStepsize());
    }
}

Animation *Square::getWinAnimation() const
{
    return winAnimation;
}

void Square::setWinAnimation(Animation *value)
{
    winAnimation = value;
}

