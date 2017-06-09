#ifndef ANIMATION_H
#define ANIMATION_H

#include <QLabel>



class Animation
{
public:
    Animation();
    Animation(int[6]);
    QLabel *getLabel() const;
    void setLabel(QLabel *value);

    void playVideoFreeSpin();
    void hideVideoFreeSpin();
    qint64 getCurrentTimeVideo() const;
    void setCurrentTimeVideo(const qint64 &value);
    bool getVideoIsRunning() const;
    void setVideoIsRunning(bool value);
private:
    QLabel * label;
    qint64 currentTimeVideo;
    bool videoIsRunning;
};

#endif // ANIMATION_H
