#ifndef MUSIC_H
#define MUSIC_H

#include <QMediaPlayer>
#include <QObject>

class Music: public QObject
{
    Q_OBJECT
public:
    Music();
    void playClickSound();
    void stopClickSound();

    QMediaPlayer *getClickSound() const;
    void setClickSound(QMediaPlayer *value);

private:
    QMediaPlayer * clickSound;
};

#endif // MUSIC_H
