#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

int Deck::current_figures = 0; 
//紀錄當前發到第幾張牌

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
        }
        if (min != i) {
            swapByPointer(&poker[i], &poker[min]);
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
    player[paraPlayer] = poker[current_figures];
    current_figures++;
    player_hand_count++;
     // 每次分發牌給玩家，就增加玩家的手牌數量
}
//分配卡牌給玩家

void Deck::distributeForDealer(int paraDealer) {
    dealer[paraDealer] = poker[current_figures];
    current_figures++;
    dealer_hand_count++;
    // 每次分發牌給莊家，就增加莊家的手牌數量
}
//分配卡牌給電腦

/*
void Deck::printCard(int parameter) {
    poker[parameter].print();
}
//會傳入一個 int 的參數，使用 cards[int] 去呼叫 class Card的print()做輸出
*/

Card* Deck::getPlayer() const {

    return player;
}
//回傳 玩家的花色跟牌值

Card* Deck::getDealer() const {

    return dealer;
}
//回傳 莊家的花色跟牌值

void Deck::showOriginal(Card* person) {
    for (int i = 0; i < 2; i++) {
        person[i].print();
    }
}
//會傳入一個 Card* 的參數，印出手上的兩張牌

void Deck::showLater(Card* person ,int a) {
    for (int i = 0; i < a; i++) {
        person[i].print();
    }
}
//顯示手上所有的牌，int一個整數，是用來判斷總共要顯示幾張牌


void Deck::finalCompare() {
 
    // 計算玩家和莊家手中牌的總值
    int playerValue = calculateHandValue(player,player_hand_count); // 玩家手牌數量
    int dealerValue = calculateHandValue(dealer,dealer_hand_count);//莊家手牌數量
   while (playerValue > 5 && playerValue < 21){//點數介於5到21，給玩家選擇是否加牌
    cout<<"是否要加牌(YES or NO)"<<endl;
    string answer;
    cin >> answer;
   if (answer == "Yes" || answer == "yes"){
    distributeForPlayer(paraPlayer);// 分發一張牌給玩家
   }
   else if (answer == "No" || answer == "no"){
       break;// 跳出迴圈，結束加牌
   }
   else{
    cout << "請輸入YES或NO" << endl;
   }
  }
    // 如果玩家手中牌的總值超過21，表示玩家爆牌，莊家贏
    if (playerValue > 21) {
        cout << "玩家爆牌，莊家贏！" << endl;
    } 
    // 如果莊家手中牌的總值超過21，表示莊家爆牌，玩家贏
    else if (dealerValue > 21) {
        cout << "莊家爆牌，玩家贏！" << endl;
    } 
    // 如果玩家手中牌的總值大於莊家，玩家贏
    else if (playerValue > dealerValue) {
        cout << "玩家贏！" << endl;
    } 
    // 如果莊家手中牌的總值大於玩家，莊家贏
    else if (dealerValue > playerValue) {
        cout << "莊家贏！" << endl;
    } 
    // 如果玩家和莊家手中牌的總值相等，表示平手
    else {
        cout << "平手！" << endl;
    }
    if (player_hand_count >= 5) {
            cout << "恭喜你過五關！" << endl;
            break;
    }
}

int Deck::calculateHandValue(Card* hand, int hand_count) {
    int total = 0;
    for(int i=0; i<hand_count; ++i) {
        if(hand[i].getRank() == "A") {
            total += 1;
        }
        else {
            total += hand[i].getCard();
        }
    }
    return total;
}


    
}
//最後用來比較莊家跟玩家的手牌大小

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




/*
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
*/
