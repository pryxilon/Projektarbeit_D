#include "gameframeoverlay.h"
#include "globals.h"

GameFrameOverlay::GameFrameOverlay(bool withButton, QGraphicsView *view, int ID)
{
    setView(view);
    setWithButton(withButton);
    setID(ID);

    background = new QGraphicsPixmapItem(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/GameOver/GameOver.png"));
    background->setPos(sideMargin, topMargin);

    text = new QGraphicsTextItem("");
    text->setPos(withButton ? 580 : 700, 310);

    view->scene()->addItem(background);
    view->scene()->addItem(text);

    if(withButton) {
        if(ID == 0) {
            text->setHtml("<div style='color: #FF0000; font-family: Space Age; font-size: 100px'>GAME OVER</div>");
        } else if(ID == 1) {
            text->setPos(590, 310);
            text->setHtml("<div style='color: #FF0000; font-family: Space Age; font-size: 100px'>GEWONNEN</div>");
        }
        restartButton = new Button(view, "Start new Game", 760, 570, 400, 100, false);
    }

    setLayerVisibility(false);
}

QGraphicsView *GameFrameOverlay::getView() const
{
    return view;
}

void GameFrameOverlay::setView(QGraphicsView *value)
{
    view = value;
}

bool GameFrameOverlay::getWithButton() const
{
    return withButton;
}

void GameFrameOverlay::setWithButton(bool value)
{
    withButton = value;
}

void GameFrameOverlay::setWinHeightText(int amount) {
    htmlText = "<div style='color: #FF0000; font-family: DELIRIUM NCV; font-size: 100px'>Freispielgewinn: ";
    htmlText += QString::number(amount);
    htmlText += "</div>";
    text->setHtml(htmlText);

    setLayerVisibility(true);
}

void GameFrameOverlay::setLayerVisibility(bool isVisible) {
    background->setVisible(isVisible);
    text->setVisible(isVisible);

    if(withButton)
        restartButton->getProxy()->setVisible(isVisible);
}

int GameFrameOverlay::getID() const
{
    return ID;
}

void GameFrameOverlay::setID(int value)
{
    ID = value;
}
