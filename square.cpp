#include "animation.h"
#include "square.h"
#include "globals.h"
#include <QDebug>
#include <QGraphicsPixmapItem>

Square::Square()
{
    qDebug() << "Default Constructor Square";
}

Square::Square(int x, int y, QGraphicsView * view, int i)
{
    //set Slot, View, ID,
    setPosX(x);
    setPosY(y);
    setView(view);
    setID(i);
    setPos(x, y);
    //setAnimationOfStaticSquare();
}

Square::Square(int x, int y, QGraphicsView * view, int i, int type)
{
    //set Slot, View, ID,
    setPosX(x);
    setPosY(y);
    setView(view);
    setID(i);
    setStepsize(20);                                                        //Standard 10
    setDefY(getPosY() - squareHeight * 2 - 120);              // 130 bei 10, 120 bei stepsize 20, 120/80 bei 40
    setMovingY(getDefY());
    setType(type);
    setPos(x, y);
    setPixmapOfSquare(type);
}

void Square::setView(QGraphicsView * view)
{
    this->view = view;
}

QGraphicsView *Square::getView()
{
    return view;
}

void Square::setID(int value)
{
    this->ID = value;
}

int Square::getID()
{
    return ID;
}

int Square::getParentalID() const
{
    return parentalID;
}

void Square::setParentalID(int value)
{
    parentalID = value;
}

int Square::getType()
{
    return type;
}

void Square::setType(int type)
{
    this->type = type;
}

int Square::getPosX() const
{
    return posX;
}

void Square::setPosX(int value)
{
    posX = value;
}

int Square::getPosY() const
{
    return posY;
}

void Square::setPosY(int value)
{
    posY = value;
}

int Square::getStepsize() const
{
    return stepsize;
}

void Square::setStepsize(int value)
{
    stepsize = value;
}

Animation *Square::getWinAnimation() const
{
    return winAnimation;
}

void Square::setWinAnimation(Animation *value)
{
    winAnimation = value;
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

void Square::setYPositionToDefault()
{
    setY(getDefY());
}

void Square::setPixmapOfSquare(int type)
{
    switch(type){
    case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Erde.png"));      break;
    case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Mond.png"));      break;
    case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Shuttle.png"));   break;
    case 3: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Astronaut.png")); break;
    case 4: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Wurmloch.png"));  break;
    case 5: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Ten.png"));       break;
    case 6: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Jack.png"));      break;
    case 7: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Queen.png"));     break;
    case 8: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/King.png"));      break;
    case 9: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Squares/Ace.png"));       break;
    default: qDebug() << "wrong type of Square";
    }
}

void Square::setPixmapOfStaticSquare(int linetype)
{
    switch(linetype){
    case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/red.png"));        break;
    case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/green.png"));      break;
    case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/blue.png"));       break;
    case 3: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/magenta.png"));    break;
    case 4: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/cyan.png"));       break;
    case 5: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/violet.png"));     break;
    case 6: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/babyblue.png"));   break;
    case 7: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/yellow.png"));     break;
    case 8: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/orange.png"));     break;
    case 9: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/white.png"));      break;
    default: qDebug() << "NaN of Line";
    }
}

void Square::hidePixmapOfStaticSquare()
{
    setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Rects/empty.png"));
}

void Square::setAnimationOfStaticSquare()
{
    winAnimation = new Animation(getView(), pos().x(), pos().y());
}

void Square::moveSquare()
{
    if(pos().y() >= squareHeight * 4){
        setPos(pos().x(), getDefY());
    } else {
        setPos(pos().x(), pos().y() + getStepsize());
    }
}
