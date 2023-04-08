#include<bits/stdc++.h>
using namespace std;
// 2022.05.30

/*
解題思維:
期望值

期望值算法:
https://zh.wikipedia.org/zh-tw/%E6%9C%9F%E6%9C%9B%E5%80%BC
擲一枚公平的六面骰子，其每次「點數」的期望值是 3.5
E(x) = 1 * 1/6 + 2 * 1/6 + 3 * 1/6 + 4 * 1/6 + 5 * 1/6 + 6 * 1/6
= (1 + 2 + 3 + 4 + 5 + 6)/6 = 3.5

本題期望值:
bubble sort 每兩兩之間交換機率是 1/2
總共會做 C(n, 2) 次
E(x) = C(n, 2) * 1/2 = (n * (n - 1))/2 * 1/2
*/

int main(){
    int t, ca = 1;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;

        cout << "Case " << ca++ << ": ";
        
        // 如果 (n * (n - 1)) 可以被 4 整除 代表最後答案會是整數，否則會是分數
        if((n * (n - 1)) % 4){
            cout << ( (n * (n - 1)) / 2 ) << "/2"<< endl;
        }
        else{
            cout << ( (n * (n - 1)) / 2 ) / 2 << endl;
        }
    }
}