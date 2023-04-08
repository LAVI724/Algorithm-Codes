#include<bits/stdc++.h>
using namespace std;
// 2022.06.08

/*
解題觀念:
dp 背包 - 重量/價值/不可重複使用

ex:
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26

第一個人的負重: 23
0 0 0 0 52 52 52 52 52 54 54 54 54 106 106 106 106 106 106 106 106 106 151 151
第二個人的負重: 20
0 0 0 0 52 52 52 52 52 54 54 54 54 106 106 106 106 106 106 106 106
第三個人的負重: 20
0 0 0 0 52 52 52 52 52 54 54 54 54 106 106 106 106 106 106 106 106
第四個人的負重: 26
0 0 0 0 52 52 52 52 52 54 54 54 54 106 106 106 106 106 106 106 106 106 151 151 151 151 151
*/

struct Edge{
    int p;
    int w;
}edge[1000+5];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> edge[i].p >> edge[i].w;
        }

        int g;
        int total = 0;
        cin >> g;
        for(int i = 0; i < g; i++){
            int pw;
            cin >> pw;

            int dp[30+5];
            memset(dp, 0, sizeof(dp));

            for(int j = 0; j < n; j++){
                for(int k = pw; k >= edge[j].w; k--){
                    dp[k] = max(dp[k], dp[k - edge[j].w] + edge[j].p);
                }
            }

            total += dp[pw];
        }
        cout << total << endl;
    }
}