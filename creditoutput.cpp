#include "creditoutput.h"

#include <QLabel>

CreditOutput::CreditOutput(QGraphicsView * view)
{
    setView(view);
    this->setFixedWidth(1280);
    this->setFixedHeight(60);
    this->setMargin(15);
    this->setStyleSheet("border-style: solid;"
                        "border-radius: 3px;"
                        "border-width: 3px;"
                        "border-color: #DDDD00;"
                        "background-color: #EEEEEE;"
                        "font: 40px Space Age;"
                        "color: #DDDD00;"
                        "qproperty-alignment: 'AlignCenter';");
}

CreditOutput::CreditOutput(int x, QGraphicsView * view)
{
    setView(view);
    proxy = view->scene()->addWidget(this);
    proxy->setPos(x, 900);
    this->setFixedWidth(240);
    this->setFixedHeight(86);
    this->setMargin(15);
    this->setStyleSheet("border-style: solid;"
                        "border-radius: 3px;"
                        "border-width: 3px;"
                        "border-color: #DDDD00;"
                        "background-color: #222222;"
                        "font: 40px Space Age;"
                        "color: #DDDD00;"
                        "qproperty-alignment: 'AlignCenter | AlignRight';");

    printLabel(x);
}

void CreditOutput::printLabel(int x)
{
    QLabel * label = new QLabel();
    QGraphicsProxyWidget * proxyLabel = getView()->scene()->addWidget(label);
    proxyLabel->setPos(x, 900);
    label->setText(x == 320 ? "Einsatz" : ((x == 1100) ? "Letzter Gewinn" : "Guthaben"));
    label->setFixedWidth(240);
    label->setFixedHeight(20);
    label->setStyleSheet("margin: 3px;"
                         "font: bold 15px Arial;"
                         "color: #DDDD00;"
                         "background-color: transparent;"
                         "qproperty-alignment: 'AlignCenter';");
}

QGraphicsView *CreditOutput::getView() const
{
    return view;
}

void CreditOutput::setView(QGraphicsView *value)
{
    view = value;
}
