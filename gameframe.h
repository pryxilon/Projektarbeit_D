#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QLabel>
#include <QMediaPlayer>
#include <QMovie>
#include "slot.h"
#include "winninglines.h"

class GameFrame: public QGraphicsRectItem {
public:
    GameFrame();
    GameFrame(QGraphicsView *, int[6]);

    // Funktionen
    void initializeSlots(int[6]);
    void gameFrameSlotCycle();
    void raiseFreeSpins();
    void highlightWinningLines();
    void dehighlightWinningLines();
    void setWinningLinesToZero();
    void checkShowingSquares();
    void checkForWinningLines(int);
    void resetPlayAndSetGame();
    void playVideoFreeSpin();
    void hideVideoFreeSpin();

    // Setter und Getter
    void setView(QGraphicsView *);
    QGraphicsView * getView();
    QMovie *getMovie() const;
    void setMovie(QMovie *value);
    QLabel *getWarpHoleLabel() const;
    void setWarpHoleLabel(QLabel *value);
    bool getVideoIsRunning() const;
    void setVideoIsRunning(bool value);
    QMediaPlayer *getVideoMusic() const;
    void setVideoMusic(QMediaPlayer *value);
    WinningLines *getWinLines() const;
    void setWinLines(WinningLines *value);

    void setSlots(Slot *, int);
    int setMaxSpinsFirstSlot();
    int setAddSpinsOtherSlots();
    int getFreeSpin() const;
    void setFreeSpin(int);

    // public Variables
    Slot * slot[10];
    int line[10];
    int winLineType[10];

    qint64 getCurrentTimeVideo() const;
    void setCurrentTimeVideo(const qint64 &value);

    bool getPlayerWin() const;
    void setPlayerWin(bool value);

private:
    QGraphicsView * view;
    Square * shownSquares[5][3];
    int freeSpin = 0;
    QMovie * movie;
    QLabel * warpHoleLabel;
    qint64 currentTimeVideo;
    QGraphicsProxyWidget * proxyVid;
    bool videoIsRunning = false;
    QMediaPlayer * videoMusic;
    Music * winSound;
    bool playerWin;

    WinningLines *WinLines;
};

#endif // GAMEFRAME_H
