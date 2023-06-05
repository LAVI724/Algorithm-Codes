#include<bits/stdc++.h>
using namespace std;
// 2022.05.30

/*
解題思維:
先將所有 k 當成正數

等差級數 1 + 2 + 3 + ... + n = sum
而當 sum - k = 偶數時，n 有最小
因為當為偶數時 sum - k 會將 sum 中與 k 對應的正數都減去 
並留下剩餘的數 是 k 的負數的 2 倍

Ex: -1 + 2 + 3 + 4 + 5 + 6 - 7 = 12 = k
sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
28 - 12 = 16 為偶數，16 為 - 1 - 7 的和的絕對值兩倍
*/

int main(){
    int t;
    bool space = false;
    cin >> t;

    while(t--){
        if(space) cout << endl;
        else space = true;
        
        int k;
        cin >> k;

        if (k < 0){
            k *= -1;
        }

        long long int sum = 0;
        for(int i = 1; ; i++){
            sum += i;

            if(sum >= k && !((sum - k) & 1)){
                cout << i << endl;
                break;
            }
        }
    }
}