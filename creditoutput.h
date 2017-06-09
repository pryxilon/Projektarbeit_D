#ifndef CREDITOUTPUT_H
#define CREDITOUTPUT_H

#include <QGraphicsView>
#include <QLabel>



class CreditOutput: public QLabel
{
public:
    CreditOutput();
    CreditOutput(int, QGraphicsView *);

    void printLabel(int);
    QGraphicsView *getView() const;
    void setView(QGraphicsView *value);

private:
    QGraphicsView * view;
};

#endif // CREDITOUTPUT_H
