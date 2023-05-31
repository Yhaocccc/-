#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
class Card {
public:
    enum Suit {  // 花色
        HEART,   // 紅心
        DIAMOND, // 方塊
        CLUB,    // 梅花
        SPADE    // 黑桃
    };
    enum Rank {  // 點數，使用enum 定義ace為1以後，後面常數會自動定義
        ACE = 1, // A
        TWO,     // 2
        THREE,   // 3
        FOUR,    // 4
        FIVE,    // 5
        SIX,     // 6
        SEVEN,   // 7
        EIGHT,   // 8
        NINE,    // 9
        TEN,     // 10
        JACK,    // J
        QUEEN,   // Q
        KING     // K
    };
    
    Card(Rank rank, Suit suit);
    Suit getSuit();//取得花色
    Rank getRank();//取得點數
    void display();//顯示牌面
       
private:
    Suit suit;
    Rank rank;
};
#endif
