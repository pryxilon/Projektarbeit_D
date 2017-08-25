#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gameframe.h"
#include "slot.h"
#include "square.h"
#include "border.h"
#include "background.h"
#include "credit.h"
#include "creditoutput.h"
#include "borderpart.h"
#include "globals.h"
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setWindowState(Qt::WindowFullScreen);
    view->setFixedSize(1920, 1080);
    view->setSceneRect(0, 0, 1920, 1080);

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QEventLoop el;
    Background * bg = new Background();
    scene->addItem(bg);

    GameFrame * gf = new GameFrame(view);
    scene->addItem(gf);

    Slot * slot[5];
    for(int i = 0; i < 5; i++){
        slot[i] = gf->slot[i];
    }

    for(int i = 0; i < 5; i++) {
        gf->slot[i]->initSlot();                  // Slots werden initialisiert -> schon erzeugte Quadrate werden in Position gebracht
    }

    Animation *freeSpinVideo = new Animation(view, 1280, 720);

    Border * bf = new Border(view);
    scene->addItem(bf);

    Borderpart * gameBorders[4];
    for(int i = 0; i < 4; i++) {
        gameBorders[i] = new Borderpart(i, true);
        scene->addItem(gameBorders[i]);
    }

    Credit * credits = new Credit(gf);

    CreditOutput * betHeightLabel = new CreditOutput(320, view, gf, 0, credits);
    CreditOutput * lastWinLabel = new CreditOutput(1100, view, gf, 1, credits);
    CreditOutput * creditLabel = new CreditOutput(1360, view, gf, 2, credits);

    credits->setBet(100);
    credits->setLastGain(0);
    credits->setCredit(startingCredits);

    CreditOutput * freeSpinLabel = new CreditOutput(view, gf, credits);
    QGraphicsProxyWidget * proxy;
    proxy = scene->addWidget(freeSpinLabel);
    proxy->setPos(320, 50);
    freeSpinLabel->setVisible(false);

    int freeSpinWin;

    while(1) {
        if(credits->getCredit() <= 0) {
            gf->gameOver->setLayerVisibility(true);

            if(gf->gameOver->restartButton->isDown()) {
                gf->gameOver->setLayerVisibility(false);
                credits->setCredit(startingCredits);
            }

        } else if(credits->getCredit() > 7500) {
            gf->winnerOverlay->setLayerVisibility(true);

            if(gf->winnerOverlay->restartButton->isDown()) {
                gf->winnerOverlay->setLayerVisibility(false);
                credits->setCredit(startingCredits);
            }
        } else {
            if(freeSpinVideo->getAnimationIsRunning() == false
               && gf->slot[0]->staticSquares[0]
               && gf->getFreeSpin() == 0) {
                if(bf->startButton->isDown()) {
                    if(credits->getCredit() >= credits->getBet()) {
                        credits->betting();
                        gf->resetPlayAndSetGame(credits->getBet());
                        credits->addWonCredits();
                    }
                    else if(credits->getCredit() < credits->getBet()) {
                        gf->getNoCredit()->getSound()->play();
                        creditLabel->blink();
                    }
                }
                else if(bf->raiseButton->isDown()) {
                    credits->handleRaiseButton();
                    gf->wait(250);
                }

            }

            if(gf->getFreeSpin() > 0) {
                gf->wait(1500);

                if(freeSpinVideo->getAnimationIsRunning() == false) {
                    freeSpinVideo->playAnimation();
                    gf->wait(1000);
                }

                if((freeSpinVideo->getAnimationIsRunning() == true) && ((freeSpinVideo->getStartTimeAnimation() + 4) - QDateTime::currentSecsSinceEpoch() < 0)) {

                    freeSpinVideo->stopAnimation();
                    freeSpinWin = credits->getCredit();
                    freeSpinLabel->setVisible(true);

                    while(gf->getFreeSpin() > 0) {
                        freeSpinLabel->setText("Freispiele: " + QString::number(gf->getFreeSpin()));

                        gf->resetPlayAndSetGame(credits->getBet());

                        credits->addWonCredits();

                        gf->setFreeSpin(gf->getFreeSpin() - 1);

                        gf->wait(1000);
                    }

                    freeSpinLabel->setVisible(false);
                    freeSpinWin = credits->getCredit() - freeSpinWin;
                    gf->freeSpinOverlay->setWinHeightText(freeSpinWin);

                    gf->wait(2500);
                    gf->freeSpinOverlay->setLayerVisibility(false);
                }
            }
        }

        el.processEvents();
    }

    return a.exec();
}
