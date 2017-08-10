#ifndef GAMEFRAMEOVERLAY_H
#define GAMEFRAMEOVERLAY_H

#include "button.h"

#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QPushButton>



class GameFrameOverlay
{
public:
    GameFrameOverlay();
    GameFrameOverlay(bool, QGraphicsView *);

    QGraphicsView *getView() const;
    void setView(QGraphicsView *);
    bool getWithButton() const;
    void setWithButton(bool );

    void setWinHeightText(int);
    void setLayerVisibility(bool);

    // public variables
    Button *gameOverButton;

private:
    QGraphicsView *view;
    QGraphicsPixmapItem *background;
    QGraphicsTextItem *text;
    bool withButton;
    QString htmlText;
};

#endif // GAMEFRAMEOVERLAY_H
