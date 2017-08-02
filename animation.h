#ifndef ANIMATION_H
#define ANIMATION_H

#include <QGraphicsView>
#include <QLabel>
#include <QMediaPlayer>
#include <QMovie>



class Animation
{
public:
    Animation();
    Animation(QGraphicsView *, int, int);
    Animation(QGraphicsView *view, int x, int y, int width, int height);
    QLabel *getLabel() const;
    void setLabel(QLabel *value);

    void playAnimation();
    void stopAnimation();
    bool getAnimationIsRunning() const;
    void setAnimationIsRunning(bool value);

    void setAnimationNonvisible();

    QMediaPlayer *getVideoMusic() const;
    void setVideoMusic(QMediaPlayer *value);

    QMovie *getAnimation() const;
    void setAnimation(QMovie *value);

    qint64 getStartTimeAnimation() const;
    void setStartTimeAnimation(const qint64 &value);
private:
    QLabel * label;
    qint64 startTimeAnimation;
    bool videoIsRunning;
    QMovie *animation;
    QGraphicsProxyWidget * proxyVid;
    bool animationIsRunning = false;

    QMediaPlayer *videoMusic;
};

#endif // ANIMATION_H
