#ifndef CREDITOUTPUT_H
#define CREDITOUTPUT_H

#include "gameframe.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QLabel>



class CreditOutput: public QLabel
{
public:
    CreditOutput(QGraphicsView *, GameFrame *);
    CreditOutput(int, QGraphicsView *, GameFrame *);

    QGraphicsView *getView() const;
    void setView(QGraphicsView *);
    GameFrame *getGf() const;
    void setGf(GameFrame *);

    void printLabel(int);
    void setColor(QString);
    void blink();

private:
    QGraphicsView * view;
    GameFrame *gf;
    QLabel * label;
    QGraphicsProxyWidget * proxy;
};

#endif // CREDITOUTPUT_H
