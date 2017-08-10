#include "button.h"

Button::Button(QGraphicsView *view, QString text, int x, int y, int w, int h, bool isVisible)
{
    setView(view);
    this->setText(text);
    this->setFixedWidth(w);
    this->setFixedHeight(h);
    this->setStyleSheet(
                       "border-style: solid;"
                       "border-radius: 3px;"
                       "border-width: 3px;"
                       "border-color: #FFFFFF;"
                       "background-color: #00FF00;"
                       "font: 30px Space Age;"
                       "color: #FFFFFF;"
                       "margin 10px;"
                       );
    proxy = getView()->scene()->addWidget(this);
    proxy->setPos(x, y);

    if(!isVisible)
        proxy->setVisible(false);
}

QGraphicsView *Button::getView() const
{
    return view;
}

void Button::setView(QGraphicsView *value)
{
    view = value;
}

QGraphicsProxyWidget *Button::getProxy() const
{
    return proxy;
}

void Button::setProxy(QGraphicsProxyWidget *value)
{
    proxy = value;
}
