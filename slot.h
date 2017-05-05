#ifndef SLOT_H
#define SLOT_H

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "square.h"

class Slot: public QGraphicsRectItem {
public:
    // Constructors
    Slot();
    Slot(QGraphicsView *);
    Slot(int, int, QRectF, QGraphicsView *, int, int[6]);

    // getters and setters
    void setView(QGraphicsView *);
    QGraphicsView * getView();
    void setID(int);
    int getID();
    void setAnzahlSquares(int);
    int getAnzahlSquares();
    int getSqHeight();

    // Functions
    int setRandomType(int);
    void initSlot();

    int getSpawningY();
    void setSpawningY(int);

    int setRandom(int);
    int setRandomNumbers(int);
    int setRandomPictures(int);
    void slotSquaresMove();

    // Public-Variables
    Square * squares[6];
    Square * staticSquares[3];

private:
    int countSquares;
    QGraphicsView * view;
    int id;
    int anzahlSquares;
    int sqHeight;
    int spawningY;
    int counter = 0;
    int counterPic = 0;
    int counterNum = 0;
};

#endif // SLOT_H
