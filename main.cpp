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

    int mainNumbers[6];
    mainNumbers[0] = topMargin;
    mainNumbers[1] = sideMargin;
    mainNumbers[2] = squareWidth;
    mainNumbers[3] = squareHeight;
    mainNumbers[4] = separatorWidth;
    mainNumbers[5] = frameBorderWidth;

    QEventLoop el;
    Background * bg = new Background();
    scene->addItem(bg);

    GameFrame * gf = new GameFrame(view, mainNumbers);
    scene->addItem(gf);

    Slot * slot[5];
    for(int i = 0; i < 5; i++){
        slot[i] = gf->slot[i];
    }

    Border * bf = new Border(view, mainNumbers);
    scene->addItem(bf);

    for(int i = 0; i < 5; i++) {
        gf->slot[i]->initSlot();                  // Slots werden initialisiert -> schon erzeugte Quadrate werden in Position gebracht
    }

    Credit * credits = new Credit(gf);
    credits->setCredit(5000);

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

        if((bf->startButton->isDown() && gf->getVideoIsRunning() == false && gf->slot[0]->staticSquares[0])) {
            credits->betting();
            creditLabel->setText(QString::number(credits->getCredit()));

            gf->resetPlayAndSetGame();

            credits->addWonCredits();
            creditLabel->setText(QString::number(credits->getCredit()));
        }

        if(gf->getFreeSpin() != 0) {

            if(gf->getVideoIsRunning() == false) {
                gf->playVideoFreeSpin();
            }

            if((gf->getVideoIsRunning() == true) && ((gf->getCurrentTimeVideo() + 4) - QDateTime::currentSecsSinceEpoch() < 0)) {
                gf->hideVideoFreeSpin();

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
