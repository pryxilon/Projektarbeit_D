#ifndef CREDIT_H
#define CREDIT_H

#include "gameframe.h"

class Credit
{
public:
    Credit(GameFrame *);

    GameFrame *getGf() const;
    void setGf(GameFrame *);
    int  getCredit() const;
    void setCredit(int);
    int  getBet() const;
    void setBet(int);
    int  getMaxBet() const;
    int  getLastGain() const;
    void setLastGain(int);
    bool getPlayerWin() const;
    void setPlayerWin(bool);
    int  getBetButton() const;
    void setBetButton(int);

    void betting();
    void addWonCredits();
    void handleRaiseButton();
    int  getSymbolValue(int, int);

private:
    GameFrame *gf;
    int credit = 0;
    int bet = 100;
    int const maxBet = 1000;
    int lastGain;
    int betButton = 0;
    bool playerWin;
};

#endif // CREDIT_H
