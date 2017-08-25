#include "credit.h"

Credit::Credit(GameFrame * gf)
{
    this->gf = gf;
    setLastGain(0);
    setPlayerWin(false);
}

GameFrame *Credit::getGf() const
{
    return gf;
}

void Credit::setGf(GameFrame *value)
{
    gf = value;
}

int Credit::getCredit() const
{
    return credit;
}

void Credit::setCredit(int value)
{
    credit = value;
    emit changedCredit(credit);
}

int Credit::getBet() const
{
    return bet;
}

void Credit::setBet(int value)
{
    bet = value;
    emit changedBet(bet);
}

int Credit::getMaxBet() const
{
    return maxBet;
}

int Credit::getLastGain() const
{
    return lastGain;
}

void Credit::setLastGain(int value)
{
    lastGain = value;
    emit changedLastWin(lastGain);
}

bool Credit::getPlayerWin() const
{
    return playerWin;
}

void Credit::setPlayerWin(bool value)
{
    playerWin = value;
}

int Credit::getBetButton() const
{
    return betButton;
}

void Credit::setBetButton(int value)
{
    betButton = value;
}

void Credit::betting()
{
    setCredit(getCredit() - bet);
}

void Credit::addWonCredits()
{
    setPlayerWin(false);
    for(int i = 0; i < 10; i++) {
        if(gf->getWinLines()->line[i] != 0) {
            setPlayerWin(true);
        }
        if(getPlayerWin()) {
            setLastGain(0);
        }
    }

    for(int i = 0; i < 10; i++) {
        if(gf->getWinLines()->line[i] != 0) {
            setCredit(getCredit() + bet * getSymbolValue(gf->getWinLines()->winLineType[i], gf->getWinLines()->line[i]));
            setLastGain(getLastGain() + bet * getSymbolValue(gf->getWinLines()->winLineType[i], gf->getWinLines()->line[i]));
        }
    }
}

void Credit::handleRaiseButton() {
    qDebug() << betButton;
    switch(betButton) {
    case 0: betButton = 1; setBet(200); break;
    case 1: betButton = 2; setBet(300); break;
    case 2: betButton = 3; setBet(400); break;
    case 3: betButton = 4; setBet(500); break;
    case 4: betButton = 0; setBet(100); break;
    default: betButton = 0; setBet(100); break;
    }
}

int Credit::getSymbolValue(int type, int length)
{
    switch(type) {
    case 0:
        switch(length) {
        case 2:
            return 1;
        case 3:
            return 6;
        case 4:
            return 20;
        case 5:
            return 150;
        default: return 0;
        }
    case 1:
        switch(length) {
        case 2:
            return 1;
        case 3:
            return 6;
        case 4:
            return 20;
        case 5:
            return 150;
        default: return 0;
        }
    case 2:
        switch(length) {
        case 2:
            return 1;
        case 3:
            return 8;
        case 4:
            return 80;
        case 5:
            return 400;
        default: return 0;
        }
    case 3:
        switch(length) {
        case 2:
            return 2;
        case 3:
            return 20;
        case 4:
            return 200;
        case 5:
            return 1000;
        default: return 0;
        }
    case 4:
        switch(length) {
        case 3:
            return 2;
        case 4:
            return 20;
        case 5:
            return 200;
        default: return 0;
        }
    case 5:
        switch(length) {
        case 3:
            return 1;
        case 4:
            return 5;
        case 5:
            return 20;
        default: return 0;
        }
    case 6:
        switch(length) {
        case 3:
            return 1;
        case 4:
            return 5;
        case 5:
            return 20;
        default: return 0;
        }
    case 7:
        switch(length) {
        case 3:
            return 1;
        case 4:
            return 5;
        case 5:
            return 20;
        default: return 0;
        }
    case 8: switch(length) {
        case 3:
            return 1;
        case 4:
            return 8;
        case 5:
            return 30;
        default: return 0;
        }
    case 9:
        switch(length) {
        case 3:
            return 1;
        case 4:
            return 8;
        case 5:
            return 30;
        default: return 0;
        }
    default: return 0;
    }
}

int Credit::getStartingCredit() const
{
    return startingCredit;
}

void Credit::setStartingCredit(int value)
{
    startingCredit = value;
}
