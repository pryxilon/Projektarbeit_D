#include "credit.h"

Credit::Credit(GameFrame * gf)
{
    this->gf = gf;

}

int Credit::getCredit() const
{
    return credit;
}

void Credit::setCredit(int value)
{
    credit = value;
}

void Credit::GameOver()
{
    if(credit == 0){

    }
}

void Credit::addWonCredits()
{
    for(int i = 0; i < 5; i++) {
        if(gf->line[i] != 0) {
            setCredit(getCredit() + bet * getSymbolValue(gf->winLineType[i], gf->line[i]));
        }
    }
}

int Credit::getBet() const
{
    return bet;
}

void Credit::setBet(int value)
{
    bet = value;
}

int Credit::getMaxBet() const
{
    return maxBet;
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

void Credit::betting()
{
    setCredit(getCredit() - bet);
}
