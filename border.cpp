#include "border.h"
#include "borderpart.h"

#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QDebug>
#include <QWidget>

Border::Border()
{

}

Border::Border(QGraphicsView * view, int mainNumbers[6])
{
    setRect(view->rect().x(), view->rect().y(), view->rect().width(), view->rect().height());
    setView(view);

    Borderpart * bps[4];

    for(int i = 0; i < 4; i++) {
        bps[i] = new Borderpart(this->rect(), i, mainNumbers, false);
        view->scene()->addItem(bps[i]);
    }

    Borderpart * gameBorders[4];

    for(int i = 0; i < 4; i++) {
        gameBorders[i] = new Borderpart(this->rect(), i, mainNumbers, true);
        view->scene()->addItem(gameBorders[i]);
    }

    Borderpart * freeSpinHeader = new Borderpart(this->rect(), 9);
    view->scene()->addItem(freeSpinHeader);

    setStartButton();
}

void Border::setStartButton()
{
    startButton = new QPushButton("START");
    startButton->setStyleSheet("QPushButton {background : red; border-style: none; font: bold 30px; color: #ffffff; padding: 6px; } "
                               "QPushButton:hover {background: #ff5555} "
                               "QPushButton:pressed {background: #aa0000}");
    QGraphicsProxyWidget * proxy1 = getView()->scene()->addWidget(startButton);
    proxy1->setPos(1700, 800);
}

void Border::setView(QGraphicsView * view)
{
    this->view = view;
}

QGraphicsView * Border::getView()
{
    return view;
}
