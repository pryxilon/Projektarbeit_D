#include "separator.h"

Separator::Separator(int x, int y, int mainNumbers[6])
{
    setRect(x, y, mainNumbers[4] /*frame->rect().width() * 0.0125*/, mainNumbers[3] * 3);
}
