#ifndef CREDIT_H
#define CREDIT_H

#include "gameframe.h"



class Credit
{
public:
    Credit(GameFrame *);

    int getCredit() const;
    void setCredit(int value);

    void GameOver();
    void addWonCredits();

    int getBet() const;
    void setBet(int value);

    int getMaxBet() const;

    int getSymbolValue(int, int);
    void betting();

    int getLastGain() const;
    void setLastGain(int value);

    bool getPlayerWin() const;
    void setPlayerWin(bool value);

private:
    int credit = 0;
    GameFrame * gf;
    int bet = 100;
    int const maxBet = 200;
    int lastGain;
    bool playerWin;
};

#endif // CREDIT_H
