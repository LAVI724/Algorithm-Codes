#include<bits/stdc++.h>
using namespace std;
// 2022.09.25

const long long int maxn = 210000000+5;

long long int maxi = 1;
long long int num[maxn];

void count(int n){
    for(int i = maxi; i <= n; ++i){
        num[i] = num[i-1] + i;
    }
}

int main(){
    long long int n;

    num[0] = 1;
    while(cin >> n && n >= 0){
        // cout << num[n] << endl;
        if(n >= maxi){
            count(n);
            maxi = max(maxi, n);
        }

        cout << num[n] << endl;
    }
}