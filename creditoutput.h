#ifndef CREDITOUTPUT_H
#define CREDITOUTPUT_H

#include "credit.h"
#include "gameframe.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QLabel>



class CreditOutput: public QLabel
{
    Q_OBJECT

public:
    CreditOutput(QGraphicsView *, GameFrame *, Credit*);
    CreditOutput(int, QGraphicsView *, GameFrame *, int, Credit*);

    QGraphicsView *getView() const;
    void setView(QGraphicsView *);
    GameFrame *getGf() const;
    void setGf(GameFrame *);
    Credit *getCredits() const;
    void setCredits(Credit *value);
    int getID() const;
    void setID(int value);

    void printLabel(int);
    void setColor(QString);
    void blink();


public slots:
    void setValue(int value);

private:
    int ID;
    Credit *credits;
    QGraphicsView * view;
    GameFrame *gf;
    QLabel * label;
    QGraphicsProxyWidget * proxy;
};

#endif // CREDITOUTPUT_H
