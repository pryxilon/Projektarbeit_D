#ifndef WINNINGLINECONNECTER_H
#define WINNINGLINECONNECTER_H

#include <QGraphicsPixmapItem>




class WinningLineConnecter: public QGraphicsPixmapItem
{
public:
    WinningLineConnecter();
    WinningLineConnecter(int ID, int type, int parentalId);

    void initialize(int, int);
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
    int getParentalId() const;
    void setParentalId(int value);

private:
    int height;
    int ID;
    int type;
    int parentalId;
};

#endif // WINNINGLINECONNECTER_H
