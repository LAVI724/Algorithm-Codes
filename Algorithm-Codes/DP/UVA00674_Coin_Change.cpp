#include<bits/stdc++.h>
using namespace std;
// 2022.08.05

/*
解題觀念:
dp - 時間(錢)/數量

和 UVA00357_Let_Me_Count_The_Ways 做法相同
*/

int main(){
    int n;
    int coin[] = {1, 5, 10, 25, 50};
    int dp[7500+5];

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for(int i = 0; i < 5; ++i){
        for(int j = coin[i]; j < 7500; ++j){
            if(dp[j - coin[i]] != 0){
                dp[j] += dp[j - coin[i]];
            }
        }
    }

    while(cin >> n){
        cout << dp[n] << endl;
    }
}