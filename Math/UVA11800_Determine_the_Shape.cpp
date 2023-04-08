#include<bits/stdc++.h>
using namespace std;
// 2022.06.28

/*
解題觀念:
atan (抄了模板)

兩向量垂直: x1x2 + y1y2 = 0
兩向量平行: x1x2 + y1y2 = |v1| |v2|
v1 是向量長度
*/

struct Edge{
    int x, y;
    Edge(int x = 0, int y = 0):x(x), y(y){}

    bool operator < (const Edge &a){
        if (x != a.x)
            return x < a.x;
        return y < a.y;
    }
}edge[4], v[4];

int side[4];

// 正方形判斷點模板
typedef Edge Vector ;

Vector vec(Edge a, Edge b){
    Vector p = {b.x - a.x, b.y - a.y};
    return p;
}

Vector orig;
bool angleCmp(Edge &a, Edge &b){
    Vector n = vec(edge[0], a);
    Vector m = vec(edge[0], b);

    return atan2l(n.y, n.x) < atan2l(m.y, m.x);
}

int crossProd(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

bool parallel(Vector a, Vector b){
    return crossProd(a, b) == 0;
}

int main(){
    int t, ca = 1;
    cin >> t;

    while(t--){
        for(int i = 0; i < 4; i++){
            cin >> edge[i].x >> edge[i].y;
        }
        sort(edge, edge + 4);
        sort(edge + 1, edge + 4, angleCmp);

        memset(side, 0, sizeof(side));
        for(int i = 0; i < 4; i++){
            side[i] = ((edge[(i+1)%4].y - edge[i].y) * (edge[(i+1)%4].y - edge[i].y)) + ((edge[(i+1)%4].x - edge[i].x) * (edge[(i+1)%4].x - edge[i].x));
        }
        
        for(int i = 0; i < 4; i++){
            v[i].x = edge[(i+1)%4].x - edge[i].x;
            v[i].y = edge[(i+1)%4].y - edge[i].y;
        }

        cout << "Case " << ca++ << ": ";
        if(side[0] == side[1] && side[0] == side[2] && side[0] == side[3]){
            if((v[0].x * v[1].x + v[0].y * v[1].y == 0) && (v[2].x * v[3].x + v[2].y * v[3].y == 0)){
                cout << "Square" << endl;
                continue;
            }
            else{
                cout << "Rhombus" << endl;
                continue;
            }
        }

        if(side[0] == side[2] && side[1] == side[3]){
            if((v[0].x * v[1].x + v[0].y * v[1].y == 0) && (v[2].x * v[3].x + v[2].y * v[3].y == 0)){
                cout << "Rectangle" << endl;
                continue;
            }
            else{
                cout << "Parallelogram" << endl;
                continue;
            }
        }

        if(parallel(vec(edge[0], edge[1]), vec(edge[3], edge[2])) || parallel(vec(edge[0], edge[3]), vec(edge[1], edge[2]))){
            cout << "Trapezium" << endl;
            continue;
        }
        else{
            cout << "Ordinary Quadrilateral" << endl;
            continue;
        }
    }
}