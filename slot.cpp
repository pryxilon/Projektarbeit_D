#include "music.h"
#include "slot.h"
#include "square.h"
#include "globals.h"
#include <QGraphicsView>
#include <QDebug>
#include <QEventLoop>
#include <QTime>



Slot::Slot(QGraphicsView * view)
{
    setView(view);
    setID(6);
}

Slot::Slot(int x, int y, QRectF frameRect, QGraphicsView * view, int id)
{
    // Setter
    setView(view);
    setID(id);
    setRect(x, y, squareWidth, frameRect.height());
    setSpawningY(frameRect.y() - 2 * squareHeight);

    stopMusic = new Music();
    stopMusic->getSound()->setMedia(QUrl("C:/Users/kaihs/Documents/Coding/Bilder/Sounds/click1.mp3"));

    for(int i = 0; i < 6; i++) {                                                    // Es gibt !6! Squares pro Slot, diese bekommen nach einem durchlauf einen neuen Type
        squares[i] = new Square(this->rect(), view, i, setRandomType(i));           // jedes Square wird erstellt
        view->scene()->addItem(squares[i]);                                         // jedes SquareItem wird der Scene hinzugefügt
    }

    for(int i = 0; i < 3; i++) {
        staticSquares[i] = new Square(this->rect(), view, i);
        view->scene()->addItem(staticSquares[i]);
    }
}

void Slot::setView(QGraphicsView * view)
{
    this->view = view;
}

QGraphicsView* Slot::getView()
{
    return view;
}

void Slot::setID(int id)
{
    this->id = id;
}

int Slot::getID()
{
    return id;
}

int Slot::getSqHeight()
{
    return rect().height() / 3;
}

int Slot::getSpawningY()
{
    return spawningY;
}

void Slot::setSpawningY(int y)
{
    spawningY = y;
}

void Slot::initSlot()
{
    for(int i = 0; i < 6; i++) {
        squares[i]->setPos(rect().x(), getSpawningY() + (5 - i) * getSqHeight());
    }
}

int Slot::setRandomType(int i)
{
    //srand(time(0));
    int rndNumberOrPic = setRandom(i);                                            // randomZahl wird in Funktion setRandomNumber erzeugt und dann in rndNumberOrPic gespeichert

    if(rndNumberOrPic <= 10) {              // Dann -> Bild
        int rndNumberPic = setRandomPictures(i);
        return rndNumberPic;
    } else {                        // Dann -> Zahl
        int rndNumberNumbers = setRandomNumbers(i);
        return rndNumberNumbers;
    }
}

int Slot::setRandom(int i) {

    int rndNumberOrPic = 0;
    int x = i == 0 ? 5 : i - 1;
    int y = x == 5 ? 4 : (x == 0 ? 5 : x - 1);

    if(counter != 0 && counter != 1){                       // count wird von beginn an hochgezählt, und wir benötigt um zu verhindern, dass in den 1. 2 durchläufen die nich leeren sq[4] und sq[5] nicht abgefragt werden
        if(squares[x]->getType() < 5) {                     // wenn voriges Feld ein SonderSquare war
            if(squares[y]->getType() < 5){                  // wenn beide vorigen Felder SonderSquares waren,
                rndNumberOrPic = 11;                        // -> ist das Folgende sicher keines, sondern ein "normalesSquare" -> daher sofort auf '11' gesetzt
            } else {                                        // wenn das vorige aber nicht das 2. zuvor ein Sondersquare ist
                rndNumberOrPic = qrand() % 35 + 7; // 8;    // -> dann wird die Chance auf ein folgendes SonderSquare verringert
            }
        } else {                                            // ist das vorige kein SonderSquare
            if(squares[y]->getType() < 5) {                 // aber das 2. zuvor eines
                rndNumberOrPic = qrand() % 35 + 5; // 6;    // dann wird die Wahrscheinlichkeit verringert, aber nicht so stark wie oben
            } else {                                        // sind beide vorigen Felder normaleSquare
                rndNumberOrPic = qrand() % 35 + 1;          // wird die normale Wahrscheinlichkeit von etwa 2.5 zu 1 verwendet
            }
        }
    } else {
        rndNumberOrPic = qrand() % 35 + 1;
    }
    counter++;
    return rndNumberOrPic;
}

int Slot::setRandomPictures(int i) {
    int rnd = qrand() % 90 + 1;
    int type = 0;
    int x = i == 0 ? 5 : i - 1;
    int y = x == 5 ? 4 : (x == 0 ? 5 : x - 1);


    if((rnd > 0) && (rnd <= 30)) {            // p == Phenix
        type = 0;
    } else if((rnd > 30) && (rnd <= 45)) {    // s == Skarabeus
        type = 1;
    } else if((rnd > 45) && (rnd <= 60)) {    // x == Pharao
        type = 2;
    } else if((rnd > 60) && (rnd <= 75)) {    // f == Forscher/Scientist
        type = 3;
    } else if((rnd > 75) && (rnd <= 90)) {    // b == book
        type = 4;
    } else {
        qDebug() << "Error at setRandomPictures";
    }

    if(counterPic != 0 && counterPic != 1){
        if(squares[x]->getType() == type || squares[y]->getType() == type) {
            type = setRandomPictures(i);
        }
    }
    counterPic++;
    return type;
}

int Slot::setRandomNumbers(int i) {
    //srand(time(0));
    //QTime time = QTime::currentTime(); //qsrand((uint)time.msec());
    int rnd = qrand() % 75 + 1;
    int type = 0;
    int x = i == 0 ? 5 : i - 1;
    int y = x == 5 ? 4 : (x == 0 ? 5 : x - 1);


    if((rnd > 0) && (rnd <= 15)) {            // t == Ten
        type = 5;
    } else if((rnd > 15) && (rnd <= 30)) {    // j == Jack
        type = 6;
    } else if((rnd > 30) && (rnd <= 45)) {    // q == Queen
        type = 7;
    } else if((rnd > 45) && (rnd <= 60)) {    // k == -king
        type = 8;
    } else if((rnd > 60) && (rnd <= 75)) {    // a == Ace
        type = 9;
    } else {
        qDebug() << "Error at setRandomNumbers";
    }

    if(counterNum != 0 && counterNum != 1){
        if(squares[x]->getType() == type || squares[y]->getType() == type) {
            type = setRandomNumbers(i);
        }
    }
    counterNum++;
    return type;
}

void Slot::slotSquaresMove()
{
    QEventLoop el;
    for(int i = 0; i < 6; i++) {
        squares[i]->moveSquare();

        el.processEvents();
        if(squares[i]->y() >= rect().height() + getSqHeight()){                         // wenn ein Quadrat bei den Slots 2 Quadrate unterhalb des "Slotfensters" ist
            int type = setRandomType(i);
            squares[i]->setType(type);                                                  // dann wird diesem Square ein neuer Typ zugewiesen
            squares[i]->setPixmapOfSquare(type);                                        // und das Bild geändert/angepasst
        }
    }
}

bool Slot::getFinished() const
{
    return finished;
}

void Slot::setFinished(bool value)
{
    finished = value;
}

Music *Slot::getStopMusic() const
{
    return stopMusic;
}

void Slot::setStopMusic(Music *value)
{
    stopMusic = value;
}

