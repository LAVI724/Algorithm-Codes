#include<bits/stdc++.h>
using namespace std;
// 2023.02.16

const int maxn = 100+5;

int main(){
    int N, M;
    int Case = 1;
    while(cin >> N >> M && N && M){

        int u, v, w;
        int dp[maxn][maxn];
        // 初始化不是無限大而是 0
        // 因為期望載客量越大越好 故初始化要是很小的 0
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < M; ++i){
            cin >> u >> v >> w;
            dp[u][v] = dp[v][u] = w;
        }

        // Floyd Warshall
        for(int k = 1; k <= N; ++k){
            for(int i = 1; i <= N; ++i){
                for(int j = 1; j <= N; ++j){
                    dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]));
                }
            }
        }

        int start, end, people;
        cin >> start >> end >> people;

        int ans = (people/(dp[start][end]-1));
        // 減一是因為每次容量都又留一個位置給導遊 可行遊客容量就會少一
        // 如果不能整除 就要多送一趟
        if(people % (dp[start][end]-1) > 0) ans++;

        cout << "Scenario #" << Case++ << endl << "Minimum Number of Trips = " << ans << endl << endl;
    }
}