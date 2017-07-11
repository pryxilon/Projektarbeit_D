#ifndef WINNINGLINES_H
#define WINNINGLINES_H

#include "square.h"
#include "winninglineoutput.h"



class WinningLines: public Square
{
public:
    WinningLines();
    WinningLines(QGraphicsView*);
    int getLength() const;
    void setLength(int value);
    int getType() const;
    void setType(int value);
    QGraphicsView *getView() const;
    void setView(QGraphicsView *value);

    void setHorizontalWinLine(int line);
    int getWinLineCount() const;
    void setWinLineCount(int value);
    int getButtonCounter() const;
    void setButtonCounter(int value);
    void setWinningLinesToZero();

    void initializeWinningLineParts();
    void handleWinLineButtonClick();
    void changeNumberOfWinningLines();
    void checkWinnings(Square*[5][3]);
    void checkHorizontalWinLine(Square*[5][3], int i);
    void checkDiagonalWinLine(Square*[5][3], int i);
    void checkBigWWinLine(Square*[5][3], int i);
    void checkSmallWWinLine(Square*[5][3], int i);

    void checkWinningLines(int, int, int, int, int, int);
    void hideWinningLines();

    //public variables
    int line[10];
    int winLineType[10];

    WinningLineOutput * WinLine[10];

    void outputFreeSpinSquares(Square *shownSquares[5][3]);
private:
    int length;
    int type;
    int winLineCount;
    int buttonCounter;
    QGraphicsView *view;
};

#endif // WINNINGLINE_H
