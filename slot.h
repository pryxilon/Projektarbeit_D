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
    Slot(int x, int y, QGraphicsView *view, int id);

    // getters and setters
    void setView(QGraphicsView *);
    QGraphicsView * getView();
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);
    void setID(int);
    int getID();
    void setAnzahlSquares(int);
    int getAnzahlSquares();
    bool getFinished() const;
    void setFinished(bool value);
    Music *getStopMusic() const;
    void setStopMusic(Music *value);

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
    int x;
    int y;
    int width;
    int height;
    int countSquares;
    QGraphicsView * view;
    int id;
    int anzahlSquares;
    int spawningY;
    int counter = 0;
    int counterPic = 0;
    int counterNum = 0;
    bool finished = false;
    Music * stopMusic;
};

#endif // SLOT_H
