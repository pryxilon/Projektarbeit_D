#ifndef WINNINGLINEOUTPUT_H
#define WINNINGLINEOUTPUT_H

#include "slot.h"
#include "winninglinepart.h"

#include <QGraphicsRectItem>
#include <QGraphicsView>



class WinningLineOutput: public QGraphicsPixmapItem
{
public:
    WinningLineOutput(int, QGraphicsView*);

    void outputHorizontalWinline();
    void outputDiagonalWinline131();
    void outputDiagonalWinline313();
    void outputBigWUpper();
    void outputBigWLower();
    void outputSmallWUpper();
    void outputSmallWLower();

    int getID() const;
    void setID(int value);

    char *getName() const;
    void setName(char *value);
    void setNameById();

    // public variables
    WinningLinePart * parts[4];

    void initializeWinLine();
    void outputHorizontalWinningLine(int length);
    void outputDiagonalWinningLine(int length);
    void outputBigWLine(int length);
    void outputSmallWLine(int length);
    void hideWinningLines();



    QGraphicsView *getView() const;
    void setView(QGraphicsView *value);
    Slot * slot[5];
    Square *staticSquares[5];

    void addPartsToScene();

private:
    int mainNumbers[6];
    int ID;
    char *name;
    QGraphicsView * view;
};

#endif // WINNINGLINEOUTPUT_H
