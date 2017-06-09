#ifndef MUSIC_H
#define MUSIC_H

#include <QMediaPlayer>
#include <QObject>

class Music: public QObject
{
    Q_OBJECT
public:
    Music();

    QMediaPlayer *getSound() const;
    void setSound(QMediaPlayer *value);

private:
    QMediaPlayer * sound;
};

#endif // MUSIC_H
