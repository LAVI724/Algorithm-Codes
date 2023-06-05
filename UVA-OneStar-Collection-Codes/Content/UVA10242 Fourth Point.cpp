#include<bits/stdc++.h>
using namespace std;
// 2022/02/09

struct node{
    double x, y;

    // bool operator < (const node &rhs) const{
    //     return x < rhs.x;
    // }

}edge[4];

int main(){

    while(cin >> edge[0].x >> edge[0].y){
        double xtotal = edge[0].x, ytotal = edge[0].y;
        for(int i = 1; i < 4; i++){
            cin >> edge[i].x >> edge[i].y;
            xtotal += edge[i].x;
            ytotal += edge[i].y;
        }

        // 平行四邊形的對角線座標相加，會等於另一條對角線相加
        bool flag = true;
        for(int i = 0; i < 2 && flag; i++){
            for(int j = 2; j < 4; j++){
                if(edge[i].x == edge[j].x && edge[i].y == edge[j].y){
                    cout << fixed << setprecision(3) << xtotal - (3.0 * edge[i].x) << " " << ytotal - (3.0 * edge[i].y) << endl;
                    flag = false;
                    break;
                }
            }
        }
    }
}