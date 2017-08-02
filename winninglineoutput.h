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
    WinningLineConnecter * parts[4];

    void initializeWinLine();
    void outputWinningLine(int type, int length);
    void hideWinningLines(int);



    QGraphicsView *getView() const;
    void setView(QGraphicsView *value);
    Slot * slot[5];
    Square *staticSquares[5];

    void addPartsToScene();


    WinningLineRect *getWinRect() const;
    void setWinRect(WinningLineRect *value);

private:
    int ID;
    char *name;
    QGraphicsView * view;
    WinningLineRect *winRect;
};

#endif // WINNINGLINEOUTPUT_H
