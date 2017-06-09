#include "creditoutput.h"

#include <QGraphicsProxyWidget>
#include <QLabel>

CreditOutput::CreditOutput()
{
    setView(view);
}

CreditOutput::CreditOutput(int x, QGraphicsView * view)
{
    setView(view);
    QGraphicsProxyWidget * proxy = view->scene()->addWidget(this);
    proxy->setPos(x, 900);
    this->setFixedWidth(240);
    this->setFixedHeight(86);
    this->setMargin(15);
    this->setStyleSheet("border-style: solid;"
                        "border-radius: 3px;"
                        "border-width: 3px;"
                        "border-color: #888800;"
                        "background-color: #222222;"
                        "font: 40px Space Age;"
                        "color: #888800;"
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
                         "color: #888800;"
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
