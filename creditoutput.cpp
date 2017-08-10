#include "creditoutput.h"
#include "globals.h"

#include <QLabel>

CreditOutput::CreditOutput(QGraphicsView * view, GameFrame *gf)     // Freispielbanner
{
    setGf(gf);
    setView(view);
    this->setFixedWidth(1280);
    this->setFixedHeight(60);
    this->setMargin(15);
    this->setStyleSheet("border-style: solid;"
                        "border-radius: 3px;"
                        "border-width: 3px;"
                        "border-color: #DDDD00;"
                        "background-color: #DDDDDD;"
                        "font: 40px Space Age;"
                        "color: #DDDD00;"
                        "qproperty-alignment: 'AlignCenter';");
}

CreditOutput::CreditOutput(int x, QGraphicsView * view, GameFrame *gf)
{
    setGf(gf);
    setView(view);
    proxy = view->scene()->addWidget(this);
    proxy->setPos(x, 900);
    this->setFixedWidth(240);
    this->setFixedHeight(86);
    this->setMargin(15);
    this->setColor("DDDD00");

    printLabel(x);
}

QGraphicsView *CreditOutput::getView() const
{
    return view;
}

void CreditOutput::setView(QGraphicsView *value)
{
    view = value;
}

GameFrame *CreditOutput::getGf() const
{
    return gf;
}

void CreditOutput::setGf(GameFrame *value)
{
    gf = value;
}

void CreditOutput::printLabel(int x)
{
    label = new QLabel();
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

void CreditOutput::setColor(QString color) {
    setStyleSheet( "border-style: solid;"
                   "border-radius: 3px;"
                   "border-width: 3px;"
                   "border-color: #" + color + "; "
                   "background-color: #222222;"
                   "font: 40px Space Age;"
                   "color: #" + color + ";"
                   "qproperty-alignment: 'AlignCenter | AlignRight';");
}

void CreditOutput::blink() {
    for(int i = 0; i < 3; i++) {
        setColor("FF0000");
        gf->wait(100);
        setColor("DDDD00");
        gf->wait(100);
    }
}
