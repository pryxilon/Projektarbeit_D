#ifndef SEPARATOR_H
#define SEPARATOR_H

#include <QGraphicsRectItem>
#include "gameframe.h"

class Separator: public QGraphicsRectItem {
public:
    Separator(int, int, int[6]);
};

#endif // SEPARATOR_H
