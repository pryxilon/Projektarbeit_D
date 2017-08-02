#ifndef BORDERDPART_H
#define BORDERDPART_H

#include <QGraphicsPixmapItem>



class Borderpart: public QGraphicsPixmapItem {
public:
    Borderpart();
    Borderpart(int, bool);
    int getId() const;
    void setId(int value);

    bool getIsFrame() const;
    void setIsFrame(bool value);

private:
    int id;
    bool isFrame;
};

#endif // BORDERDPARTS_H
