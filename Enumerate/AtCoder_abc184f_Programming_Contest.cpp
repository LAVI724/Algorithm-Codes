#include<bits/stdc++.h>
using namespace std;
// 2022.07.31

/*
解題觀念:
折半枚舉
枚舉集合 Sx 的數字 Sxi，找出 Sy 集合內小於等於 T−Sxi 中最大的數 Syj

參考資料:
https://fjuonlinejudge.github.io/Training/algorithm/enumerate/#_7
*/

const int maxn = 40+5;
int A[maxn+5];

void dfs(set<long long int> &s, int depth, int T, long long int sum){
    if(depth >= T){
        s.insert(sum);
        return;
    }
    // 取或不取的概念
    dfs(s, depth + 1, T, sum);
    dfs(s, depth + 1, T, sum + A[depth]);
}

int main(){

    int N, T;
    set<long long int> s1, s2;
    cin >> N >> T;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    // 折半枚舉
    dfs(s1, 0, N/2, 0);
    dfs(s2, N/2, N, 0);

    long long int ans = 0;
    for(auto &x : s1){
        auto it = s2.upper_bound(T - x);
        long long int y = *(--it);
        if(x + y <= T){
            ans = max(ans, x + y);
        }
    }
    cout << ans << endl; 
}