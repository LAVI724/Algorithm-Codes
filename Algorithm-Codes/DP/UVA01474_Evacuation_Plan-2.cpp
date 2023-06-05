#include<bits/stdc++.h>
using namespace std;
// 2023.01.12 信宏 110-1/1117

const int maxn = 4000+5;

struct Item{
    int pos;
    int idx;
    bool operator < (const Item &rhs) const{
        return pos < rhs.pos;
    }
}team[maxn], shelter[maxn];

long long int dp[maxn][maxn];
int path[maxn][maxn];

int main(){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            cin >> team[i].pos;
            team[i].idx = i;
        }
        sort(team + 1, team + n + 1);

        int m;
        cin >> m;
        for(int i = 1; i <= m; ++i){
            cin >> shelter[i].pos;
            shelter[i].idx = i;
        }
        sort(shelter + 1, shelter + m + 1);

        memset(dp, 0x3f3f3f3f, sizeof(dp));
        memset(path, 0, sizeof(path));
        dp[1][0] = 0;
        for(int i = 1; i <= m; ++i){ // shelter no.
            for(int j = i; j <= n; ++j){ // team no.
                if(dp[i-1][j-1] <= dp[i][j-1]){
                    dp[i][j] = dp[i-1][j-1] + abs(shelter[i].pos - team[j].pos);
                    path[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i][j-1] + abs(shelter[i].pos - team[j].pos);
                    path[i][j] = 0;
                }
            }
        }
        
        cout << dp[m][n] << endl;
        int ans[maxn], shelterNow = m;
        for(int i = n; i > 0; --i){
            ans[team[i].idx] = shelter[shelterNow].idx;
            shelterNow -= path[shelterNow][i];
        }

        for(int i = 1; i < n; ++i){
            cout << ans[i] << " ";
        }
        cout << ans[n] << endl;
    }
}