#include "Card.h"
#include <iostream>
#include<string>
using namespace std;
Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}
// 取得卡牌的花色
Card::Suit Card::getSuit() {
    return suit;
}

// 取得卡牌的點數
Card::Rank Card::getRank() {
    return rank;
}

// 顯示卡牌的花色和點數
void Card::display() {
    string suitStr;
    string rankStr;

    // 使用switch-case結構來將枚舉型別的花色轉換為字符串
    switch (suit) {
        case HEART:
            suitStr = "紅心";
            break;
        case DIAMOND:
            suitStr = "方塊";
            break;
        case CLUB:
            suitStr = "梅花";
            break;
        case SPADE:
            suitStr = "黑桃";
            break;
    }

    // 使用switch-case結構來將枚舉型別的點數轉換為字符串
    switch (rank) {
        case ACE:
            rankStr = "A";
            break;
        case TWO:
            rankStr = "2";
            break;
        case THREE:
            rankStr = "3";
            break;
        case FOUR:
            rankStr = "4";
            break;
        case FIVE:
            rankStr = "5";
            break;
        case SIX:
            rankStr = "6";
            break;
        case SEVEN:
            rankStr = "7";
            break;
        case EIGHT:
            rankStr = "8";
            break;
        case NINE:
            rankStr = "9";
            break;
        case TEN:
            rankStr = "10";
            break;
        case JACK:
            rankStr = "J";
            break;
        case QUEEN:
            rankStr = "Q";
            break;
        case KING:
            rankStr = "K";
            break;
    }

    // 輸出卡牌的花色和點數
    cout << "牌面: " << suitStr << " " << rankStr << endl;
}
