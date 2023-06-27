#include<bits/stdc++.h>
using namespace std;
// 2023.06.27 PUPC 模擬賽 2

/*
DP - 雙重背包問題
處理細節比較繁瑣
參考資料：
https://theriseofdavid.github.io/2020/10/12/UVa/UVa10163/
*/

const int maxn = 100+5;
const int inf = 0x3f3f3f3f;

int N, M, cost;
int P[maxn], dp[maxn];

int maxSafe(){
    memset(dp, 0, sizeof(dp));
    dp[0] = inf;

    // i：工人、j：儲存量、k：看守倉庫數
    for(int i = 0; i < M; ++i){
        for(int j = N; j > 0; --j){
            // P[i] >= k 的目的是不讓 P[i]/k 小於 1
            // dp[j-k] 如果前 k 個倉庫還無人看守，則現倉庫也先預設為無人看守
            // P[i]/k 一個工人看守多個倉庫會減少安全性
            for(int k = 1; k <= j && P[i] >= k; k++){
                dp[j] = max(dp[j], min(dp[j-k], P[i] / k));
            }
        }
    }
    return dp[N];
}

int miniCost(){
    // 工人成本等於安全性，安全性 0 則成本亦為 0
    if(cost == 0) return 0;
    memset(dp, inf, sizeof(dp));
    dp[0] = 0;

    for(int i = 0; i < M; ++i){
        for(int j = N; j > 0; --j){
            // k 直接從 j 和 P[i]/cost 間取較小者開始算
            // 若 P[i]/cost 小於 1，則不會使用這名工人
            for(int k = min(j, P[i]/cost); k > 0; --k){
                dp[j] = min(dp[j], dp[j-k] + P[i]);
            }
        }
    }
    return dp[N];
}

int main(){
    while(cin >> N >> M && N && M){
        memset(P, 0, sizeof(P));
        for(int i = 0; i < M; ++i){
            cin >> P[i];
        }
        cost = maxSafe();
        cout << cost << " " << miniCost() << endl; 
    }
}