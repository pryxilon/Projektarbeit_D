#include "winninglineoutput.h"
#include "slot.h"
#include "globals.h"

WinningLineOutput::WinningLineOutput(int ID, QGraphicsView *view)
{
    setID(ID);
    setNameById();
    setView(view);
    initializeWinLine();
}

int WinningLineOutput::getID() const
{
    return ID;
}

void WinningLineOutput::setID(int value)
{
    ID = value;
}

char *WinningLineOutput::getName() const
{
    return name;
}

void WinningLineOutput::setName(char *value)
{
    name = value;
}

void WinningLineOutput::initializeWinLine() {
    switch(ID) {
    case 0: outputHorizontalWinline(); break;
    case 1: outputHorizontalWinline(); break;
    case 2: outputHorizontalWinline(); break;
    case 3: outputDiagonalWinline131(); break;
    case 4: outputDiagonalWinline313(); break;
    case 5: outputBigWUpper(); break;
    case 6: outputBigWLower(); break;
    case 7: outputSmallWUpper(); break;
    case 8: outputSmallWLower(); break;
    default: break;
    }
}

void WinningLineOutput::outputHorizontalWinline() {
    for(int i = 0; i < 4; i++) {
        parts[i] = new WinningLinePart(i * 3 + ID, 0);
        view->scene()->addItem(parts[i]);
    }

    for(int i = 0; i < 5; i++) {
        staticSquares[i] = new Square(sideMargin + i * squareWidth + i * separatorWidth, topMargin + ID * squareHeight, view, i);
        view->scene()->addItem(staticSquares[i]);
    }

}

void WinningLineOutput::outputDiagonalWinline131() {
    parts[0] = new WinningLinePart(0, 1);
    parts[1] = new WinningLinePart(3, 1);
    parts[2] = new WinningLinePart(5, 2);
    parts[3] = new WinningLinePart(6, 2);

    staticSquares[0] = new Square(sideMargin + 0 * squareWidth + 0 * separatorWidth, topMargin + 0 * squareHeight, view, 0);
    staticSquares[1] = new Square(sideMargin + 1 * squareWidth + 1 * separatorWidth, topMargin + 1 * squareHeight, view, 1);
    staticSquares[2] = new Square(sideMargin + 2 * squareWidth + 2 * separatorWidth, topMargin + 2 * squareHeight, view, 2);
    staticSquares[3] = new Square(sideMargin + 3 * squareWidth + 3 * separatorWidth, topMargin + 1 * squareHeight, view, 3);
    staticSquares[4] = new Square(sideMargin + 4 * squareWidth + 4 * separatorWidth, topMargin + 0 * squareHeight, view, 4);


    addPartsToScene();
}

void WinningLineOutput::outputDiagonalWinline313() {
    parts[0] = new WinningLinePart(1, 2);
    parts[1] = new WinningLinePart(2, 2);
    parts[2] = new WinningLinePart(4, 1);
    parts[3] = new WinningLinePart(7, 1);

    staticSquares[0] = new Square(sideMargin + 0 * squareWidth + 0 * separatorWidth, topMargin + 2 * squareHeight, view, 0);
    staticSquares[1] = new Square(sideMargin + 1 * squareWidth + 1 * separatorWidth, topMargin + 1 * squareHeight, view, 1);
    staticSquares[2] = new Square(sideMargin + 2 * squareWidth + 2 * separatorWidth, topMargin + 0 * squareHeight, view, 2);
    staticSquares[3] = new Square(sideMargin + 3 * squareWidth + 3 * separatorWidth, topMargin + 1 * squareHeight, view, 3);
    staticSquares[4] = new Square(sideMargin + 4 * squareWidth + 4 * separatorWidth, topMargin + 2 * squareHeight, view, 4);

    addPartsToScene();
}

void WinningLineOutput::outputBigWUpper() {
    parts[0] = new WinningLinePart(0, 4);
    parts[1] = new WinningLinePart(1, 3);
    parts[2] = new WinningLinePart(2, 4);
    parts[3] = new WinningLinePart(3, 3);

    staticSquares[0] = new Square(sideMargin + 0 * squareWidth + 0 * separatorWidth, topMargin + 0 * squareHeight, view, 0);
    staticSquares[1] = new Square(sideMargin + 1 * squareWidth + 1 * separatorWidth, topMargin + 2 * squareHeight, view, 1);
    staticSquares[2] = new Square(sideMargin + 2 * squareWidth + 2 * separatorWidth, topMargin + 0 * squareHeight, view, 2);
    staticSquares[3] = new Square(sideMargin + 3 * squareWidth + 3 * separatorWidth, topMargin + 2 * squareHeight, view, 3);
    staticSquares[4] = new Square(sideMargin + 4 * squareWidth + 4 * separatorWidth, topMargin + 0 * squareHeight, view, 4);

    addPartsToScene();
}

void WinningLineOutput::outputBigWLower() {
    parts[0] = new WinningLinePart(0, 3);
    parts[1] = new WinningLinePart(1, 4);
    parts[2] = new WinningLinePart(2, 3);
    parts[3] = new WinningLinePart(3, 4);

    staticSquares[0] = new Square(sideMargin + 0 * squareWidth + 0 * separatorWidth, topMargin + 2 * squareHeight, view, 0);
    staticSquares[1] = new Square(sideMargin + 1 * squareWidth + 1 * separatorWidth, topMargin + 0 * squareHeight, view, 1);
    staticSquares[2] = new Square(sideMargin + 2 * squareWidth + 2 * separatorWidth, topMargin + 2 * squareHeight, view, 2);
    staticSquares[3] = new Square(sideMargin + 3 * squareWidth + 3 * separatorWidth, topMargin + 0 * squareHeight, view, 3);
    staticSquares[4] = new Square(sideMargin + 4 * squareWidth + 4 * separatorWidth, topMargin + 2 * squareHeight, view, 4);

    addPartsToScene();
}

void WinningLineOutput::outputSmallWUpper() {
    parts[0] = new WinningLinePart(0, 1);
    parts[1] = new WinningLinePart(2, 2);
    parts[2] = new WinningLinePart(4, 1);
    parts[3] = new WinningLinePart(6, 2);

    staticSquares[0] = new Square(sideMargin + 0 * squareWidth + 0 * separatorWidth, topMargin + 0 * squareHeight, view, 0);
    staticSquares[1] = new Square(sideMargin + 1 * squareWidth + 1 * separatorWidth, topMargin + 1 * squareHeight, view, 1);
    staticSquares[2] = new Square(sideMargin + 2 * squareWidth + 2 * separatorWidth, topMargin + 0 * squareHeight, view, 2);
    staticSquares[3] = new Square(sideMargin + 3 * squareWidth + 3 * separatorWidth, topMargin + 1 * squareHeight, view, 3);
    staticSquares[4] = new Square(sideMargin + 4 * squareWidth + 4 * separatorWidth, topMargin + 0 * squareHeight, view, 4);

    addPartsToScene();
}

void WinningLineOutput::outputSmallWLower() {
    parts[0] = new WinningLinePart(1, 2);
    parts[1] = new WinningLinePart(3, 1);
    parts[2] = new WinningLinePart(5, 2);
    parts[3] = new WinningLinePart(7, 1);

    staticSquares[0] = new Square(sideMargin + 0 * squareWidth + 0 * separatorWidth, topMargin + 2 * squareHeight, view, 0);
    staticSquares[1] = new Square(sideMargin + 1 * squareWidth + 1 * separatorWidth, topMargin + 1 * squareHeight, view, 1);
    staticSquares[2] = new Square(sideMargin + 2 * squareWidth + 2 * separatorWidth, topMargin + 2 * squareHeight, view, 2);
    staticSquares[3] = new Square(sideMargin + 3 * squareWidth + 3 * separatorWidth, topMargin + 1 * squareHeight, view, 3);
    staticSquares[4] = new Square(sideMargin + 4 * squareWidth + 4 * separatorWidth, topMargin + 2 * squareHeight, view, 4);

    addPartsToScene();
}

void WinningLineOutput::addPartsToScene() {
    for(int i = 0; i < 5; i++) {
        view->scene()->addItem(staticSquares[i]);
    }
    for(int i = 0; i < 4; i++) {
        view->scene()->addItem(parts[i]);
    }
}

void WinningLineOutput::setNameById() {
    qDebug() << "setNameByID not used atm";
    /*switch(ID) {
    case 0: setName('HorizontalUpper'); break;
    case 1: setName('HorizontalMid'); break;
    case 2: setName('HorizontalLower'); break;
    case 3: setName('DiagonalUpLowUp'); break;
    case 4: setName('DiagonalLowUpLow'); break;
    case 5: setName('BigWUpper'); break;
    case 6: setName('BigWLower'); break;
    case 7: setName('SmallWUpper'); break;
    case 8: setName('SmallWLower'); break;
    }*/
}

void WinningLineOutput::outputHorizontalWinningLine(int length) {
    if(length != 0){
        staticSquares[0]->setPixmapOfStaticSquare(1);
        parts[0]->setupPixmap();
        staticSquares[1]->setPixmapOfStaticSquare(1);
        if(length == 3){
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
        }
        if(length == 4) {
            for(int i = 1; i < 4; i++) {
                parts[i]->setupPixmap();
                staticSquares[i]->setPixmapOfStaticSquare(1);
            }
        }
        if(length == 5) {
            for(int i = 1; i < 5; i++) {
                parts[i]->setupPixmap();
                staticSquares[i]->setPixmapOfStaticSquare(1);
            }
        }
    }
}

void WinningLineOutput::outputDiagonalWinningLine(int length) {
    if(length != 0){
        staticSquares[0]->setPixmapOfStaticSquare(1);
        parts[0]->setupPixmap();
        staticSquares[1]->setPixmapOfStaticSquare(1);
        if(length == 3){
            parts[1]->setupPixmap();
            staticSquares[1]->setPixmapOfStaticSquare(1);
        }
        if(length == 4) {
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
            parts[2]->setupPixmap();
            staticSquares[3]->setPixmapOfStaticSquare(1);
        }
        if(length == 5) {
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
            parts[2]->setupPixmap();
            staticSquares[3]->setPixmapOfStaticSquare(1);
            parts[3]->setupPixmap();
            staticSquares[4]->setPixmapOfStaticSquare(1);
        }
    }
}

void WinningLineOutput::outputBigWLine(int length) {
    if(length != 0){
        staticSquares[0]->setPixmapOfStaticSquare(1);
        parts[0]->setupPixmap();
        staticSquares[1]->setPixmapOfStaticSquare(1);
        if(length == 3){
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
        }
        if(length == 4) {
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
            parts[2]->setupPixmap();
            staticSquares[3]->setPixmapOfStaticSquare(1);
        }
        if(length == 5) {
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
            parts[2]->setupPixmap();
            staticSquares[3]->setPixmapOfStaticSquare(1);
            parts[3]->setupPixmap();
            staticSquares[4]->setPixmapOfStaticSquare(1);
        }
    }
}

void WinningLineOutput::outputSmallWLine(int length) {
    if(length != 0){
        staticSquares[0]->setPixmapOfStaticSquare(1);
        parts[0]->setupPixmap();
        staticSquares[1]->setPixmapOfStaticSquare(1);
        if(length == 3){
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
        }
        if(length == 4) {
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
            parts[2]->setupPixmap();
            staticSquares[3]->setPixmapOfStaticSquare(1);
        }
        if(length == 5) {
            parts[1]->setupPixmap();
            staticSquares[2]->setPixmapOfStaticSquare(1);
            parts[2]->setupPixmap();
            staticSquares[3]->setPixmapOfStaticSquare(1);
            parts[3]->setupPixmap();
            staticSquares[4]->setPixmapOfStaticSquare(1);
        }
    }
}

void WinningLineOutput::hideWinningLines() {
    for(int j = 0; j < 4; j++) {
        parts[j]->hidePixmap();
    }
    for(int j = 0; j < 5; j++) {
        staticSquares[j]->setPixmapOfStaticSquare(0);
    }
}

QGraphicsView *WinningLineOutput::getView() const
{
    return view;
}

void WinningLineOutput::setView(QGraphicsView *value)
{
    view = value;
}
