#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include <ctime>
#include "Card.h"

using namespace std;

class Deck{
public:
  Deck();
   void shuffle(); // 將牌洗亂
    Card dealCard(); // 發一張牌
    int cardsLeft(); // 剩餘未發出的排
private:
    Card cards_[52]; // 牌堆中所有的牌
    int currentCard; // 已經發出的牌的數量
};

#endif
    
  
  
