#include<bits/stdc++.h>
using namespace std;
// 2022.06.25

int main(){
    long long int n;

    cin >> n;

    if(n & 1){
        cout << 0 << endl;
    }
    else{
        long long int ans = 0;
        long long int t = 10;
        while(n >= t){
            ans += n/t;
            t *= 5;
            // cout << t << endl;
        }

        cout << ans << endl;
    }
}