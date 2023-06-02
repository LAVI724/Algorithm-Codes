#include<bits/stdc++.h>
using namespace std;
// 2022.06.26

/*
解題觀念:
bitwise operator

寫法是 atcoder abc197c orxor 的魔改
*/

int main(){
    string s;
    cin >> s;

    long long int n = s.size();
    long long int arr[n+5];
    memset(arr, 0, sizeof(arr));

    for(long long int i = 1; i <= s.size(); i++){
        arr[i] = s[i-1] - '0';
    }

    long long int total = 0;
    for(long long int i = 0; i < (1 << n); i++){
        long long int lef = 0;
        for(int j = 1; j <= n; j++){
            lef = lef * 10 + arr[j];
            if((i & (1 << j))){
                total += lef;
                lef = 0;
            }
        }
        total += lef;
    }

    cout << total/2 << endl;
}