#include "animation.h"
#include <QPixmap>
#include <QGraphicsProxyWidget>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

Animation::Animation() {

}

Animation::Animation(int mainNumbers[6])               // Animation für Freispiele
{
    /*label = new QLabel();
    label->setMask((new QPixmap("C:/Users/kaihs/Documents/Coding/Bilder/Warphole.gif"))->mask());

    movie = new QMovie("C:/Users/kaihs/Documents/Coding/Bilder/Warphole.gif");
    label->setMovie(movie);
    proxyVid = view->scene()->addWidget(warpHoleLabel);
    proxyVid->setPos(mainNumbers[1], mainNumbers[0]);*/
}

QLabel *Animation::getLabel() const
{
    return label;
}

void Animation::setLabel(QLabel *value)
{
    label = value;
}

void Animation::playVideoFreeSpin()
{
    /*setVideoIsRunning(true);
    label->setFixedHeight(720);
    label->setFixedWidth(1280);
    movie->start();
    videoMusic->play();

    label->setVisible(true);
    setCurrentTimeVideo(QDateTime::currentSecsSinceEpoch());*/
}

void Animation::hideVideoFreeSpin()
{
    /*movie->stop();
    label->setVisible(false);
    setVideoIsRunning(false);
    videoMusic->stop();*/
}

qint64 Animation::getCurrentTimeVideo() const
{
    return currentTimeVideo;
}

void Animation::setCurrentTimeVideo(const qint64 &value)
{
    currentTimeVideo = value;
}

bool Animation::getVideoIsRunning() const
{
    return videoIsRunning;
}

void Animation::setVideoIsRunning(bool value)
{
    videoIsRunning = value;
}

