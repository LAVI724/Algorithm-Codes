#include<bits/stdc++.h>
using namespace std;
// 2022.03.21

struct Edge{
    int s;
    int e;

    bool operator < (const Edge &rhs) const{
        return e < rhs.e;
    }

}edge[20+5];

int main(){
    int n;
    cin >> n;

    int j;
    int x, y;
    for(int i = 0; i < n; i++){
        for(j = 0; ; j++){
            cin >> x >> y;
            
            if(x == 0 && y == 0){
                break;
            }

            edge[j].s = x;
            edge[j].e = y;
        }

        sort(edge, edge + j);

        int len = 0;
        int meet = 0;
        for(int i = 0; i < j; i++){
            if(len <= edge[i].s){
                meet++;
                len = edge[i].e;
            }
        }

        cout << meet << endl;
    }
}