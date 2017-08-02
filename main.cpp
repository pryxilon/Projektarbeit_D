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
    //view->setWindowState(Qt::WindowMaximized);
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

    Credit * credits = new Credit(gf);
    credits->setCredit(5000);

    Border * bf = new Border(view);
    scene->addItem(bf);

    Borderpart * gameBorders[4];

    for(int i = 0; i < 4; i++) {
        gameBorders[i] = new Borderpart(i, true);
        scene->addItem(gameBorders[i]);
    }

    CreditOutput * betHeightLabel = new CreditOutput(320, view);
    CreditOutput * lastWinLabel = new CreditOutput(1100, view);
    CreditOutput * creditLabel = new CreditOutput(1360, view);
    CreditOutput * freeSpinLabel = new CreditOutput(view);
    QGraphicsProxyWidget * proxy;

    creditLabel->setText(QString::number(credits->getCredit()));

    //gf->setFreeSpin(5);

    while(1) {
        betHeightLabel->setText(QString::number(credits->getBet()));
        lastWinLabel->setText(QString::number(credits->getLastGain()));

        if((bf->startButton->isDown() && freeSpinVideo->getAnimationIsRunning() == false && gf->slot[0]->staticSquares[0])) {
            credits->betting();
            creditLabel->setText(QString::number(credits->getCredit()));
            gf->resetPlayAndSetGame();

            credits->addWonCredits();
            creditLabel->setText(QString::number(credits->getCredit()));
        }

        if(gf->getFreeSpin() != 0) {

            if(freeSpinVideo->getAnimationIsRunning() == false) {
                freeSpinVideo->playAnimation();
            }

            if((freeSpinVideo->getAnimationIsRunning() == true) && ((freeSpinVideo->getStartTimeAnimation() + 4) - QDateTime::currentSecsSinceEpoch() < 0)) {
                freeSpinVideo->stopAnimation();

                proxy = scene->addWidget(freeSpinLabel);
                proxy->setPos(320, 50);
                while(gf->getFreeSpin() > 0) {
                    freeSpinLabel->setText("Freispiele: " + QString::number(gf->getFreeSpin()));
                    lastWinLabel->setText(QString::number(credits->getLastGain()));
                    gf->resetPlayAndSetGame();
                    credits->addWonCredits();
                    creditLabel->setText(QString::number(credits->getCredit()));
                    gf->setFreeSpin(gf->getFreeSpin() - 1);
                }
                scene->removeItem(freeSpinLabel->graphicsProxyWidget());
            }
        }

        el.processEvents();
    }

    return a.exec();
}
