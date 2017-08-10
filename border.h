#ifndef BORDER_H
#define BORDER_H

#include "button.h"

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>

class Border: public QGraphicsRectItem {
public:
    Border();
    Border(QGraphicsView *);

    void setView(QGraphicsView *);
    QGraphicsView * getView();

    // public variables
    Button *startButton;
    Button *raiseButton;

private:
    QGraphicsView * view;
};

#endif // BORDERFRAME_H
