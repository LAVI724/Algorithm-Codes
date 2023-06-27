#include<bits/stdc++.h>
using namespace std;
// 2023.06.27 程式競賽專論 110-1 阿和

/*
Greedy + dfs 
遍歷可能拼接棍子長度

參考網站：
http://naivered.github.io/2016/04/08/Problem_Solving/UVa/UVa-307-Sticks/
*/

const int maxn = 100+5;

int n, stickLengthSum, ans;
int stick[maxn];
bool visited[maxn];

// length 為當前拼接長度、cnt 為滿足 ans 長度的拼接木棒個數、i 為當前木棍已做到的 idx
bool dfs(int length, int idx, int stickTotal){
    if(length == ans){
        if(stickTotal == n) return true; 
        length = 0;
    }

    if(length == 0){
        for(idx = 0; visited[idx]; idx++);
        visited[idx] = true;
        if(dfs(length + stick[idx], idx+1, stickTotal+1)) return true;
        visited[idx] = false;
    }
    else{
        for(int j = idx; j < n; ++j){
            if(visited[j] || (j && stick[j] == stick[j-1] && !visited[j-1])) continue;
            if(stick[j] + length > ans) continue;

            visited[j] = true;
            if(dfs(length + stick[j], j+1, stickTotal+1)) return true;
            visited[j] = false;

            // 此 ans 假設棍長無論如何組合，皆無法完全完成
            if(length + stick[j] == ans) return false;
        }
    }
    return false;
}

int main(){

    while(scanf("%d", &n) && n){
        stickLengthSum = 0;

        for(int i = 0; i < n; ++i){
            scanf("%d", &stick[i]);
            stickLengthSum += stick[i];
        }
        sort(stick, stick + n, greater<int>());

        for(ans = stick[0]; ans <= stickLengthSum; ans++){
            memset(visited, false, sizeof(visited));

            if(stickLengthSum % ans != 0) continue;

            if(dfs(0, 0, 0)) break;
        }
        printf("%d\n", ans);
    }
}