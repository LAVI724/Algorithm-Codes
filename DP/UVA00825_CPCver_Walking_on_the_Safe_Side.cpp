#include<bits/stdc++.h>
using namespace std;
// 2022.07.07 

/*
同題 調整了子傑的輸入法
*/

bool mp[100+5][100+5];
long long int dp[100+5][100+5];

int main(){
    int t;
    bool space = false;
    cin >> t;
    while(t--){
        if(space){
            cout << endl;
        }
        else{
            space = true;
        }

        int r, c;
        cin >> r >> c;

        memset(mp, false, sizeof(mp));
        memset(dp, 0, sizeof(dp));

        int num;
        for(int i = 1; i <= r; i++){
            cin >> num >> num;

            int boom;
            for(int j = 0; j < num; j++){
                cin >> boom;
                mp[i][boom] = true;
            }
        }

        dp[1][1] = 1;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                if(mp[i][j]){
                    continue;
                }

                if(i > 1){
                    dp[i][j] += dp[i-1][j];
                }
                if(j > 1){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        cout << dp[r][c] << endl;
    }
}