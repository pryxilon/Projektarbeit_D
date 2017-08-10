#ifndef WINNINGLINES_H
#define WINNINGLINES_H

#include "square.h"
#include "winninglineoutput.h"



class WinningLines: public Square
{
public:
    WinningLines();
    WinningLines(QGraphicsView*);
    QGraphicsView *getView() const;
    void setView(QGraphicsView *);
    int  getWinLineCount() const;
    void setWinLineCount(int);
    int  getBetHeight() const;
    void setBetHeight(int);
    int  getButtonCounter() const;
    void setButtonCounter(int);

    void handleWinLineButtonClick();
    void changeNumberOfWinningLines();
    void initializeWinningLineParts();

    void checkWinnings(Square*[5][3], int, int[5][2], int);
    void checkHorizontalWinLine(Square*[5][3], int);
    void checkDiagonalWinLine(Square*[5][3], int);
    void checkBigWWinLine(Square*[5][3], int);
    void checkSmallWWinLine(Square*[5][3], int);

    void checkWinningLines(int, int, int, int, int, int);
    void outputFreeSpinSquares(Square *shownSquares[5][3]);
    void hideWinningLines();
    void setWinningLinesToZero();

    //public variables
    int line[10];
    int winLineType[10];
    WinningLineOutput * WinLine[10];

private:
    QGraphicsView *view;
    int winLineCount;
    int betHeight;
    int buttonCounter;
};

#endif // WINNINGLINE_H
