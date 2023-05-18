#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {

public:
    static const int All_Size = 52; //表示撲克牌數，預設檔會給予，請不要修改
    Deck(); //建構子 
    Card* createADeck() const; //建立一個有所有撲克牌的陣列，並且回傳它（ex. 梅花A～黑桃K）
    void sortCard(); //由小到大排列所有的牌（提示：用 card 的小數去判斷），並且交換卡牌位置使用 swapByAddress()
    void Shuffle(int); //洗牌
    void distributeForPlayer(int); //分配卡牌給玩家
    void distributeForDealer(int); //分配卡牌給電腦
    
    void printCard(int); //會傳入一個 int 的參數，使用 cards[int] 去呼叫 class Card的print()做輸出
    Card* getPlayer() const; //回傳 player1
    Card* getDealer() const; //回傳 player2
    void show(Card*); //會傳入一個 Card* 的參數，印出該參數的前3張牌，輸出格式見輸出範例
    void compare(); //比較誰大，總共會比較3回合的player1卡大還是player2卡比較大。這裡的規則像是大老二先比牌的大小在比花色，梅花<方塊<愛心<黑桃，A比K大，2為最大(第一張和第一張比，第二張就和第二張比，第三張如前述)，得知誰大了之後做輸出，輸出格式見輸出範例
    
    static int current_figures;
    void swapByReference(Card&, Card&); //用參照的方式將參數兩個物件做交換
    void swapByPointer(Card*, Card*); //用指標的方式將參數兩個物件做交換
private:

    vector<Card> *player_HandCards;
    vector<Card> *dealer_HandCards;

    vector<Card> *player; //用來存放玩家手牌的指標
    vector<Card> *dealer; //用來存放莊家手牌的指標
    Card* poker; //用來存放所有卡牌的指標，（ex. 梅花A～黑桃K 共52張牌存到這個指標裡）
};
#endif // DECK_H
