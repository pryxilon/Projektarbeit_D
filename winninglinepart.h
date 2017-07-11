#ifndef WINNINGLINEPART_H
#define WINNINGLINEPART_H

#include <QGraphicsPixmapItem>




class WinningLinePart: public QGraphicsPixmapItem
{
public:
    WinningLinePart();
    WinningLinePart(int ID, int type);

    void initialize(int, int);
    void setupPixmap(int);
    void hidePixmap();
    void setPosition(int type);
    void setPositionEven(int ID);
    void setPositionDiagonal(int ID);
    void setPositionBigW(int ID);

    int getHeight() const;
    void setHeight(int value);
    int getType() const;
    void setType(int value);
    int getID() const;
    void setID(int value);


    void setupPixmap();
private:
    int height;
    int ID;
    int type;
};

#endif // WINNINGLINEPART_H
