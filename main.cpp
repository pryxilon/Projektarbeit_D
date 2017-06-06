#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gameframe.h"
#include "slot.h"
#include "square.h"
#include "border.h"
#include "background.h"
#include "credit.h"
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

    Credit * credits = new Credit(gf);
    credits->setCredit(5000);

    QLabel * creditLabel = new QLabel();
    QGraphicsProxyWidget * proxy = scene->addWidget(creditLabel);
    proxy->setPos(1400, 900);
    creditLabel->setFixedWidth(150);
    creditLabel->setFixedHeight(50);
    creditLabel->setMargin(15);
    creditLabel->setStyleSheet("background-color: #222222;"
                               "opacity: 0.5;"
                               "font: bold 20px;"
                               "color: #888800;"
                               "border: 5px;"
                               "border-color: #888800");

    QLabel * betLabel = new QLabel();
    QGraphicsProxyWidget * proxyBet = scene->addWidget(betLabel);
    proxyBet->setPos(1100, 900);
    betLabel->setFixedWidth(150);
    betLabel->setFixedHeight(50);
    betLabel->setMargin(15);
    betLabel->setStyleSheet("background-color: #222222;"
                               "opacity: 0.5;"
                               "font: bold 20px;"
                               "color: #888800;"
                               "border: 5px;"
                               "border-color: #888800");

    while(1) {
        creditLabel->setText(QString::number(credits->getCredit()));
        if((bf->startButton->isDown() && gf->getVideoIsRunning() == false)) {
            credits->betting();
            creditLabel->setText(QString::number(credits->getCredit()));
            gf->resetPlayAndSetGame();
            credits->addWonCredits();
            creditLabel->setText(QString::number(credits->getCredit()));
            betLabel->setText("last win");
        }

        if(gf->getFreeSpin() != 0) {

            if(gf->getVideoIsRunning() == false) {
                gf->playVideoFreeSpin();
            }

            if((gf->getVideoIsRunning() == true) && ((gf->getCurrentTimeVideo() + 4) - QDateTime::currentSecsSinceEpoch() < 0)) {
                gf->hideVideoFreeSpin();

                while(gf->getFreeSpin() > 0) {
                    gf->resetPlayAndSetGame();
                    credits->addWonCredits();
                    creditLabel->setText(QString::number(credits->getCredit()));
                    gf->setFreeSpin(gf->getFreeSpin() - 1);
                }
            }
        }

        if(bf->vidButton->isDown() && gf->getVideoIsRunning() == false) {                       // diese Schleife + Inhalt muss später entfernt werden, wenn nicht mehr getestet werden muss
            gf->playVideoFreeSpin();
        }

        if((gf->getVideoIsRunning() == true) && ((gf->getCurrentTimeVideo() + 4) - QDateTime::currentSecsSinceEpoch() < 0)) {
            gf->hideVideoFreeSpin();
        }

        el.processEvents();
    }

    return a.exec();
}
