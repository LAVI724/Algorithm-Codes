#include<bits/stdc++.h>
using namespace std;
// 2022.06.17

/*
解題觀念:
應該是 segment tree
用到 binary search 和 dfs 的觀念

切割:
6 | 13 || 12 | 5 || 3 | 7 || 10 | 11 || 16 | 9 || 8 | 15 || 2 | 1 || 14 | 4
每兩兩比較 大的 return
13 | 12 || 7 | 11 || 16 | 15 || 2 | 14
13 | 11 || 16 | 14
13 | 16
16
*/

int num[65536+5];
int lose;

int dfs(int lef, int rig){

    if(lef + 2 == rig){
        if(num[lef] > num[rig-1]){
            lose = rig-1;
            return lef;
        }
        else{
            lose = lef;
            return rig-1;
        }
    }

    int mid = (lef + rig)/2;
    int p1 = dfs(lef, mid);
    int p2 = dfs(mid, rig);

    if(num[p1] > num[p2]){
        lose = p2;
        return p1;
    }
    else{
        lose = p1;
        return p2;
    }

}

int main(){
    int n;
    cin >> n;
    memset(num, 0, sizeof(num));
    for(int i = 0; i < pow(2, n); i++){
        cin >> num[i];
    }

    dfs(0, pow(2, n));
    cout << lose + 1 << endl;
}