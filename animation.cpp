#include "animation.h"
#include "globals.h"
#include <QPixmap>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

Animation::Animation() {

}

Animation::Animation(QGraphicsView *view, int width, int height) {     // Freispielvideo
    label = new QLabel();
    label->setMask((new QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Animation/Warphole.gif"))->mask());

    animation = new QMovie("C:/Users/kaihs/Documents/Coding/Bilder/Animation/Warphole.gif");

    videoMusic = new QMediaPlayer();
    videoMusic->setMedia(QUrl("C:/Users/kaihs/Documents/Coding/Bilder/Sounds/Wurmloch.mp3"));

    label->setMovie(animation);
    label->setFixedWidth(width);
    label->setFixedHeight(height);


    proxyVid = view->scene()->addWidget(label);
    proxyVid->setPos(sideMargin, topMargin);
    label->setVisible(false);
}

Animation::Animation(QGraphicsView * view, int x, int y, int width, int height)               // Animation für Squares
{
    label = new QLabel();
    label->setMask((new QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/WinGIF2.gif"))->mask());

    animation = new QMovie("C:/Users/kaihs/Documents/Coding/Bilder/WinGIF2.gif");
    label->setMovie(animation);
    label->setFixedWidth(width);
    label->setFixedHeight(height);

    proxyVid = view->scene()->addWidget(label);
    proxyVid->setPos(x, y);
    label->setVisible(false);
    //proxyVid->setPos(sideMargin + slot * squareWidth + slot * separatorWidth, topMargin + pos * squareHeight);
}

QGraphicsView *Animation::getView() const
{
    return view;
}

void Animation::setView(QGraphicsView *value)
{
    view = value;
}

QLabel *Animation::getLabel() const
{
    return label;
}

void Animation::setLabel(QLabel *value)
{
    label = value;
}

QMediaPlayer *Animation::getVideoMusic() const
{
    return videoMusic;
}

void Animation::setVideoMusic(QMediaPlayer *value)
{
    videoMusic = value;
}

QMovie *Animation::getAnimation() const
{
    return animation;
}

void Animation::setAnimation(QMovie *value)
{
    animation = value;
}

qint64 Animation::getStartTimeAnimation() const
{
    return startTimeAnimation;
}

void Animation::setStartTimeAnimation(const qint64 &value)
{
    startTimeAnimation = value;
}

bool Animation::getAnimationIsRunning() const
{
    return animationIsRunning;
}

void Animation::setAnimationIsRunning(bool value)
{
    animationIsRunning = value;
}

void Animation::playAnimation()
{
    setAnimationIsRunning(true);
    animation->start();
    videoMusic->play();

    label->setVisible(true);
    setStartTimeAnimation(QDateTime::currentSecsSinceEpoch());
}

void Animation::stopAnimation()
{
    animation->stop();
    label->setVisible(false);
    setAnimationIsRunning(false);
    videoMusic->stop();
}
