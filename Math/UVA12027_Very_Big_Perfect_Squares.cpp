#include<bits/stdc++.h>
using namespace std;
// 2022.05.27

/*
題目只要"大概個數"

解題思維:
1.
僅判斷高位數字
若數字長度為奇數 則取最高位
若數字長度為偶數 則取最鋼兩位

2.
對高位數字開根號後無條件捨去

3.
結尾補 剩餘位數/2 個0
*/

int main(){
    string str;
    while(cin >> str && str != "0"){
        int num, len;
        if(str.size() & 1){
            num = str[0] - '0';
            len = str.size() - 1;
        }
        else{
            num = (str[0] - '0') * 10 + (str[1] - '0');
            len = str.size() - 2;
        }
        len /= 2;
        
        cout << (int)sqrt(num);
        for(int i = 0; i < len; i++){
            cout << 0;
        }
        cout << endl;
    }
}