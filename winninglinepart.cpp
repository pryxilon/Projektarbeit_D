#include "winninglinepart.h"
#include "globals.h"
#include <QDebug>
#include <QGraphicsPixmapItem>

WinningLinePart::WinningLinePart(int ID, int type)
{
    setType(type);
    setID(ID);
    initialize(ID, type);
    //qDebug() << "Part";

}

void WinningLinePart::initialize(int ID, int type) {
    switch(type){
    case 0: setupPixmap(type); setHeight(10); setPositionEven(ID); break;
    case 1: setupPixmap(type); setHeight(20); setPositionDiagonal(ID); break;
    case 2: setupPixmap(type); setHeight(20); setPositionDiagonal(ID); break;
    case 3: setupPixmap(type); setHeight(260); setPositionBigW(ID); break;
    case 4: setupPixmap(type); setHeight(260); setPositionBigW(ID); break;
    case 5: setupPixmap(type); setHeight(20); setPositionDiagonal(ID); break;
    case 6: setupPixmap(type); setHeight(20); setPositionDiagonal(ID); break;
    default: setupPixmap(type); setHeight(0); setPos(0, 0); break;
    }
}

void WinningLinePart::setupPixmap(int type) {
    switch(type){
    case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-gerade.png")); break;
    case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-diagonal-down.png")); break;
    case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-diagonal-up.png")); break;
    case 3: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-big-down.png")); break;
    case 4: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-big-up.png")); break;
    case 5: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-small-down.png")); break;
    case 6: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-small-up.png")); break;
    default: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-gerade.png")); break;
    }
}

void WinningLinePart::setupPixmap() {
    switch(type){
    case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-gerade.png")); break;
    case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-diagonal-down.png")); break;
    case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-diagonal-up.png")); break;
    case 3: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-big-down.png")); break;
    case 4: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-big-up.png")); break;
    case 5: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-small-down.png")); break;
    case 6: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-small-up.png")); break;
    default: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-gerade.png")); break;
    }
}

void WinningLinePart::hidePixmap() {
    switch(type){
    case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-gerade-empty.png")); break;
    case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-diagonal-empty.png")); break;
    case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-diagonal-empty.png")); break;
    case 3: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-big-empty.png")); break;
    case 4: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-big-empty.png")); break;
    case 5: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-diagonal-empty.png")); break;
    case 6: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-diagonal-empty.png")); break;
    default: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winline-gerade-empty.png")); break;
    }
}

void WinningLinePart::setPositionEven(int ID) {
    switch(ID) {
    case  0: setPos(sideMargin + squareWidth * 1 + 0 * separatorWidth, topMargin + 0 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  1: setPos(sideMargin + squareWidth * 1 + 0 * separatorWidth, topMargin + 1 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  2: setPos(sideMargin + squareWidth * 1 + 0 * separatorWidth, topMargin + 2 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  3: setPos(sideMargin + squareWidth * 2 + 1 * separatorWidth, topMargin + 0 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  4: setPos(sideMargin + squareWidth * 2 + 1 * separatorWidth, topMargin + 1 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  5: setPos(sideMargin + squareWidth * 2 + 1 * separatorWidth, topMargin + 2 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  6: setPos(sideMargin + squareWidth * 3 + 2 * separatorWidth, topMargin + 0 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  7: setPos(sideMargin + squareWidth * 3 + 2 * separatorWidth, topMargin + 1 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  8: setPos(sideMargin + squareWidth * 3 + 2 * separatorWidth, topMargin + 2 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case  9: setPos(sideMargin + squareWidth * 4 + 3 * separatorWidth, topMargin + 0 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case 10: setPos(sideMargin + squareWidth * 4 + 3 * separatorWidth, topMargin + 1 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    case 11: setPos(sideMargin + squareWidth * 4 + 3 * separatorWidth, topMargin + 2 * squareHeight + squareHeight / 2 - getHeight() / 2); break;
    default: qDebug() << "default SetPosEven"; break;
    }
}

void WinningLinePart::setPositionDiagonal(int ID) {
    switch(ID) {
    case 0: setPos(sideMargin + squareWidth, topMargin + squareHeight - getHeight() / 2); break;
    case 1: setPos(sideMargin + squareWidth, topMargin + 2 * squareHeight - getHeight() / 2); break;
    case 2: setPos(sideMargin + 2 * squareWidth + separatorWidth, topMargin + squareHeight - getHeight() / 2); break;
    case 3: setPos(sideMargin + 2 * squareWidth + separatorWidth, topMargin + 2 * squareHeight - getHeight() / 2); break;
    case 4: setPos(sideMargin + 3 * squareWidth + 2 * separatorWidth, topMargin + squareHeight - getHeight() / 2); break;
    case 5: setPos(sideMargin + 3 * squareWidth + 2 * separatorWidth, topMargin + 2 * squareHeight - getHeight() / 2); break;
    case 6: setPos(sideMargin + 4 * squareWidth + 3 * separatorWidth, topMargin + squareHeight - getHeight() / 2); break;
    case 7: setPos(sideMargin + 4 * squareWidth + 3 * separatorWidth, topMargin + 2 * squareHeight - getHeight() / 2); break;
    default: qDebug() << "default SetPosDiag"; break;
    }
}

void WinningLinePart::setPositionBigW(int ID) {
    switch(ID) {
    case 0: setPos(sideMargin + squareWidth, topMargin + squareHeight - 10); break;
    case 1: setPos(sideMargin + 2 * squareWidth + separatorWidth, topMargin + squareHeight - 10); break;
    case 2: setPos(sideMargin + 3 * squareWidth + 2 * separatorWidth, topMargin + squareHeight - 10); break;
    case 3: setPos(sideMargin + 4 * squareWidth + 3 * separatorWidth, topMargin + squareHeight - 10); break;
    default: qDebug() << "default SetPosWBig"; break;
    }
}

int WinningLinePart::getHeight() const
{
    return height;
}

void WinningLinePart::setHeight(int value)
{
    height = value;
}

int WinningLinePart::getType() const
{
    return type;
}

void WinningLinePart::setType(int value)
{
    type = value;
}

int WinningLinePart::getID() const
{
    return ID;
}

void WinningLinePart::setID(int value)
{
    ID = value;
}
