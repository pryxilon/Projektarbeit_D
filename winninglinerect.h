#ifndef WINNINGLINERECT_H
#define WINNINGLINERECT_H

#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QGraphicsRectItem>


class WinningLineRect: public QGraphicsRectItem
{
public:
    WinningLineRect();
    WinningLineRect(int parentalID, QGraphicsView *view);

    QGraphicsView *getView() const;
    void setView(QGraphicsView *value);    
    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    QGraphicsTextItem *getText() const;
    void setText(QGraphicsTextItem *value);

    void setupRect(int lineID);
    void displayRect(int type, int length);
    void hideRect();
    int getSymbolValue(int type, int length);

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
