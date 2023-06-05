#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// 2022.08.20

/*
解題觀念:
樹形 dp
類似樹上的並查集

參考資料:
https://blog.csdn.net/hao_6_6/article/details/119920640
*/

const int maxn = 1e5 + 5;
long long int MOD = 1e9 + 7;

vector<int> G[maxn];
long long int dp[maxn][2]; // 點 u 是 or 白 的方法數

void dfs(int u, int father){
    // 點 u 初始更新為 1 種方法
    dp[u][0] = dp[u][1] = 1;

    for(int v : G[u]){

        // 因為每點子節點中會有一點是連回原父節點
        if(v == father) continue;

        dfs(v, u);

        // 更新父親 u 染黑的方法數有: u 為黑的方法數 * 兒子 v 是白的方法數
        dp[u][1] = dp[u][1] * dp[v][0] % MOD;

        // 更新父親 u 染白的方法數有: u 為白的方法數 * 兒子 v 所有黑白的方法數
        dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;
    }
}

int main(){
    int N;
    cin >> N;

    int x, y;
    for(int i = 1; i < N; ++i){
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1, 0);

    // int ans = 0;
    // for(int i = 1; i <= N; ++i){
    //     ans = max(ans, (dp[i][0] + dp[i][1]) % MOD); 
    // }

    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
}