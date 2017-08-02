#ifndef SLOT_H
#define SLOT_H

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "music.h"
#include "square.h"

class Slot: public QGraphicsRectItem {
public:
    // Constructors
    Slot();
    Slot(QGraphicsView *);
    Slot(int, int, QRectF, QGraphicsView *, int);

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

    bool getFinished() const;
    void setFinished(bool value);

    Music *getStopMusic() const;
    void setStopMusic(Music *value);

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
    bool finished = false;
    Music * stopMusic;
};

#endif // SLOT_H
