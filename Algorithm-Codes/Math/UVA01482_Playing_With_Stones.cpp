#include<bits/stdc++.h>
using namespace std;
// 2022.11.09 P16

/*
程式競賽專論 P16
SG 函數 
Nim Game 解法

看到 Nim Game 就要想到 SG 函數
*/

long long int SG(long long int n){
    return n % 2 == 0 ? n/2 : SG(n/2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        long long int a, v = 0;
        for(int i = 0; i < n; ++i){
            cin >> a;
            v ^= SG(a);
        }

        if(v){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}