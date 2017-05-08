#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QLabel>
#include <QMediaPlayer>
#include <QMovie>
#include "slot.h"

class GameFrame: public QGraphicsRectItem {
public:
    GameFrame();
    GameFrame(QGraphicsView *, int[6]);

    // Setter und Getter
    void setView(QGraphicsView *);
    QGraphicsView * getView();
    QMovie *getMovie() const;
    void setMovie(QMovie *value);
    QLabel *getWarpHoleLabel() const;
    void setWarpHoleLabel(QLabel *value);
    qint64 getCurrentTime() const;
    void setCurrentTime(const qint64 &value);
    bool getVideoIsRunning() const;
    void setVideoIsRunning(bool value);
    QMediaPlayer *getVideoMusic() const;
    void setVideoMusic(QMediaPlayer *value);
    QMediaPlayer *getClickSound() const;
    void setClickSound(QMediaPlayer *value);

    void setSlots(Slot *, int);
    int setMaxSpinsFirstSlot();
    int setAddSpinsOtherSlots();
    int getFreeSpin() const;
    void setFreeSpin(int);

    // Funktionen
    void initializeSlots(int[6]);
    void gameFrameSlotCycle();
    void raiseFreeSpins();
    void highlightWinningLines();
    void dehighlightWinningLines();
    void setWinningLinesToZero();
    void checkShowingSquares();
    void checkForWinningLines(int);
    void playVideoFreeSpin();
    void hideVideoFreeSpin();
    void playClickSound();
    void stopClickSound();

    // public Variables
    Slot * slot[5];
    int line[5];

private:
    QGraphicsView * view;
    Square * shownSquares[5][3];
    int freeSpin = 0;
    QMovie * movie;
    QLabel * warpHoleLabel;
    qint64 currentTime;
    QGraphicsProxyWidget * proxyVid;
    bool videoIsRunning = false;
    QMediaPlayer * videoMusic;
    QMediaPlayer * clickSound;
};

#endif // GAMEFRAME_H
