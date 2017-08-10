#ifndef WINNINGLINEOUTPUT_H
#define WINNINGLINEOUTPUT_H

#include "slot.h"
#include "winninglineconnecter.h"
#include "winninglinerect.h"

#include <QGraphicsRectItem>
#include <QGraphicsView>



class WinningLineOutput: public QGraphicsPixmapItem
{
public:
    WinningLineOutput(int, QGraphicsView*);

    QGraphicsView *getView() const;
    void setView(QGraphicsView *);
    int getID() const;
    void setID(int);
    WinningLineRect *getWinRect() const;
    void setWinRect(WinningLineRect *);

    void initializeWinLine();
    void outputHorizontalWinline();
    void outputDiagonalWinline131();
    void outputDiagonalWinline313();
    void outputBigWUpper();
    void outputBigWLower();
    void outputSmallWUpper();
    void outputSmallWLower();
    void setRectsOfWarpholes();
    void outputWinningLine(int, int, int);
    void outputRectsOfWarpholes(int, int[5][2]);
    void hideWinningLines(int);
    void addPartsToScene();

    // public variables
    WinningLineConnecter * parts[4];
    Slot * slot[5];
    Square *staticSquares[5];

private:
    int ID;
    QGraphicsView * view;
    WinningLineRect *winRect;
};

#endif // WINNINGLINEOUTPUT_H
