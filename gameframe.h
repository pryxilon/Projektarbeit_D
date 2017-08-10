#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QGraphicsView>
#include <QPushButton>
#include <QTime>
#include "slot.h"
#include "winninglines.h"
#include "gameframeoverlay.h"

class GameFrame: public QGraphicsRectItem {
public:
    GameFrame();
    GameFrame(QGraphicsView *);

    // Setter und Getter
    void setView(QGraphicsView *);
    QGraphicsView * getView();
    int  getX() const;
    void setX(int);
    int  getY() const;
    void setY(int);
    int  getWidth() const;
    void setWidth(int);
    int  getHeight() const;
    void setHeight(int);
    int  getFreeSpin() const;
    void setFreeSpin(int);
    Animation getFreeSpinVideo() const;
    void setFreeSpinVideo(const Animation &);
    bool getPlayerWin() const;
    void setPlayerWin(bool);
    WinningLines *getWinLines() const;
    void setWinLines(WinningLines *);
    Music *getNoCredit() const;
    void setNoCredit(Music *value);

    void setSlots(Slot *, int);
    int  setMaxSpinsFirstSlot();
    int  setAddSpinsOtherSlots();

    // Funktionen
    void initializeSlots();
    void resetPlayAndSetGame(int);
    void gameFrameSlotCycle();
    void checkShowingSquares(int);
    void raiseFreeSpins();
    void wait(int);

    // public Variables
    Slot *slot[5];
    int line[10];
    int winLineType[10];

    GameFrameOverlay *gameOver;
    GameFrameOverlay *freeSpinOverlay;


private:
    QGraphicsView * view;
    int x;
    int y;
    int width;
    int height;
    int freeSpin = 0;
    bool playerWin;
    Square *shownSquares[5][3];
    Music *winSound;
    Music *warpSound;
    Music *noCredit;
    Animation freeSpinVideo;
    WinningLines *WinLines;
    QTime dieTime;
};

#endif // GAMEFRAME_H
