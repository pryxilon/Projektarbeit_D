#ifndef BORDER_H
#define BORDER_H

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>

class Border: public QGraphicsRectItem {
public:
    Border();
    Border(QGraphicsView *, int[6]);

    void setStartButton();

    void setView(QGraphicsView *);
    QGraphicsView * getView();
    QPushButton * startButton;

    void setExitButton();
private:
    QGraphicsView * view;
};

#endif // BORDERFRAME_H
