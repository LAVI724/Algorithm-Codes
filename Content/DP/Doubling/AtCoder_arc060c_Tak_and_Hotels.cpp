#include<bits/stdc++.h>
using namespace std;
// 2022.07.23

/*
解題觀念:
倍增

參考資料:
https://drive.google.com/drive/folders/11zIJefAbArrRLNnY2iPsKVo22XBquy6H

ex: 
9
1 3 6 13 15 18 19 29 31
10

初始化 dp[i][0] (從每個 i 開始走 L 最多可以走多遠的 index)
更新 dp[j][i] 更新次數 i 是 logN-1 次 (減初始化那次)

更新結果:
2 4 7
3 6 8
4 6 8
6 7 8
6 7 8
6 7 8
7 8 8
8 8 8
8 8 8
i = 0 為 day1 休息時的位址
i = 1 為 day2 休息時的位址 (day1 休息的位址的休息位址)
...
LOG 是因為設 2^LOG >= N
無論如何從第一間開始住都不會超過住 LOG 次的天數
*/

int main(){
    int N;
    cin >> N;

    int LOG = sqrt(N);
    vector<int> arr(N);
    vector<vector<int>> dp(N, vector<int>(LOG));
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }

    int L, Q;
    cin >> L >> Q;
    for(int i = 0; i < N; ++i){
        dp[i][0] = lower_bound(arr.begin(), arr.end(), arr[i] + L) - arr.begin();
        if(dp[i][0] == N || arr[i] + L < arr[dp[i][0]]){
            dp[i][0] -= 1;
        }
    }

    for(int i = 1; i < LOG; ++i){
        for(int j = 0; j < N; ++j){
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }

    // for(int i = 0; i < N; ++i){
    //     for(int j = 0; j < LOG; ++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < Q; ++i){
        int a, b;
        cin >> a >> b;
        // 要減減是因為 arr 的 index 從 0 開始 但題目從 1 開始
        a--;
        b--;

        if(a > b) swap(a, b);

        int ans = 0;
        // 從後往回推 最大化可以到達的位址
        for(int i = LOG - 1; i >= 0; --i){
            if(dp[a][i] < b){
                ans += (1 << i);
                a = dp[a][i];
            }
        }
        cout << ans + 1 << endl;
    }
}