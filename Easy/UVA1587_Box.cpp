#include<bits/stdc++.h>
using namespace std;
// 2023.01.11 阿和 110-1/1027

struct Rectangle{
    int w, h;
    bool operator < (const Rectangle &rhs) const{
        if(w == rhs.w) return h < rhs.h;
        return w < rhs.w;
    }
}rec[6];

int main(){
    int w, h;
    while(cin >> w >> h){
        if(w < h) swap(w, h);
        rec[0].w = w, rec[0].h = h;

        for(int i = 1; i < 6; ++i){
            cin >> rec[i].w >> rec[i].h;
            if(rec[i].w < rec[i].h) swap(rec[i].w, rec[i].h);
        }
        sort(rec, rec + 6);
        
        bool check = false, flag = false;
        for(int i = 0; i < 6; ++i){
            if(i % 2 != 0){
                if(rec[i].w != rec[i-1].w || rec[i].h != rec[i-1].h){
                    flag = true;
                    break;
                }
            }
        }
        if(rec[0].w != rec[4].h || rec[0].h != rec[2].h || rec[2].w != rec[4].w) flag = true;

        if(flag) cout << "IMPOSSIBLE" << endl;
        else cout << "POSSIBLE" << endl;
    }
}
