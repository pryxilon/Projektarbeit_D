#include "border.h"
#include "borderpart.h"

#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QDebug>
#include <QWidget>

Border::Border()
{

}

Border::Border(QGraphicsView * view)
{
    setRect(view->rect().x(), view->rect().y(), view->rect().width(), view->rect().height());
    setView(view);

    Borderpart * bps[4];

    for(int i = 0; i < 4; i++) {
        bps[i] = new Borderpart(i, false);
        view->scene()->addItem(bps[i]);
    }

    setStartButton();
}

void Border::setStartButton()
{
    startButton = new QPushButton("START");
    startButton->setFixedWidth(240);
    startButton->setFixedHeight(80);
    startButton->setStyleSheet(//"QPushButton {"
                               "border-style: solid;"
                               "border-radius: 3px;"
                               "border-width: 3px;"
                               "border-color: #FFFFFF;"
                               "background-color: #00FF00;"
                               "font: 40px Space Age;"
                               "color: #FFFFFF;"
                               //"qproperty-alignment: 'AlignCenter';"
                               "margin 10px;"
                               //"QPushButton:hover {background: #ff5555} "
                               //"QPushButton:pressed {background: #aa0000}"
                               );
    QGraphicsProxyWidget * proxy1 = getView()->scene()->addWidget(startButton);
    proxy1->setPos(1650, 800);
}

void Border::setView(QGraphicsView * view)
{
    this->view = view;
}

QGraphicsView * Border::getView()
{
    return view;
}
