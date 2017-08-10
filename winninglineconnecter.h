#ifndef WINNINGLINECONNECTER_H
#define WINNINGLINECONNECTER_H

#include <QGraphicsPixmapItem>




class WinningLineConnecter: public QGraphicsPixmapItem
{
public:
    WinningLineConnecter();
    WinningLineConnecter(int, int, int);

    int  getID() const;
    void setID(int);
    int  getType() const;
    void setType(int);
    int  getParentalId() const;
    void setParentalId(int);
    int  getHeight() const;
    void setHeight(int);

    void initialize(int);
    void setupPixmap();
    void setPosition(int);
    void setPositionEven();
    void setPositionDiagonal();
    void setPositionBigW();

private:
    int ID;
    int type;
    int parentalId;
    int height;
};

#endif // WINNINGLINECONNECTER_H
