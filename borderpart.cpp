#include "borderpart.h"
#include <QBrush>
#include <QDebug>


Borderpart::Borderpart(QRectF rect, int i)
{
    setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/FreeSpinHeaderEmpty1280x100.png"));
    setPos(rect.x() + 320,rect.y() + 20);
    setId(i);
}

Borderpart::Borderpart(QRectF rect, int i, int mainNumbers[6], bool isFrame)
{
    setId(i);
    setIsFrame(isFrame);
    if(!isFrame) {
        switch(i) {
        case 0:
            setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Header140.png"));
            setPos(rect.x(), rect.y());
            break;
        case 1:
            setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Left.png"));
            setPos(rect.x(), rect.y() + mainNumbers[0]);
            break;
        case 2:
            setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Right.png"));
            setPos(rect.x() + mainNumbers[1] + mainNumbers[2] * 5 + mainNumbers[4] * 4, rect.y() + mainNumbers[0]);
            break;
        case 3:
            setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Bottom220.png"));
            setPos(rect.x(), mainNumbers[0] + mainNumbers[2] * 3);
            break;
        }
    } else {
        switch(i) {
        case 0:
            setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/border-obenunten.png"));
            setPos(mainNumbers[1] - mainNumbers[5], mainNumbers[0] - mainNumbers[5]);
            break;
        case 1:
            setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/border-linksrechts.png"));
            setPos(mainNumbers[1] - mainNumbers[5], rect.y() + mainNumbers[0]);
            break;
        case 2:
            setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/border-linksrechts.png"));
            setPos(mainNumbers[1] + mainNumbers[2] * 5 + mainNumbers[4] * 4, rect.y() + mainNumbers[0]);
            break;
        case 3:
            setPixmap(QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/border-obenunten.png"));
            setPos(mainNumbers[1] - mainNumbers[5], mainNumbers[0] + mainNumbers[2] * 3);
            break;
        }
    }
}

int Borderpart::getId() const
{
    return id;
}

void Borderpart::setId(int value)
{
    id = value;
}

bool Borderpart::getIsFrame() const
{
    return isFrame;
}

void Borderpart::setIsFrame(bool value)
{
    isFrame = value;
}
