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

    Credit * credits = new Credit(gf);
    credits->setCredit(5000);

    CreditOutput * betHeightLabel = new CreditOutput(320, view);
    CreditOutput * lastWinLabel = new CreditOutput(1100, view);
    CreditOutput * creditLabel = new CreditOutput(1360, view);

    creditLabel->setText(QString::number(credits->getCredit()));

    while(1) {
        betHeightLabel->setText(QString::number(credits->getBet()));
        lastWinLabel->setText(QString::number(credits->getLastGain()));

        if((bf->startButton->isDown() && gf->getVideoIsRunning() == false)) {
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


                while(gf->getFreeSpin() > 0) {
                    lastWinLabel->setText(QString::number(credits->getLastGain()));
                    gf->resetPlayAndSetGame();
                    credits->addWonCredits();
                    creditLabel->setText(QString::number(credits->getCredit()));
                    gf->setFreeSpin(gf->getFreeSpin() - 1);
                }
            }
        }

        el.processEvents();
    }

    return a.exec();
}
