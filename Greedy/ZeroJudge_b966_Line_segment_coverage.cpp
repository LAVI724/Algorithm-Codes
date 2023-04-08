#include<bits/stdc++.h>
using namespace std;
// 2022.03.21

/*
解題觀念:
線段覆蓋長度
*/

struct Edge{
    int l;
    int r;

    bool operator < (const Edge &rhs) const{
        if(l == rhs.l){
            return r < rhs.r;
        }
        else{
            return l < rhs.l;
        }
    }

}edge[10000+5];

int main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> edge[i].l >> edge[i].r;
        }

        sort(edge, edge + n);

        int len = edge[0].r;
        int ans = edge[0].r - edge[0].l;
        for(int i = 1; i < n; i++){
            if(len > edge[i].l && len < edge[i].r){
                ans = ans + (edge[i].r - len);
                len = edge[i].r;
            }
            else if (edge[i].l >= len){
                ans = ans + (edge[i].r - edge[i].l);
                len = edge[i].r;
            }
        }

        cout << ans << endl;
    }
}