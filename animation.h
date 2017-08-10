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

    QGraphicsView *getView() const;
    void setView(QGraphicsView *value);
    QLabel *getLabel() const;
    void setLabel(QLabel *value);
    QMediaPlayer *getVideoMusic() const;
    void setVideoMusic(QMediaPlayer *value);
    QMovie *getAnimation() const;
    void setAnimation(QMovie *value);
    qint64 getStartTimeAnimation() const;
    void setStartTimeAnimation(const qint64 &value);
    bool getAnimationIsRunning() const;
    void setAnimationIsRunning(bool value);

    void playAnimation();
    void stopAnimation();
    void setAnimationNonvisible();

private:
    QGraphicsView *view;
    QLabel * label;
    QMediaPlayer *videoMusic;
    QMovie *animation;
    qint64 startTimeAnimation;
    bool animationIsRunning = false;
    QGraphicsProxyWidget * proxyVid;

};

#endif // ANIMATION_H
