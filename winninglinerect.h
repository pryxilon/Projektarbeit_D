#ifndef WINNINGLINERECT_H
#define WINNINGLINERECT_H

#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QGraphicsRectItem>


class WinningLineRect: public QGraphicsRectItem
{
public:
    WinningLineRect();
    WinningLineRect(int parentalID, QGraphicsView *);

    QGraphicsView *getView() const;
    void setView(QGraphicsView *);
    int  getWidth() const;
    void setWidth(int);
    int  getHeight() const;
    void setHeight(int);
    int  getX() const;
    void setX(int);
    int  getY() const;
    void setY(int);
    QGraphicsTextItem *getText() const;
    void setText(QGraphicsTextItem *);

    void setupRect(int);
    void displayRect(int, int, int);
    void hideRect();
    int  getSymbolValue(int, int);


private:
    int width;
    int height;
    int x;
    int y;
    QGraphicsView *view;
    QGraphicsTextItem *text;
    QString htmlText;
};

#endif // WINNINGLINERECT_H
