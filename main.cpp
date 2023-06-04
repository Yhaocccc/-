#include <iostream>
#include <string>
#include"Card.h"
#include"Deck.h"
using namespace std;
    bool playAgain() {
        bool playAgain = false;
        string choice;
         do{
            cout << "是否重新開始遊戲(YES or NO)";
            cin >> choice;
    
            if ( choice== "Yes"|| choice == "yes"||choice == "YES"){
                 playAgain=true;
            }
            else if ( choice== "No"||choice == "NO"|| choice == "no"){
                playAgain=false;
            }
            else{
                cout<<"請輸入YES或NO"<<endl;
            }
          } while (true);
   }

int main() {
    
 do {   
   cout << " * 二十一點卡牌遊戲 * " << endl;
   cout << " ******************** " << endl ;
   for (int i = 0; i < 52; i++) {
        cout << "Enter the value for poker card " << i << ": ";
        cin >> poker[i];
    }
    for (int i = 0; i < 52; i++) {
        int rank = static_cast<int>(poker[i]); // 取得整數部分(數字)
        int suit = static_cast<int>((poker[i] - rank) * 10); // 取得小數部分(花色)
        cout << "Poker card " << i << " has value: " << rank << "." << suit << endl;
    }

    

    for (int i = 0; i < 52; i++) {
        if (i % 13 == 0) {
            pokerOnScreen[i] = "A"; //設定1個數字為A
        }
        else if (i % 13 == 9) {
            pokerOnScreen[i] = "10"; //設定10個數字為10
        }
        else if (i % 13 == 10) {
            pokerOnScreen[i] = "J"; //設定11個數字為J
        }
        else if (i % 13 == 11) {
            pokerOnScreen[i] = "Q"; //設定12個數字為Q
        }
        else if (i % 13 == 12) {
            pokerOnScreen[i] = "K"; //設定13個數字為K
            pokerOnScreenCin = 48;
        }
        else {
            pokerOnScreen[i] = to_string((i % 13) + 1); // 其餘數字利用數字字符串表示
            poker[i] = (i % 13) + 1;
        }
    }// 將A~K輸入進陣列當中 共四次

    int poker[52]; //實際上玩家手上撲克牌的點數陣列


    for (int i = 0; i < 52; i++) {
        if (i % 13 == 9 || i % 13 == 10 || i % 13 == 11 || i % 13 == 12) {
            poker[i] = 10; //10, J, Q, K為點數10
        }
        else {
            poker[i] = (i + 1) % 13; //剩餘數字照常輸入
        }

    } //輸入點數於陣列中
/*
    for (int i = 0; i < 52; i++) {
        cout << poker[i] << " ";
    }
*/

     Deck deck;
     // 建立牌組
   
     deck.createADeck();
     deck.Shuffle();
     // 創建一副牌並洗牌
  
     deck.distributeForPlayer(2);
     deck.distributeForDealer(2);
     // 發兩張牌給玩家和莊家

    
     cout << "玩家的牌: " << endl;
     deck.showOriginal(deck.getPlayer());
     cout << "莊家的牌: " << endl;
     deck.showOriginal(deck.getDealer());
     // 顯示玩家和莊家的初始手牌

     deck.finalCompare();
     //詢問玩家是否要加牌，並決定遊戲勝負

   } while (playAgain());  //詢問是否重新開始遊戲

     return 0;
}
