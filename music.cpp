#include "music.h"

Music::Music()
{
    sound = new QMediaPlayer();
    //sound->setMedia(QUrl("C:/Users/kaihs/Documents/Coding/Bilder/Sounds/click1.mp3"));
}

QMediaPlayer *Music::getSound() const
{
    return sound;
}

void Music::setSound(QMediaPlayer *value)
{
    sound = value;
}
