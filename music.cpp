#include "music.h"

Music::Music()
{
    clickSound = new QMediaPlayer();
    clickSound->setMedia(QUrl("C:/Users/kaihs/Documents/Coding/Bilder/click1.mp3"));
}

void Music::playClickSound()
{
    clickSound->play();
}

void Music::stopClickSound()
{
    clickSound->stop();
}

QMediaPlayer *Music::getClickSound() const
{
    return clickSound;
}

void Music::setClickSound(QMediaPlayer *value)
{
    clickSound = value;
}
