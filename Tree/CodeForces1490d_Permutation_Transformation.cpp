#include<bits/stdc++.h>
using namespace std;
// 2022.07.23

/*
解題觀念:
dfs
segement tree 變形
*/

const int maxn = 100+5;
int arr[maxn], dep[maxn];

void dfs(int lef, int rig, int depth){
    if(lef > rig) return;

    int maxi = -1, maxindx;
    for(int i = lef; i <= rig; ++i){
        if(arr[i] > maxi){
            maxi = arr[i];
            maxindx = i;
        }
    }
    dep[maxindx] = depth;
    dfs(lef, maxindx-1, depth+1);
    dfs(maxindx+1, rig, depth+1);
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        dfs(0, n-1, 0);

        for(int i = 0; i < n; ++i){
            cout << dep[i] << " ";
        }
        cout << endl;
    }
}