#include "winninglineoutput.h"
#include "slot.h"
#include "globals.h"

WinningLineOutput::WinningLineOutput(int ID, QGraphicsView *view)
{
    setID(ID);
    setNameById();
    setView(view);
    initializeWinLine();
    winRect = new WinningLineRect(ID, view);
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
        parts[i] = new WinningLineConnecter(i * 3 + ID, 0, ID);
        view->scene()->addItem(parts[i]);
    }

    for(int i = 0; i < 5; i++) {
        staticSquares[i] = new Square(sideMargin + i * squareWidth + i * separatorWidth, topMargin + ID * squareHeight, view, i);
        view->scene()->addItem(staticSquares[i]);
    }

}

void WinningLineOutput::outputDiagonalWinline131() {
    parts[0] = new WinningLineConnecter(0, 1, ID);
    parts[1] = new WinningLineConnecter(3, 1, ID);
    parts[2] = new WinningLineConnecter(5, 2, ID);
    parts[3] = new WinningLineConnecter(6, 2, ID);

    staticSquares[0] = new Square(sideMargin + 0 * squareWidth + 0 * separatorWidth, topMargin + 0 * squareHeight, view, 0);
    staticSquares[1] = new Square(sideMargin + 1 * squareWidth + 1 * separatorWidth, topMargin + 1 * squareHeight, view, 1);
    staticSquares[2] = new Square(sideMargin + 2 * squareWidth + 2 * separatorWidth, topMargin + 2 * squareHeight, view, 2);
    staticSquares[3] = new Square(sideMargin + 3 * squareWidth + 3 * separatorWidth, topMargin + 1 * squareHeight, view, 3);
    staticSquares[4] = new Square(sideMargin + 4 * squareWidth + 4 * separatorWidth, topMargin + 0 * squareHeight, view, 4);

    addPartsToScene();
}

void WinningLineOutput::outputDiagonalWinline313() {
    parts[0] = new WinningLineConnecter(1, 2, ID);
    parts[1] = new WinningLineConnecter(2, 2, ID);
    parts[2] = new WinningLineConnecter(4, 1, ID);
    parts[3] = new WinningLineConnecter(7, 1, ID);

    staticSquares[0] = new Square(sideMargin + 0 * squareWidth + 0 * separatorWidth, topMargin + 2 * squareHeight, view, 0);
    staticSquares[1] = new Square(sideMargin + 1 * squareWidth + 1 * separatorWidth, topMargin + 1 * squareHeight, view, 1);
    staticSquares[2] = new Square(sideMargin + 2 * squareWidth + 2 * separatorWidth, topMargin + 0 * squareHeight, view, 2);
    staticSquares[3] = new Square(sideMargin + 3 * squareWidth + 3 * separatorWidth, topMargin + 1 * squareHeight, view, 3);
    staticSquares[4] = new Square(sideMargin + 4 * squareWidth + 4 * separatorWidth, topMargin + 2 * squareHeight, view, 4);

    addPartsToScene();
}

void WinningLineOutput::outputBigWUpper() {
    for(int i = 0; i < 4; i++) {
        parts[i] = new WinningLineConnecter(i, (i % 2 == 0 ? 4 : 3), ID);
    }
    parts[0] = new WinningLineConnecter(0, 4, ID);
    parts[1] = new WinningLineConnecter(1, 3, ID);
    parts[2] = new WinningLineConnecter(2, 4, ID);
    parts[3] = new WinningLineConnecter(3, 3, ID);

    for(int i = 0; i < 5; i++) {
        staticSquares[i] = new Square(sideMargin + i * squareWidth + i * separatorWidth, topMargin + (i % 2 == 0 ? 0 : 2) * squareHeight, view, i);
    }

    addPartsToScene();
}

void WinningLineOutput::outputBigWLower() {
    for(int i = 0; i < 4; i++) {
        parts[i] = new WinningLineConnecter(i, (i % 2 == 0 ? 3 : 4), ID);
    }

    for(int i = 0; i < 5; i++) {
        staticSquares[i] = new Square(sideMargin + i * squareWidth + i * separatorWidth, topMargin + (i % 2 == 0 ? 2 : 0) * squareHeight, view, i);
    }

    addPartsToScene();
}

void WinningLineOutput::outputSmallWUpper() {
    for(int i = 0; i < 4; i++) {
        parts[i] = new WinningLineConnecter(i * 2, (i % 2 == 0 ? 1 : 2), ID);
    }

    for(int i = 0; i < 5; i++) {
        staticSquares[i] = new Square(sideMargin + i * squareWidth + i * separatorWidth, topMargin + (i % 2 == 0 ? 0 : 1) * squareHeight, view, i);
    }

    addPartsToScene();
}

void WinningLineOutput::outputSmallWLower() {
    for(int i = 0; i < 4; i++) {
        parts[i] = new WinningLineConnecter(i * 2 + 1, (i % 2 == 0 ? 2 : 1), ID);
    }
    parts[0] = new WinningLineConnecter(1, 2, ID);
    parts[1] = new WinningLineConnecter(3, 1, ID);
    parts[2] = new WinningLineConnecter(5, 2, ID);
    parts[3] = new WinningLineConnecter(7, 1, ID);

    for(int i = 0; i < 5; i++) {
        staticSquares[i] = new Square(sideMargin + i * squareWidth + i * separatorWidth, topMargin + (i % 2 == 0 ? 2 : 1) * squareHeight, view, i);
    }

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

WinningLineRect *WinningLineOutput::getWinRect() const
{
    return winRect;
}

void WinningLineOutput::setWinRect(WinningLineRect *value)
{
    winRect = value;
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

void WinningLineOutput::outputWinningLine(int type, int length) {
    if(length != 0){
        staticSquares[0]->setPixmapOfStaticSquare(ID);
        winRect->displayRect(type, length);
        parts[0]->setVisible(true);
        staticSquares[1]->setPixmapOfStaticSquare(ID);
        if(length == 3){
            parts[1]->setVisible(true);
            staticSquares[2]->setPixmapOfStaticSquare(ID);
        }
        if(length == 4) {
            for(int i = 1; i < 4; i++) {
                parts[i]->setVisible(true);
                staticSquares[i+1]->setPixmapOfStaticSquare(ID);
            }
        }
        if(length == 5) {
            for(int i = 1; i < 5; i++) {
                parts[i]->setVisible(true);
                staticSquares[i+1]->setPixmapOfStaticSquare(ID);
            }
        }
    }
}

void WinningLineOutput::hideWinningLines(int win) {
    for(int j = 0; j < 4; j++) {
        parts[j]->setVisible(false);;
    }
    for(int j = 0; j < 5; j++) {
        staticSquares[j]->hidePixmapOfStaticSquare();
    }
    if(win != 0) {
        winRect->hideRect();
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
