#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gameframe.h"
#include "slot.h"
#include "square.h"
#include "border.h"
#include "background.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QThread>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    //view->setWindowState(Qt::WindowMaximized);
    view->setFixedSize(1920, 1080);
    view->setSceneRect(0, 0, 1920, 1080);

    int topMargin = 140;
    int sideMargin = 320;
    int squareWidth = 240;
    int squareHeight = 240;
    int separatorWidth = 20;
    int frameBorderWidth = 10;

    int mainNumbers[6];
    mainNumbers[0] = topMargin;
    mainNumbers[1] = sideMargin;
    mainNumbers[2] = squareWidth;
    mainNumbers[3] = squareHeight;
    mainNumbers[4] = separatorWidth;
    mainNumbers[5] = frameBorderWidth;


    Background * bg = new Background();
    scene->addItem(bg);

    QEventLoop el;

    GameFrame * gf = new GameFrame(view, mainNumbers);

    scene->addItem(gf);

    //gf->setFlag(QGraphicsItem::ItemIsFocusable);
    //gf->setFocus();

    Slot * slot[5];
    for(int i = 0; i < 5; i++){
        slot[i] = gf->slot[i];
    }

    Border * bf = new Border(view, mainNumbers);
    scene->addItem(bf);

    for(int i = 0; i < 5; i++) {
        gf->slot[i]->initSlot();                  // Slots werden initialisiert -> schon erzeugte Quadrate werden in Position gebracht
    }

    while(1) {
        if((bf->startButton->isDown() && gf->getVideoIsRunning() == false) || (gf->getVideoIsRunning() == false || gf->getFreeSpin() != 0)) {
            gf->dehighlightWinningLines();              // alle "WinnigLines" "ausschalten"
            gf->setWinningLinesToZero();                // "Winninglines" müssen vor jeder Runde auf 0 gesetzt werden
            gf->gameFrameSlotCycle();                   // soll einen kompletten durchlauf der Slots durchführen, wie in einer Spielrunde, soll normal in der "hauptschleife" wiederholt werden
            gf->checkShowingSquares();                  // überprüfe die zu sehendes Felder und überprüfe ob gewonnen wurde
            gf->highlightWinningLines();

        }

        if(gf->getFreeSpin() != 0) {

            if(gf->getVideoIsRunning() == false) {
                gf->playVideoFreeSpin();
            }

            if((gf->getVideoIsRunning() == true) && ((gf->getCurrentTime() + 4) - QDateTime::currentSecsSinceEpoch() < 0)) {
                gf->hideVideoFreeSpin();

                for(int i = 0; i < gf->getFreeSpin(); i++) {
                    gf->dehighlightWinningLines();              // alle "WinnigLines" "ausschalten"
                    gf->setWinningLinesToZero();                // "Winninglines" müssen vor jeder Runde auf 0 gesetzt werden

                    gf->gameFrameSlotCycle();                   // soll einen kompletten durchlauf der Slots durchführen, wie in einer Spielrunde, soll normal in der "hauptschleife" wiederholt werden
                    gf->checkShowingSquares();                  // überprüfe die zu sehendes Felder und überprüfe ob gewonnen wurde
                    gf->highlightWinningLines();
                }
            }
        }

        if(bf->vidButton->isDown() && gf->getVideoIsRunning() == false) {                       // diese Schleife + Inhalt muss später entfernt werden, wenn nicht mehr getestet werden muss
            gf->playVideoFreeSpin();
        }

        if((gf->getVideoIsRunning() == true) && ((gf->getCurrentTime() + 4) - QDateTime::currentSecsSinceEpoch() < 0)) {
            gf->hideVideoFreeSpin();
        }

        el.processEvents();
    }

    return a.exec();
}
