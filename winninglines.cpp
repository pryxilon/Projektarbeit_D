#include "winninglines.h"
#include "winninglineoutput.h"
#include <QGraphicsView>

WinningLines::WinningLines(QGraphicsView *view)
{
    setBetHeight(100);
    setWinLineCount(4);
    setButtonCounter(0);
    setView(view);
    initializeWinningLineParts();

    for(int i = 0; i < 10; i++) {
        line[i] = 0;
    }
}

QGraphicsView *WinningLines::getView() const
{
    return view;
}

void WinningLines::setView(QGraphicsView *value)
{
    view = value;
}

int WinningLines::getWinLineCount() const
{
    return winLineCount;
}

void WinningLines::setWinLineCount(int value)
{
    winLineCount = value;
}

int WinningLines::getBetHeight() const
{
    return betHeight;
}

void WinningLines::setBetHeight(int value)
{
    betHeight = value;
}

int WinningLines::getButtonCounter() const
{
    return buttonCounter;
}

void WinningLines::setButtonCounter(int value)
{
    buttonCounter = value;
}

void WinningLines::handleWinLineButtonClick() {
    switch(buttonCounter) {
    case 0: setButtonCounter(1); break;
    case 1: setButtonCounter(0); break;
    //case 2: setButtonCounter(3); break;
    //case 3: setButtonCounter(0); break;
    }

    changeNumberOfWinningLines();
}

void WinningLines::changeNumberOfWinningLines() {
    switch(buttonCounter) {
    case 0: winLineCount = 4; break;
    case 1: winLineCount = 9; break;
    //case 2: winLineCount = 6; break;
    //case 3: winLineCount = 8; break;
    default: winLineCount = 2; break;
    }
}

void WinningLines::initializeWinningLineParts() {
    for(int i = 0; i <= 9; i++) {
        WinLine[i] = new WinningLineOutput(i, view);
    }
}

void WinningLines::checkWinnings(Square *shownSquares[5][3], int count, int sq[5][2], int betHeight) {
    setBetHeight(betHeight);

    for(int i = 0; i < 3; i++) {
        checkHorizontalWinLine(shownSquares, i);
    }

    if(winLineCount > 2) {
        checkDiagonalWinLine(shownSquares, 3);
        checkDiagonalWinLine(shownSquares, 4);

        if(winLineCount > 4) {
            checkBigWWinLine(shownSquares, 5);
            checkBigWWinLine(shownSquares, 6);

            if(winLineCount > 6) {
                checkSmallWWinLine(shownSquares, 7);
                checkSmallWWinLine(shownSquares, 8);
            }
        }
    }

    if(count > 2) {
        WinLine[9]->outputRectsOfWarpholes(count, sq);
    }
}

void WinningLines::checkHorizontalWinLine(Square *shownSquares[5][3], int i) {
    int type0 = shownSquares[0][i]->getType();
    int type1 = shownSquares[1][i]->getType();
    int type2 = shownSquares[2][i]->getType();
    int type3 = shownSquares[3][i]->getType();
    int type4 = shownSquares[4][i]->getType();
    checkWinningLines(type0, type1, type2, type3, type4, i);

    if(line[i] != 0) {
        WinLine[i]->outputWinningLine(winLineType[i], line[i], betHeight);
    }
}

void WinningLines::checkDiagonalWinLine(Square *shownSquares[5][3], int i) {
    int type0 = shownSquares[0][(i == 3 ? 0 : 2)]->getType();
    int type1 = shownSquares[1][1]->getType();
    int type2 = shownSquares[2][(i == 3 ? 2 : 0)]->getType();
    int type3 = shownSquares[3][1]->getType();
    int type4 = shownSquares[4][(i == 3 ? 0 : 2)]->getType();

    checkWinningLines(type0, type1, type2, type3, type4, (i == 3 ? 3 : 4));

    if(line[i] != 0) {
        WinLine[i]->outputWinningLine(winLineType[i], line[i], betHeight);
    }
}

void WinningLines::checkBigWWinLine(Square *shownSquares[5][3], int i) {
    int type0 = shownSquares[0][(i == 5 ? 0 : 2)]->getType();
    int type1 = shownSquares[1][(i == 5 ? 2 : 0)]->getType();
    int type2 = shownSquares[2][(i == 5 ? 0 : 2)]->getType();
    int type3 = shownSquares[3][(i == 5 ? 2 : 0)]->getType();
    int type4 = shownSquares[4][(i == 5 ? 0 : 2)]->getType();

    checkWinningLines(type0, type1, type2, type3, type4, (i == 5 ? 5 : 6));

    if(line[i] != 0) {
        WinLine[i]->outputWinningLine(winLineType[i], line[i], betHeight);
    }
}

void WinningLines::checkSmallWWinLine(Square *shownSquares[5][3], int i) {
    int type0 = shownSquares[0][(i == 7 ? 0 : 2)]->getType();
    int type1 = shownSquares[1][1]->getType();
    int type2 = shownSquares[2][(i == 7 ? 0 : 2)]->getType();
    int type3 = shownSquares[3][1]->getType();
    int type4 = shownSquares[4][(i == 7 ? 0 : 2)]->getType();

    checkWinningLines(type0, type1, type2, type3, type4, (i == 7 ? 7 : 8));

    if(line[i] != 0) {
        WinLine[i]->outputWinningLine(winLineType[i], line[i], betHeight);
    }
}

void WinningLines::checkWinningLines(int type0, int type1, int type2, int type3, int type4, int winLineNumber)
{
    line[winLineNumber] = 0;
    if((type0 == type1) || (type0 == 4) || (type1 == 4)) {
        if(type0 <= 4 && type1 <= 4 && type0 != type2 && type1 != type2 && !(type2 == 4)) {
            line[winLineNumber] = 2;
            if(type0 == 4) {
                winLineType[winLineNumber] = type1;
            } else {
                winLineType[winLineNumber] = type0;
            }
        }
        if(type0 == 4 && type1 == 4) {
            line[winLineNumber] = 3;

            if(type3 == 4 || type2 == type3 || type2 == 4) {
                line[winLineNumber] = 4;
                if(type4 == 4 || type2 == type4 || type3 == type4 || type2 == 4 || type3 == 4) {
                    line[winLineNumber] = 5;
                }
            }
        }

        if(type1 == type2 || (type2 == 4) || (type0 == type2 && type1 == 4)){
            line[winLineNumber] = 3;
            if(type3 == 4 || type0 == type3 || type1 == type3 || type2 == type3) {
                line[winLineNumber] = 4;
                if(type4 == 4 || type0 == type4 || type1 == type4 || type2 == type4 || type3 == type4) {
                    line[winLineNumber] = 5;
                }
            }
        }
    }

    if(type0 != 4){
        winLineType[winLineNumber] = type0;
    } else if(type1 != 4) {
        winLineType[winLineNumber] = type1;
    } else if(type2 != 4) {
        winLineType[winLineNumber] = type2;
    } else if(type3 != 4) {
        winLineType[winLineNumber] = type3;
    } else if(type4 != 4) {
        winLineType[winLineNumber] = type4;
    } else {
        winLineType[winLineNumber] = 4;
    }
}

void WinningLines::outputFreeSpinSquares(Square *shownSquares[5][3]) {
    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < 3; i++) {
            if(shownSquares[j][i]->getType() == 4) {
                WinLine[i]->staticSquares[j]->setPixmapOfStaticSquare(9);
            }
        }
    }
}

void WinningLines::hideWinningLines() {
    for(int i = 0; i <= 9; i++) {
        WinLine[i]->hideWinningLines(line[i]);
    }
}

void WinningLines::setWinningLinesToZero()
{
    for(int i = 0; i < 10; i++) {
        line[i] = 0;
    }
}
