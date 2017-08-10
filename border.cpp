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
    setView(view);

    Borderpart * bps[4];

    for(int i = 0; i < 4; i++) {
        bps[i] = new Borderpart(i, false);
        view->scene()->addItem(bps[i]);
    }

    startButton = new Button(view, "START", 1650, 800, 240, 80, true);
    raiseButton = new Button(view, "Einsatz", 1650, 600, 240, 80, true);
}

void Border::setView(QGraphicsView * view)
{
    this->view = view;
}

QGraphicsView * Border::getView()
{
    return view;
}
