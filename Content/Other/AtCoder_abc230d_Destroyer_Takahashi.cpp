#include<bits/stdc++.h>
using namespace std;
// 2022.06.24

/*
解題思維:
區間調整問題 Greedy

每次都打一座牆的最尾端、下次打此拳沒碰到的墻的最尾端
*/

int main(){
    int n, d;
    cin >> n >> d;

    deque<pair<int, int>> wall(n);
    for(int i = 0; i < n; i++){
        // int l, r;
        // cin >> l >> r;
        // wall.push_back({l, r});

        // 為了用尾端大小作排序，否則可能會有顧慮到頭卻沒有顧慮到尾的狀況
        cin >> wall[i].second >> wall[i].first;
    }
    sort(wall.begin(), wall.end());

    // for(auto i : wall){
    //     cout << i.first << " " << i.second << endl;
    // }

    long long int ans = 0, p = -1;
    for(int i = 0; i < wall.size(); i++){
        if(wall[i].second <= p){
            continue;
        }

        ans++;
        p = wall[i].first + d - 1;
    }

    cout << ans << endl;
}