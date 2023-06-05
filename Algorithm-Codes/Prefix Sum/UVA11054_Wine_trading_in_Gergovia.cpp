#include<bits/stdc++.h>
using namespace std;
// 2022.10.26 P13

/*
綜觀程式競賽 阿和

解題觀念:
Prefix Sum
*/

int main(){
    int n;
    while(scanf("%d", &n) && n){
        int num;
        long long int ans = 0;
        int prefix_sum = 0;

        for(int i = 0; i < n; ++i){
            scanf("%d", &num);
            prefix_sum += num;
            ans += abs(prefix_sum);
        }

        printf("%lld\n", ans);
    }
}