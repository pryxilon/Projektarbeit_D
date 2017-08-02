#include "gameframe.h"
#include "slot.h"
#include "separator.h"
#include "globals.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QEventLoop>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

GameFrame::GameFrame(QGraphicsView * view)
{
    setRect((view->width() - 5 * squareWidth - 4 * separatorWidth) / 2, topMargin, 5 * squareWidth + 4 * separatorWidth, squareWidth * 3);
    setView(view);
    setPlayerWin(false);

    initializeSlots();

    WinLines = new WinningLines(view);

    winSound = new Music();
    winSound->getSound()->setMedia(QUrl("C:/Users/kaihs/Documents/Coding/Bilder/Sounds/WinSound.mp3"));
}

void GameFrame::setView(QGraphicsView * view)
{
    this->view = view;
}

QGraphicsView * GameFrame::getView()
{
    return view;
}

int GameFrame::getFreeSpin() const
{
    return freeSpin;
}

void GameFrame::setFreeSpin(int value)
{
    freeSpin = value;
}

void GameFrame::setSlots(Slot * slot, int i)
{
    this->slot[i] = slot;
}

void GameFrame::initializeSlots()
{
    Slot * newSlots[5];
    Separator * separators[4];

    newSlots[0] = new Slot(this->rect().x(), this->rect().y(), this->rect(), view, 0);
    setSlots(newSlots[0], 0);
    view->scene()->addItem(newSlots[0]);

    for(int i = 0; i < 4; i++){
        separators[i] = new Separator(newSlots[i]->rect().x() + newSlots[i]->rect().width(), this->rect().y());
        newSlots[i+1] = new Slot(separators[i]->getPosX() + separators[i]->getWidth(), this->rect().y(), this->rect(), view, i);
        setSlots(newSlots[i+1], i+1);
        view->scene()->addItem(separators[i]);
        view->scene()->addItem(newSlots[i+1]);
    }
}

void GameFrame::gameFrameSlotCycle()                        // Verantwortlich für das laufen der Slots
{
    QEventLoop el;
    int maxSpins[5];

    maxSpins[0] = setMaxSpinsFirstSlot();                   // 1. Slot hat andere Funktion als die folgenden, da hier 13/14/15 Spins festgelegt werden

    for(int i = 1; i < 5; i++){                             // bei weiteren Slots wird nur noch eine zufällige Anzahl 2/3/4 erzeugt und folgend hinzugerechnet
        maxSpins[i] = setAddSpinsOtherSlots();
    }

    for(int spin = 0; spin < (maxSpins[0] + maxSpins[1] + maxSpins[2] + maxSpins[3] + maxSpins[4]); spin++) {
        for(int j = 0; j < slot[0]->getSqHeight() / slot[0]->squares[0]->getStepsize(); j++){                // Schleife läuft bis
            for(int i = (spin < maxSpins[0] ? 0 :                           // 1. die ersten 13/14/15 Umdrehungen vollziehen alle 5 Walzen
                        (spin < maxSpins[0] + maxSpins[1] ? 1 :                           // 2. danach drehen die Übrigen (hier: 4) Walzen 2/3/4 Umdrehungen, wonach die 2. dann stehen bleibt
                        (spin < maxSpins[0] + maxSpins[1] + maxSpins[2] ? 2 :                           // 3. danach geht es so weiter wie bei 2.
                        (spin < maxSpins[0] + maxSpins[1] + maxSpins[2] + maxSpins[3] ? 3 : 4)))); i < 5; i++) {    // 4. wie 2.

                slot[i]->slotSquaresMove();                                 // Funktionsaufruf dass im Slot der "MOVE Slot" aktiviert wird und
                                                                            // die Quadrate des Slots (hier um 5 Pixel) verschoben werden
            }
        }

        if(spin == maxSpins[0]) {
            slot[0]->getStopMusic()->getSound()->play();
        } else if(spin == maxSpins[0] + maxSpins[1]) {
            slot[1]->getStopMusic()->getSound()->play();
        } else if(spin == maxSpins[0] + maxSpins[1] + maxSpins[2]) {
            slot[2]->getStopMusic()->getSound()->play();
        } else if(spin == maxSpins[0] + maxSpins[1] + maxSpins[2] + maxSpins[3]) {
            slot[3]->getStopMusic()->getSound()->play();
        } else if(spin == maxSpins[0] + maxSpins[1] + maxSpins[2] + maxSpins[3] + maxSpins[4]) {
            slot[4]->getStopMusic()->getSound()->play();
        }
    }
}

int GameFrame::setMaxSpinsFirstSlot(){                  // die Anzahl der Stellen die durchlaufen werden werden hier durch eine Random-Funktion festgelegt
    //srand(time(NULL));
    int rnd = rand() % 100 + 1;                         // rnd zw. 1 und 100

    if(rnd <= 45) {                                     // 45% chance auf 13 Spins
        return 13;
    } else if(rnd > 45 && rnd <= 90) {                  // 45% Chance auf 14 Spins
        return 14;
    } else {                                            // 10% Chance auf 15 Spins
        return 15;
    }
}

int GameFrame::setAddSpinsOtherSlots(){                 //
    //srand(time(NULL));
    int rnd = rand() % 100 + 1;                         // rnd zw. 1 und 100

    if(rnd <= 30) {                                     // 30% Chance auf 2 weitere Drehungen
        return 2;
    } else if(rnd > 30 && rnd <= 70) {                  // 40% Chance auf 3 weitere Drehungen
        return 3;
    } else {                                            // 30% Chance auf 4 weitere Drehungen
        return 4;
    }
}

void GameFrame::checkShowingSquares() {
    int count = 0;

    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < 6; i++) {
            for(int h = 0; h < 3; h++){
                if(slot[j]->squares[i]->getPosY() == slot[j]->staticSquares[h]->getPosY()) {
                    shownSquares[j][h] = slot[j]->squares[i];

                    if(shownSquares[j][h]->getType() == 4){
                        count++;
                    }
                }
            }
        }
    }

    if(count > 3) {
        raiseFreeSpins();
    }

    WinLines->checkWinnings(shownSquares);
}

void GameFrame::resetPlayAndSetGame()
{
    WinLines->hideWinningLines();
    WinLines->setWinningLinesToZero();

    gameFrameSlotCycle();                     // soll einen kompletten durchlauf der Slots durchführen, wie in einer Spielrunde, soll normal in der "hauptschleife" wiederholt werden
    checkShowingSquares();                    // überprüfe die zu sehendes Felder und überprüfe ob gewonnen wurde

    setPlayerWin(false);
    for(int i = 0; i < WinLines->getWinLineCount() + 1; i++) {
        if(WinLines->line[i] != 0) {
            setPlayerWin(true);
        }
        if(getPlayerWin()) {
            winSound->getSound()->play();
        }
    }
}

bool GameFrame::getPlayerWin() const
{
    return playerWin;
}

void GameFrame::setPlayerWin(bool value)
{
    playerWin = value;
}

Animation GameFrame::getFreeSpinVideo() const
{
    return freeSpinVideo;
}

void GameFrame::setFreeSpinVideo(const Animation &value)
{
    freeSpinVideo = value;
}

WinningLines *GameFrame::getWinLines() const
{
    return WinLines;
}

void GameFrame::setWinLines(WinningLines *value)
{
    WinLines = value;
}

void GameFrame::raiseFreeSpins()
{
    this->freeSpin += 10;
}
