#include "borderpart.h"
#include "globals.h"
#include <QBrush>
#include <QDebug>


Borderpart::Borderpart()
{

}

Borderpart::Borderpart(int i, bool isFrame)
{
    setID(i);
    setIsFrame(isFrame);
    setupPixmap();
}

int Borderpart::getID() const
{
    return ID;
}

void Borderpart::setID(int value)
{
    ID = value;
}

bool Borderpart::getIsFrame() const
{
    return isFrame;
}

void Borderpart::setIsFrame(bool value)
{
    isFrame = value;
}

void Borderpart::setupPixmap() {
    if(!isFrame) {
        switch(ID) {
        case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Backgroundimage/Header.png")); setPos(0, 0);                                                          break;
        case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Backgroundimage/Left.png"));   setPos(0, topMargin);                                                  break;
        case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Backgroundimage/Right.png"));  setPos(sideMargin + squareWidth * 5 + separatorWidth * 4, topMargin);  break;
        case 3: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Backgroundimage/Bottom.png")); setPos(0, topMargin + squareHeight * 3);                               break;
        }
    } else {
        switch(ID) {
        case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Border/upper2.png"));          setPos(sideMargin - frameBorderWidth, topMargin - frameBorderWidth);   break;
        case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Border/sides.png"));           setPos(sideMargin - frameBorderWidth, topMargin);                      break;
        case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Border/rightside.png"));       setPos(sideMargin + squareWidth * 5 + separatorWidth * 4, topMargin);  break;
        case 3: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Border/lower2.png"));          setPos(sideMargin - frameBorderWidth, topMargin + squareWidth * 3);    break;
        }
    }
}
