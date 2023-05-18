#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

int Deck::current_figures = 0;

Deck::Deck() {
    player = player_HandCards;
    dealer = dealer_HandCards;
    poker = createADeck();
}
// 建構子

Card* Deck::createADeck() const {
    Card* cards = new Card[All_Size];
    int index = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            cards[index] = j + (i * 0.1);
            index++;
        }
    }

    return cards;
}
//建立一個有所有撲克牌的陣列，並且回傳它 #小數點表花色、整數表大小

void Deck::sortCard() {
    for (int i = 0; i < 51; i++) {
        int min = i;
        for (int j = i + 1; j < 52; j++) {
            if (poker[j].getCard() < poker[min].getCard())
                min = j;
            for (int m = 0; m < min; m++) {
                if (poker[m].getCard() > poker[min].getCard()) {
                    swapByPointer(&poker[m], &poker[min]);
                }
            }
        }
    }
}
//由小到大排列所有的牌（提示：用 card 的小數去判斷），並且交換卡牌位置使用 swapByPointer()

void Deck::Shuffle(int r) {
    srand(r);
    for (int i = 0; i < 52; ++i)
    {
        int j = rand() % 52;
        swapByReference(poker[i], poker[j]);
    }
}
//洗牌

void Deck::distributeForPlayer(int paraPlayer) {
    player[paraPlayer].push_back(poker[current_figures]);
    current_figures++;
}
//分配卡牌給玩家

void Deck::distributeForDealer(int paraDealer) {
    player[paraDealer].push_back(poker[current_figures]);
    current_figures++;
}
//分配卡牌給電腦

void Deck::printCard(int parameter) {
    poker[parameter].print();
}
//會傳入一個 int 的參數，使用 cards[int] 去呼叫 class Card的print()做輸出

Card* Deck::getPlayer() const {

    return player;
}
//回傳 player1

Card* Deck::getDealer() const {

    return dealer;
}
//回傳 player2

void Deck::show(Card* player) {
    for (int i = 0; i < 3; i++) {
        player[i].print();
    }
}
//會傳入一個 Card* 的參數，印出該參數的前3張牌，輸出格式見輸出範例

void Deck::compare() {
    for (int i = 0; i < 3; i++) {
        if (player[i].getSymbol() > dealer[i].getSymbol())
            cout << "Game" << i << ":" << endl << "player1 win" << endl;
        else if (player[i].getSymbol() < dealer[i].getSymbol())
            cout << "Game" << i << ":" << endl << "player2 win" << endl;
        else if (player[i].getSymbol() == dealer[i].getSymbol())
            if (player[i].getSuit() > dealer[i].getSuit())
                cout << "Game" << i << ":" << endl << "player1 win" << endl;
            else if (player[i].getSuit() < dealer[i].getSuit())
                cout << "Game" << i << ":" << endl << "player2 win" << endl;
    }
}
//比較誰大，總共會比較3回合的player1卡大還是player2卡比較大。
//這裡的規則像是大老二先比牌的大小在比花色，梅花<方塊<愛心<黑桃，A比K大，2為最大
//(第一張和第一張比，第二張就和第二張比，第三張如前述)，得知誰大了之後做輸出，輸出格式見輸出範例

void Deck::swapByReference(Card& c1, Card& c2) {
    Card tempCard = c2;
    c2 = c1;
    c1 = tempCard;
}
//用參照的方式將參數兩個物件做交換

void Deck::swapByPointer(Card* c1, Card* c2) {
    Card tempCard = *c2;
    *c2 = *c1;
    *c1 = tempCard;
}
//用指標的方式將參數兩個物件做交換
