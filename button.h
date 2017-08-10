#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QString>



class Button: public QPushButton
{
public:
    Button();
    Button(QGraphicsView *, QString, int, int, int, int, bool);

    QGraphicsView *getView() const;
    void setView(QGraphicsView *);
    QGraphicsProxyWidget *getProxy() const;
    void setProxy(QGraphicsProxyWidget *);


private:
    QGraphicsProxyWidget *proxy;
    QGraphicsView *view;
};

#endif // BUTTON_H
