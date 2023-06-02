#include<bits/stdc++.h>
using namespace std;
// 2022.07.15

/*
本題觀念:
Floyd 多源最短路徑
*/

const int maxn = 1000+5;
const int INF = 0x3f3f3f3f;

int m, n;
int G[maxn][maxn];

void init(){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            G[i][j] = INF;
        }
        G[i][i] = 0;
    }
}

void floyd_warshall(){
    for (int k = 0; k < m; k++){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                if(G[i][k] + G[k][j] < G[i][j]){
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
}

int main(){
    int s, t, w;
    cin >> m >> n;

    init();
    
    for(int i = 0; i < n; ++i){
        cin >> s >> t >> w;
        G[s-1][t-1] = w;
        G[t-1][s-1] = w;
    }
    floyd_warshall();

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << G[i][j] << " ";
    //     }
    //     cout << endl;

    // }

    int q;
    int x, y;
    cin >> q;
    for(int i = 0; i < q; ++i){
        cin >> x >> y;
        cout << G[x-1][y-1] << endl;
    }
}