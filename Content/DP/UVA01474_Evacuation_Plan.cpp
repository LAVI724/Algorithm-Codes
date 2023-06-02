#include<bits/stdc++.h>
using namespace std;
// 2022.10.26 P14

/*
綜觀程式競賽 信宏

解題觀念:
dp 更新路徑

path 紀錄:
如果 dp 的前一列從左方來，則前一隊也來此避難所
如果 dp 的前一列從左上來，則前面沒有隊伍來此避難所
*/

const int maxn = 4000+5;

int path[maxn][maxn];
long long int dp[maxn][maxn];

struct Edge{
    int idx;
    int position;

    bool operator < (const Edge &rhs) const{
        return position < rhs.position;
    }
}team[maxn], shelter[maxn];

int main(){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            cin >> team[i].position;
            team[i].idx = i;
        }
        sort(team + 1, team + n + 1);

        int m;
        cin >> m;
        for(int i = 1; i <= m; ++i){
            cin >> shelter[i].position;
            shelter[i].idx = i;
        }
        sort(shelter + 1, shelter + m + 1);

        memset(dp, 0x3f3f3f3f, sizeof(dp));

        dp[1][0] = 0;
        for(int i = 1; i <= m; ++i){
            for(int j = i; j <= n; ++j){
                // dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]) + abs(team[j].position - shelter[i].position);
                if(dp[i][j-1] <= dp[i-1][j-1]){
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]) + abs(team[j].position - shelter[i].position);
                    path[i][j] = 0; // 從左邊來，前面的 teams 有人來 j shelter
                }
                else{
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]) + abs(team[j].position - shelter[i].position);
                    path[i][j] = 1; // 從左上來，前面的 teams 不會來 j shelter
                }
            }
        }
        // for(int i = 1; i <= m; ++i){
        //     for(int j = 1; j <= n; ++j){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int now_shelter = m;
        int ans[maxn];
        for(int i = n; i > 0; --i){
            ans[team[i].idx] = shelter[now_shelter].idx;
            now_shelter -= path[now_shelter][i];
            // if(!path[now_shelter][i]) now_shelter--;
            // cout << now_shelter << endl;
        }

        cout << dp[m][n] << endl;
        for(int i = 1; i < n; ++i){
            cout << ans[i] << " ";
        }
        cout << ans[n] << endl;
    }

}