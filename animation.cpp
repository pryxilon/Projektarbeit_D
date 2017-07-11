#include "animation.h"
#include <QPixmap>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

Animation::Animation() {

}

Animation::Animation(QGraphicsView * view, int x, int y)               // Animation für Freispiele
{
    label = new QLabel();
    label->setMask((new QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/WinGIF2.gif"))->mask());

    animation = new QMovie("C:/Users/kaihs/Documents/Coding/Bilder/WinGIF2.gif");
    label->setMovie(animation);
    proxyVid = view->scene()->addWidget(label);
    proxyVid->setPos(x, y);
    label->setVisible(false);
    //proxyVid->setPos(mainNumbers[1] + slot * mainNumbers[2] + slot * mainNumbers[4], mainNumbers[0] + pos * mainNumbers[3]);
}

QLabel *Animation::getLabel() const
{
    return label;
}

void Animation::setLabel(QLabel *value)
{
    label = value;
}

void Animation::playAnimation()
{
    setAnimationIsRunning(true);
    label->setFixedHeight(240);
    label->setFixedWidth(240);
    animation->start();

    label->setVisible(true);
    setCurrentTimeVideo(QDateTime::currentSecsSinceEpoch());
}

void Animation::stopAnimation()
{
    animation->stop();
    setAnimationNonvisible();
    setAnimationIsRunning(false);
}

void Animation::setAnimationNonvisible() {
    label->setVisible(false);
}

qint64 Animation::getCurrentTimeVideo() const
{
    return currentTimeVideo;
}

void Animation::setCurrentTimeVideo(const qint64 &value)
{
    currentTimeVideo = value;
}

bool Animation::getAnimationIsRunning() const
{
    return animationIsRunning;
}

void Animation::setAnimationIsRunning(bool value)
{
    animationIsRunning = value;
}

