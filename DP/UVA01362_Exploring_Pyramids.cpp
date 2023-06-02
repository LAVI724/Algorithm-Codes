#include<bits/stdc++.h>
using namespace std;
// 2022.09.23

const int maxn = 300 + 5;
const int MOD = 1e9;

string str;
long long int dp[maxn][maxn];

int main(){
    // dp(i, j) = sum{d(i + 1, k - 1) * dp(k, j)}

    while(cin >> str){
        memset(dp, 0, sizeof(dp));
        
        for(int len = 0; len < str.size(); len += 2){
            for(int lef = 0; lef + len < str.size(); ++lef){
                int rig = lef + len;

                if(lef == rig) {
                    dp[lef][rig] = 1;
                    continue;
                }
                for(int k = lef + 2; k <= rig; k += 2){
                    if(str[lef] == str[k] && str[k] == str[rig])
                        dp[lef][rig] = (dp[lef][rig] + dp[lef+1][k-1] * dp[k][rig]) % MOD;
                }
            }
        }
        // for(int i = 0; i < str.size(); ++i){
        //     for(int j = 0; j < str.size(); ++j){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[0][str.size() - 1] << endl;
    }
}