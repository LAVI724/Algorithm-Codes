#include<bits/stdc++.h>
using namespace std;
// 2022.08.13

/*
解題思維:
數位 DP

dp[100+5][2][4]
第一維：10^100
第二維：上一位數是否已達 limit
第三維：題目的 k 值 (0/1/2/3)

參考資料:
https://yuihuang.com/atcoder-154e/
*/

string strN, revstrN;
int N, K, up[100+5];
long long int dp[100+5][2][4];

long long int dfs(int pos, int limit, int cnt){
    if(pos == -1 && cnt == K) return 1;
    else if (pos == -1) return 0;

    if(cnt > K) return 0;
    if(dp[pos][limit][cnt] != -1) return dp[pos][limit][cnt];

    int last;
    long long int ret = 0;
    if(limit == 1) last = revstrN[pos] - '0';
    else last = 9;

    for(int i = 0; i <= last; ++i){
        ret += dfs(pos - 1, limit && i == last, cnt + (i != 0));
    }
    return dp[pos][limit][cnt] = ret;
}

int main(){
    cin >> strN >> K;
    N = strN.size();

    memset(dp, -1, sizeof(dp));

    revstrN = strN;
    reverse(revstrN.begin(), revstrN.end());

    dfs(N - 1, 1, 0);
    stringstream ss;
    int num;
    ss << strN;
    ss >> num;
    for(int i = 0; i <= num; ++i){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k <= K; ++k){
            cout << "i: " << i << " j: " << j << " k: " << k << " : " << dp[i][j][k] << endl;
            }
        }
    }
    cout << endl;

    cout << dfs(N - 1, 1, 0) << endl;
}