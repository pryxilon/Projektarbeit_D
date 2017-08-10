#ifndef BORDERDPART_H
#define BORDERDPART_H

#include <QGraphicsPixmapItem>



class Borderpart: public QGraphicsPixmapItem {
public:
    Borderpart();
    Borderpart(int, bool);

    int  getID() const;
    void setID(int);
    bool getIsFrame() const;
    void setIsFrame(bool);

    void setupPixmap();

private:
    int  ID;
    bool isFrame;
};

#endif // BORDERDPARTS_H
