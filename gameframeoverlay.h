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
    GameFrameOverlay(bool, QGraphicsView *, int);

    QGraphicsView *getView() const;
    void setView(QGraphicsView *);
    bool getWithButton() const;
    void setWithButton(bool );
    int getID() const;
    void setID(int value);

    void setWinHeightText(int);
    void setLayerVisibility(bool);

    // public variables
    Button *restartButton;


private:
    QGraphicsView *view;
    QGraphicsPixmapItem *background;
    QGraphicsTextItem *text;
    bool withButton;
    int ID;
    QString htmlText;
};

#endif // GAMEFRAMEOVERLAY_H
