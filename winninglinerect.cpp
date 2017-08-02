#include "winninglinerect.h"
#include "globals.h"

#include <QDebug>


WinningLineRect::WinningLineRect(int parentalID, QGraphicsView *view)
{
    setView(view);
    view->scene()->addItem(this);
    setX(6);
    setY(0);
    setWidth(40);
    setHeight(40);
    setupRect(parentalID);
    text = new QGraphicsTextItem("");
    text->setPos(sideMargin + 6, topMargin + getY() - 5);
    getView()->scene()->addItem(text);

    setRect(sideMargin, topMargin, getWidth(), getHeight());
    setupRect(parentalID);
    setVisible(false);
}

QGraphicsView *WinningLineRect::getView() const
{
    return view;
}

void WinningLineRect::setView(QGraphicsView *value)
{
    view = value;
}

int WinningLineRect::getWidth() const
{
    return width;
}

void WinningLineRect::setWidth(int value)
{
    width = value;
}

int WinningLineRect::getX() const
{
    return x;
}

void WinningLineRect::setX(int value)
{
    x = value;
}

int WinningLineRect::getY() const
{
    return y;
}

void WinningLineRect::setY(int value)
{
    y = value;
}

QGraphicsTextItem *WinningLineRect::getText() const
{
    return text;
}

void WinningLineRect::setText(QGraphicsTextItem *value)
{
    text = value;
}

int WinningLineRect::getHeight() const
{
    return height;
}

void WinningLineRect::setHeight(int value)
{
    height = value;
}

void WinningLineRect::setupRect(int lineID) {
    switch(lineID) {
    case 0: setY(squareHeight / 2 - height / 2); setPos(getX(), getY()); setBrush(QBrush(Qt::red)); break;
    case 1: setY(squareHeight + squareHeight / 2 - height / 2); setPos(getX(), getY()); setBrush(QBrush(Qt::green)); break;
    case 2: setY(2 * squareHeight + squareHeight / 2 - height / 2); setPos(getX(), getY()); setBrush(QBrush(Qt::blue)); break;
    case 3: setY(5); setPos(getX(), getY()); setBrush(QBrush(Qt::magenta)); break;
    case 4: setY(3 * squareHeight - height - 7); setPos(getX(), getY()); setBrush(QBrush(Qt::cyan)); break;
    case 5: setY(5 + this->height + 10); setPos(getX(), getY()); setBrush(QBrush(Qt::gray)); break;
    case 6: setY(- 6 + 3 * squareHeight - this->height - 10); setPos(getX(), getY()); setBrush(QBrush(Qt::white)); break;
    case 7: setY(squareHeight - 5 - this->height); setPos(getX(), getY()); setBrush(QBrush(Qt::black)); break;
    case 8: setY(2 * squareHeight + 5 + this->height); setPos(getX(), getY()); setBrush(QBrush(Qt::red)); break;
    case 9: setY(5 + this->height); setPos(getX(), getY()); setBrush(QBrush(Qt::red)); break;
    default: setY(5 + this->height * 2); setPos(getX(), getY()); setBrush(QBrush(Qt::white)); break;
    }
}

void WinningLineRect::displayRect(int type, int length) {
    htmlText = "<div style='color: #FFFFFF; font-family: DELIRIUM NCV; font-size: 40px'>";
    htmlText += QString::number(100 * getSymbolValue(type, length));
    htmlText += "</div>";
    qDebug() << htmlText;
    text->setHtml(htmlText);
    text->setVisible(true);
    this->setVisible(true);
}

void WinningLineRect::hideRect() {
    text->setVisible(false);
    this->setVisible(false);
}

int WinningLineRect::getSymbolValue(int type, int length)
{
    switch(type) {
    case 0:
        switch(length) {
        case 2: return 1;
        case 3: return 6;
        case 4: return 20;
        case 5: return 150;
        default: return 0;
        }
    case 1:
        switch(length) {
        case 2: return 1;
        case 3: return 6;
        case 4: return 20;
        case 5: return 150;
        default: return 0;
        }
    case 2:
        switch(length) {
        case 2: return 1;
        case 3: return 8;
        case 4: return 80;
        case 5: return 400;
        default: return 0;
        }
    case 3:
        switch(length) {
        case 2: return 2;
        case 3: return 20;
        case 4: return 200;
        case 5: return 1000;
        default: return 0;
        }
    case 4:
        switch(length) {
        case 3: return 2;
        case 4: return 20;
        case 5: return 200;
        default: return 0;
        }
    case 5:
        switch(length) {
        case 3: return 1;
        case 4: return 5;
        case 5: return 20;
        default: return 0;
        }
    case 6:
        switch(length) {
        case 3: return 1;
        case 4: return 5;
        case 5: return 20;
        default: return 0;
        }
    case 7:
        switch(length) {
        case 3: return 1;
        case 4: return 5;
        case 5: return 20;
        default: return 0;
        }
    case 8: switch(length) {
        case 3: return 1;
        case 4: return 8;
        case 5: return 30;
        default: return 0;
        }
    case 9:
        switch(length) {
        case 3: return 1;
        case 4: return 8;
        case 5: return 30;
        default: return 0;
        }
    default: return 0;
    }
}
