#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {

public:
    static const int All_Size = 52; //表示撲克牌數
    Deck(); //建構子 
    Card* createADeck() const; //建立一個有所有撲克牌的陣列，並且回傳它
    void sortCard(); //由小到大排列所有的牌，並且交換卡牌位置使用 swapByPointer()
    void Shuffle(); //洗牌
    void distributeForPlayer(int); //分配卡牌給玩家
    void distributeForDealer(int); //分配卡牌給電腦
    
    //void printCard(int); //會傳入一個 int 的參數，使用 cards[int] 去呼叫 class Card的print()做輸出
    Card* getPlayer() const; //回傳 玩家的花色跟牌值
    Card* getDealer() const; //回傳 莊家的花色跟牌值
    void showOriginal(Card*); //會傳入一個 Card* 的參數，印出手上的兩張牌
    void showLater(Card*, int); //顯示手上所有的牌，int一個整數，是用來判斷總共要顯示幾張牌
    void finalCompare(); //最後用來比較莊家跟玩家的手牌大小
     int calculateHandValue(Card* hand, int hand_count); //計算手牌值
    
    static int current_figures; //紀錄當前發到第幾張牌
    void swapByReference(Card&, Card&); //用參照的方式將參數兩個物件做交換
    void swapByPointer(Card*, Card*); //用指標的方式將參數兩個物件做交換
private:

    Card* player_HandCards;
    Card* dealer_HandCards;

    Card* player; //用來存放玩家手牌的指標
    Card* dealer; //用來存放莊家手牌的指標
    Card* poker; //用來存放所有卡牌的指標
    int player_hand_count = 0;
    int dealer_hand_count = 0;
};
#endif // !1
