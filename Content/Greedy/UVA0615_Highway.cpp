#include<bits/stdc++.h>
using namespace std;
// 2023.03.06

const int maxn = 10000+5;

struct Node{
    double x, y;
    double lef, rig;

    bool operator < (const Node &rhs) const{
        if(lef == rhs.lef) return rig > rhs.rig;
        return lef < rhs.lef;
    }
}node[maxn];

int main(){
    int L, D, N;
    while(cin >> L){
        cin >> D >> N;
        for(int i = 0; i < N; ++i){
            cin >> node[i].x >> node[i].y;

            double tmp = sqrt(D*D - node[i].y*node[i].y);

            if(node[i].x - tmp <= 0) node[i].lef = 0;
            else node[i].lef = node[i].x - tmp;

            if(node[i].x + tmp >= L) node[i].rig = L;
            else node[i].rig = node[i].x + tmp;
        }
        sort(node, node + N);

        int cnt = 0;
        double ptrRig = -1;
        for(int i = 0; i < N; ++i){
            if(node[i].lef > ptrRig){
                cnt++;
                ptrRig = node[i].rig;
            }
        }
        cout << cnt << endl;
    }
}