#include<bits/stdc++.h>
using namespace std;
// 2022.11.2

/*
阿和寫法

解題觀念:
法一:
1. 如果 B 內 == N，輸出並回傳 ture
2. 若 B 滿了，清空 B
3. 若 A 為空，注滿 A
4. 如果 A 有水，把 A 倒入 B

法二:
把法一的 A 和 B 全部倒過來做
*/

int main(){
    int a, b, ca, cb, n;
    while(cin >> ca >> cb >> n){
        a = 0; b = 0;
        while(true){
            if(b == n) {
                cout << "success" << endl;
                break;
            }
            else if(b == cb){
                cout << "empty B" << endl;
                b = 0;
            }
            else if (a == 0){
                cout << "fill A" << endl;
                a = ca;
            }
            else if(a != 0){
                cout << "pour A B" << endl;
                if(a + b <= cb){
                    b += a;
                    a = 0;
                }
                else{
                    a = a + b - cb;
                    b = cb;
                }
            }
        }
    }
}