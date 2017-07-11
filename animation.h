#ifndef ANIMATION_H
#define ANIMATION_H

#include <QGraphicsView>
#include <QLabel>
#include <QMovie>



class Animation
{
public:
    Animation();
    Animation(QGraphicsView *, int, int);
    QLabel *getLabel() const;
    void setLabel(QLabel *value);

    void playAnimation();
    void stopAnimation();
    qint64 getCurrentTimeVideo() const;
    void setCurrentTimeVideo(const qint64 &value);
    bool getAnimationIsRunning() const;
    void setAnimationIsRunning(bool value);

    void setAnimationNonvisible();

private:
    QLabel * label;
    qint64 currentTimeVideo;
    bool videoIsRunning;
    QMovie * animation;
    QGraphicsProxyWidget * proxyVid;
    bool animationIsRunning;
};

#endif // ANIMATION_H
