#include <iostream>
#include <string>
using namespace std;

int main() {
    int pokerCin = 49; // 用於使用ASCII碼的變數
    string poker[52]; // 撲克牌陣列

    for (int i = 0; i < 52; i++) {
        if (i % 13 == 0) {
            poker[i] = "A"; //設第1個數字為A
        }
        else if (i % 13 == 9) {
            poker[i] = "10"; //設第10個數字為10
        }
        else if (i % 13 == 10) {
            poker[i] = "J"; //設第11個數字為J
        }
        else if (i % 13 == 11) {
            poker[i] = "Q"; //設第12個數字為Q
        }
        else if (i % 13 == 12) {
            poker[i] = "K"; //設第13個數字為K
            pokerCin = 48;
        }
        else {
            poker[i] = (char)pokerCin; //其餘數字利用ASCII輸入
        }
        pokerCin++;
    }// 將A~K輸入進陣列當中 共四次
    
}
