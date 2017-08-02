#include "winninglineconnecter.h"
#include "globals.h"
#include <QDebug>
#include <QGraphicsPixmapItem>

WinningLineConnecter::WinningLineConnecter(int ID, int type, int parentalId)
{
    setType(type);
    setID(ID);
    setParentalId(parentalId);
    initialize(ID, type);
    setupPixmap();
    setVisible(false);
}

void WinningLineConnecter::initialize(int ID, int type) {
    switch(type){
    case 0: setupPixmap(); setHeight(10); setPositionEven(ID); break;
    case 1: setupPixmap(); setHeight(40); setPositionDiagonal(ID); break;
    case 2: setupPixmap(); setHeight(40); setPositionDiagonal(ID); break;
    case 3: setupPixmap(); setHeight(260); setPositionBigW(ID); break;
    case 4: setupPixmap(); setHeight(260); setPositionBigW(ID); break;
    case 5: setupPixmap(); setHeight(40); setPositionDiagonal(ID); break;
    case 6: setupPixmap(); setHeight(40); setPositionDiagonal(ID); break;
    default: setupPixmap(); setHeight(0); setPos(0, 0); break;
    }
}

void WinningLineConnecter::setupPixmap() {
    switch(parentalId){
    case 0: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Straight/red1.png")); break;
    case 1: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Straight/green1.png")); break;
    case 2: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Straight/blue1.png")); break;
    case 3: (ID < 4) ? setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Small/down-magenta1.png")) : setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Small/up-magenta1.png")); break;
    case 4: (ID < 4) ? setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Small/up-cyan1.png")) : setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Small/down-cyan1.png")); break;
    case 5: (ID % 2 == 0) ? setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Big/down-violet.png")) : setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Big/up-violet.png")); break;
    case 6: (ID % 2 == 0) ? setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Big/up-babyblue.png")) : setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Big/down-babyblue.png")); break;
    case 7: (ID % 2 == 0) ? setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Small/down-yellow.png")) : setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Big/up-yellow.png")); break;
    case 8: (ID % 2 == 0) ? setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Small/up-orange.png")) : setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Big/down-orange.png")); break;
    case 9: /*setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/small-down.png")); */ break;
    default: setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/winlines/Straight/red.png")); break;
    }
}

int WinningLineConnecter::getParentalId() const
{
    return parentalId;
}

void WinningLineConnecter::setParentalId(int value)
{
    parentalId = value;
}

void WinningLineConnecter::setPositionEven(int ID) {
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

void WinningLineConnecter::setPositionDiagonal(int ID) {
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

void WinningLineConnecter::setPositionBigW(int ID) {
    switch(ID) {
    case 0: setPos(sideMargin + squareWidth, topMargin + squareHeight - 10); break;
    case 1: setPos(sideMargin + 2 * squareWidth + separatorWidth, topMargin + squareHeight - 10); break;
    case 2: setPos(sideMargin + 3 * squareWidth + 2 * separatorWidth, topMargin + squareHeight - 10); break;
    case 3: setPos(sideMargin + 4 * squareWidth + 3 * separatorWidth, topMargin + squareHeight - 10); break;
    default: qDebug() << "default SetPosWBig"; break;
    }
}

int WinningLineConnecter::getHeight() const
{
    return height;
}

void WinningLineConnecter::setHeight(int value)
{
    height = value;
}

int WinningLineConnecter::getType() const
{
    return type;
}

void WinningLineConnecter::setType(int value)
{
    type = value;
}

int WinningLineConnecter::getID() const
{
    return ID;
}

void WinningLineConnecter::setID(int value)
{
    ID = value;
}
