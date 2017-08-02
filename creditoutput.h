#ifndef CREDITOUTPUT_H
#define CREDITOUTPUT_H

#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QLabel>



class CreditOutput: public QLabel
{
public:
    CreditOutput(QGraphicsView *);
    CreditOutput(int, QGraphicsView *);

    void printLabel(int);
    QGraphicsView *getView() const;
    void setView(QGraphicsView *value);

private:
    QGraphicsView * view;
    QGraphicsProxyWidget * proxy;
};

#endif // CREDITOUTPUT_H
