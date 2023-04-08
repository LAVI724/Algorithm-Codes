#include<bits/stdc++.h>
using namespace std;
// 2022.11.09 P15

/*
綜觀程式競賽 阿和

解題觀念:
選擇該如何放入
排序後放入
1. 依照右邊大小排序 則由左邊依序取
2. 依照左邊大小排序 則由右邊依序取 
*/

int n;
const int maxn = 5000+5;

struct Edge{
    int lef;
    int rig;
    int pos = 0;
    int idx;

    bool operator < (const Edge &rhs) const{
        if(rig != rhs.rig){
            return rig < rhs.rig;
        }
        else{
            return lef < rhs.lef; 
        }
        // return rig < rhs.rig;
        // if(lef != rhs.lef){
        //     return lef < rhs.lef;
        // }
        // else{
        //     return rig < rhs.rig;
        // }
    }
}x[maxn], y[maxn];
bool used[maxn];

bool solve_x(){
    memset(used, false, sizeof(used));
    for(int i = 0; i < n; ++i){
        x[i].pos = 0;
        
        for(int j = x[i].lef; j <= x[i].rig; ++j){
            if(!used[j]){
                x[i].pos = j;
                used[j] = true;
                break;
            }
        }

        if(x[i].pos == 0) return false;
    }
    return true;
}

bool solve_y(){
    memset(used, false, sizeof(used));
    for(int i = 0; i < n; ++i){
        y[i].pos = 0;
        
        for(int j = y[i].lef; j <= y[i].rig; ++j){
            if(!used[j]){
                y[i].pos = j;
                used[j] = true;
                break;
            }
        }

        if(y[i].pos == 0) return false;
    }
    return true;
}

int main(){
    while(cin >> n && n){
        int x1, y1, x2, y2;
        for(int i = 0; i < n; ++i){
            cin >> x1 >> y1 >> x2 >> y2;

            x[i].lef = min(x1, x2);
            x[i].rig = max(x1, x2);
            y[i].lef = min(y1, y2);
            y[i].rig = max(y2, y2);
            x[i].idx = y[i].idx = i;
            x[i].pos = y[i].pos = 0;
        }   
        sort(x, x + n);
        sort(y, y + n);

        // for(int i = 0; i < n; ++i){
        //     cout << x[i].lef << " " << x[i].rig << " " << x[i].pos << " " << x[i].idx << endl;
        // }

        if(!solve_x() || !solve_y()) cout << "IMPOSSIBLE" << endl;
        else{
            int ans_x[maxn], ans_y[maxn];
            for(int i = 0; i < n; ++i){
                ans_x[x[i].idx] = x[i].pos;
                ans_y[y[i].idx] = y[i].pos; 
            }

            for(int i = 0; i < n; ++i){
                cout << ans_x[i] << " " << ans_y[i] << endl;
            }
        }

    }
}